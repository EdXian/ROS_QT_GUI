#include "geocode_data_manager.h"
//#include "qstring.h"
#include <QJsonParseError>
#include <QEventLoop>
geocode_data_manager::geocode_data_manager(QObject *parent) :
    QObject(parent)
{
      QString baseUrl = "https://maps.googleapis.com/maps/api/geocode/json?address=交通大學,+TW&key=AIzaSyADViN2MPMwHpiKa4E6KnXiNfQH-KoGwAk";
      QNetworkRequest request;
      request.setUrl(QUrl(baseUrl));
      QNetworkAccessManager *manager = new QNetworkAccessManager(this);
      QNetworkReply *pReplay = manager->get(request);
      QEventLoop eventLoop;
      QObject::connect(manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
      eventLoop.exec();
      QByteArray bytes = pReplay->readAll();
      QString s = QString::fromUtf8(bytes);

      qDebug() << s;
}

//

void geocode_data_manager::OnDataReadyToRead()
{
    mDataBuffer->append(mNetReply->readAll());
}


void geocode_data_manager::OnListReadFinished()
{


    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer, &error);
    QJsonArray array = doc.array();
   // qDebug() <<"json =" <<array;
    // -- STORE LATEST 10 STORIES ID --
    for(int i = 0; i < 10; ++i)
    {
        printf("%d\n",array[i].toInt());
    }
    NetworkCleanup();
     // mLatestStoriesID[i] = array[i].toInt();
//    // -- CLEAN UP --
//    NetworkCleanup();
}

void geocode_data_manager::NetworkCleanup()
{
    mNetReply->deleteLater();
    mNetReply = nullptr;
    mDataBuffer->clear();
}

//
void geocode_data_manager::geocode_DataReady2Read()
{
    //geocode_json=mNetReply->readAll();

    QJsonParseError jerror;
    QJsonDocument jdoc= QJsonDocument::fromJson(mNetReply->readAll(),&jerror);

    if(jerror.error!= QJsonParseError::NoError){
        printf("error\n");
    }

    qDebug() << "Reply = " << geocode_json;
}

void geocode_data_manager::geocode_printf()
{
    printf("geocode_data_manager\n");
}

/*
 *
 *
void GeocodeDataManager::replyFinished(QNetworkReply* reply)
{
    QString json = reply->readAll();
    qDebug() << "Reply = " << json;
    qDebug() << "URL = " << reply->url();
    QString strUrl = reply->url().toString();

    QJson::Parser parser;

    bool ok;

    // json is a QString containing the data to convert
    //QVariant result = parser.parse (json.toLatin1(), &ok);
    QVariant result = parser.parse (json.toLatin1(), &ok);
    if(!ok)
    {
        emit errorOccured(QString("Cannot convert to QJson object: %1").arg(json));
        return;
    }

    QString code = result.toMap()["status"].toString();
    qDebug() << "Code" << code;
    if(code != "OK")
    {
        emit errorOccured(QString("Code of request is: %1").arg(code));
        return;
    }

    QVariantList results = result.toMap()["results"].toList();
    if(results.count() == 0)
    {
        emit errorOccured(QString("Cannot find any locations"));
        return;
    }

    double east  = results[0].toMap()["geometry"].toMap()["location"].toMap()["lng"].toDouble();
    double north = results[0].toMap()["geometry"].toMap()["location"].toMap()["lat"].toDouble();

    emit coordinatesReady(east, north);

    QString address = results[0].toMap()["formatted_address"].toString();
    emit addressReady(address);
}
 *
 *
 *
 */

