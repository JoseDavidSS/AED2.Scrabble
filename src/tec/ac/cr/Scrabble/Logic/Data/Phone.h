//
// Created by parallels on 4/8/19.
//

#ifndef SCRABBLE_SMS_H
#define SCRABBLE_SMS_H


#include <string>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QAuthenticator>
#include <QUrlQuery>
#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QEventLoop>

using namespace std;

class Phone : public QObject {
    Q_OBJECT

public:
    Phone() = default;
    ~Phone() = default;
    void sendSMS(QString message);
    QString getSMS();

private:
    const QString expert = "%2B50684280167";
    const QString scrabble = "%2B12056357334";
    const QString gringo = "%2B16318328474";
    const QString sid = "ACb3e903228a71b7babed4beec9a56af8d";
    const QString token = "57b4ccb49064d547d61f2be4ecd66ece";

private slots:
    void authenticate(QNetworkReply*, QAuthenticator*);
    void hasReplied(QNetworkReply*);

};


#endif //SCRABBLE_SMS_H
