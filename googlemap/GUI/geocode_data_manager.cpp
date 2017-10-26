#include "geocode_data_manager.h"
//#include "qstring.h"
#include <QJsonParseError>
#include <QEventLoop>
#include <QVariantMap>

geocode_data_manager::geocode_data_manager(QObject *parent) :
    QObject(parent)
{

}

//
void geocode_data_manager::get_location_gps(QString object)
{


}

void  geocode_data_manager::get_location_corrdinate(QString object,double& east , double& north)
{
   //https://maps.googleapis.com/maps/api/geocode/json?address=nctu,+TW&key=AIzaSyADViN2MPMwHpiKa4E6KnXiNfQH-KoGwAk"
   QString trans_url = QString(GEO_API_url+"address="+object+"&key="+API_KEY);

   QNetworkRequest request;
   request.setUrl(QUrl(trans_url));
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
   //qDebug()<<json_d.toJson().toStdString().data();
   QVariantMap mainMap= json_obj.toVariantMap();
   QVariantList results = mainMap["results"].toList();
     east  = results[0].toMap()["geometry"].toMap()["location"].toMap()["lng"].toFloat();
     north = results[0].toMap()["geometry"].toMap()["location"].toMap()["lat"].toFloat();
//   printf("lng : %f\n",results[0].toMap()["geometry"].toMap()["location"].toMap()["lng"].toFloat());
//   printf("lat : %f\n",results[0].toMap()["geometry"].toMap()["location"].toMap()["lat"].toFloat());

   pReplay->deleteLater();
   pReplay = nullptr;
   bytes.clear();
}

float geocode_data_manager::get_location_alttitude(float lng,float lat)
{
  float altitude=0.0;
  QString trans_url = QString(ELE_API_url+"locations=%1,%2&key="+API_KEY).arg(lng).arg(lat);

  QNetworkRequest request;
  request.setUrl(QUrl(trans_url));
  QNetworkAccessManager *manager = new QNetworkAccessManager(this);
  QNetworkReply *pReplay = manager->get(request);
  QEventLoop eventLoop;
  QObject::connect(manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
  eventLoop.exec();

  QByteArray bytes = pReplay->readAll();
  QString json = QString::fromUtf8(bytes);

  QJsonDocument json_d=QJsonDocument::fromJson(json.toUtf8());
  QJsonObject json_obj=json_d.object();
  //qDebug()<<json_d.toJson().toStdString().data();
  QVariantMap mainMap= json_obj.toVariantMap();
  QVariantList results = mainMap["results"].toList();
  altitude = results[0].toMap()["elevation"].toFloat();


  pReplay->deleteLater();
  pReplay = nullptr;
  bytes.clear();

  return altitude;
}


void geocode_data_manager::NetworkCleanup()
{
//    mNetReply->deleteLater();
//    mNetReply = nullptr;
//    mDataBuffer->clear();
}

void geocode_data_manager::geocode_printf()
{
    printf("geocode_data_manager\n");
}


