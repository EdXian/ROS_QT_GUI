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


    void geocode_getCoordinates(void);
    void geocode_printf();
    void geocode_DataReady2Read();
    void OnDataReadyToRead();
    void OnListReadFinished();
private slots:
    //void replyFinished(QNetworkReply* reply);

 private:
     void NetworkCleanup();
      QNetworkReply *mNetReply;
      QByteArray *mDataBuffer;
      QNetworkAccessManager* m_pNetworkAccessManager;
      QString  geocode_json;
};

#endif // GEOCODE_DATA_MANAGER_H
