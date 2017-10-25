#include "geocode_data_manager.h"
//#include "qstring.h"
#include <QJsonParseError>
#include <QEventLoop>
#include <QVariantMap>

geocode_data_manager::geocode_data_manager(QObject *parent) :
    QObject(parent)
{
      //https://maps.googleapis.com/maps/api/elevation/json?locations=39.7391536,-104.9847034&key=
     // QString baseUrl = "https://maps.googleapis.com/maps/api/geocode/json?address=nctu,+TW&key=AIzaSyADViN2MPMwHpiKa4E6KnXiNfQH-KoGwAk";
      QString baseUrl = "https://maps.googleapis.com/maps/api/elevation/json?locations=24.7859852,120.9999097&key=AIzaSyADViN2MPMwHpiKa4E6KnXiNfQH-KoGwAk";
      QNetworkRequest request;
      request.setUrl(QUrl(baseUrl));
      QNetworkAccessManager *manager = new QNetworkAccessManager(this);
      QNetworkReply *pReplay = manager->get(request);
      QEventLoop eventLoop;
      QObject::connect(manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
      eventLoop.exec();

      QByteArray bytes = pReplay->readAll();
       QString json = QString::fromUtf8(bytes);

      QJsonDocument json_d=QJsonDocument::fromJson(json.toUtf8());
      QJsonObject json_obj=json_d.object();
      //Qstring j_string=json_d.toJson().toStdString();
      qDebug()<<json_d.toJson().toStdString().data();
      QVariantMap mainMap= json_obj.toVariantMap();
      QVariantList results = mainMap["results"].toList();
       double east  = results[0].toMap()["geometry"].toMap()["location"].toMap()["lng"].toFloat();
       double north = results[0].toMap()["geometry"].toMap()["location"].toMap()["lat"].toFloat();
      printf("lng : %f\n",results[0].toMap()["geometry"].toMap()["location"].toMap()["lng"].toFloat());
      printf("lat : %f\n",results[0].toMap()["geometry"].toMap()["location"].toMap()["lat"].toFloat());
}

//
void geocode_data_manager::get_location_gps(QString name)
{

}

float geocode_data_manager::get_location_alttitude(float lng,float lat)
{
  float altitude=0.0;
  QString KEY="AIzaSyADViN2MPMwHpiKa4E6KnXiNfQH-KoGwAk";
  QString base_url="https://maps.googleapis.com/maps/api/geocode/json?";
//  QString trans_url = base_url+"address" +"="
//                              +name     +","+"+" ;

  return altitude;
  //printf("%s",);
}


void geocode_data_manager::OnDataReadyToRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

/*
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
}*/

void geocode_data_manager::NetworkCleanup()
{
    mNetReply->deleteLater();
    mNetReply = nullptr;
    mDataBuffer->clear();
}

//
/*
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
*/
void geocode_data_manager::geocode_printf()
{
    printf("geocode_data_manager\n");
}


