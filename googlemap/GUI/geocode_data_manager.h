#ifndef GEOCODE_DATA_MANAGER_H
#define GEOCODE_DATA_MANAGER_H
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonArray>
#include <QJsonParseError>
#include<QDebug>

#include "QtNetwork/QNetworkAccessManager"
#include "QtNetwork/QNetworkReply"
#include "QtNetwork/QNetworkRequest"
#include"stdio.h"
#include "QString"
class geocode_data_manager :  public QObject
{
     Q_OBJECT
public:
    geocode_data_manager(QObject *parent=0);


    void get_location_corrdinate(QString object);
    void get_location_gps(QString object);
    float get_location_alttitude(float lng,float lat);
    void geocode_printf();

private slots:


 private:
      QString JS_API_KEY = "AIzaSyA_iIaYqH8KQkC4rVm2IRLAqHiBawE0_Ag";
      QString API_KEY="AIzaSyADViN2MPMwHpiKa4E6KnXiNfQH-KoGwAk";
      QString ELE_API_url="https://maps.googleapis.com/maps/api/elevation/json?";
      QString GEO_API_url="https://maps.googleapis.com/maps/api/geocode/json?";

      void NetworkCleanup();


};

#endif // GEOCODE_DATA_MANAGER_H
