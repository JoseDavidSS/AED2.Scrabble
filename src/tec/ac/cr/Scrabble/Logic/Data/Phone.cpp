//
// Created by parallels on 4/8/19.
//

#include "Phone.h"
#include <iostream>

void Phone::authenticate(QNetworkReply *, QAuthenticator *auth) {
    auth->setUser(sid);
    auth->setPassword(token);
}

void Phone::hasReplied(QNetworkReply *reply) {
    qDebug() << reply->readAll();
    qDebug() << reply->size();
}

void Phone::sendSMS(QString message) {
    // Access Twilio REST API.
    QNetworkAccessManager *networkManager = new QNetworkAccessManager();
    QString RESTpath = "https://api.twilio.com/2010-04-01/Accounts/" + sid + "/Messages.json";
    QUrl RESTurl(RESTpath);
    QNetworkRequest networkRequest(RESTurl);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Set sender, target, and message w/ defaults.
    QUrlQuery toSend(RESTurl);
    toSend.addQueryItem("To", expert);
    toSend.addQueryItem("From", scrabble);
    toSend.addQueryItem("Body", message);
    RESTurl.setQuery(toSend);


    QObject::connect(networkManager, SIGNAL(finished(QNetworkReply *)),
                     this, SLOT(hasReplied(QNetworkReply*)));
    QObject::connect(networkManager, SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),
                     this, SLOT(authenticate(QNetworkReply*,QAuthenticator*)));

    // Posts request on web.
    networkManager->post(networkRequest, toSend.query(QUrl::FullyEncoded).toUtf8());
}

QString Phone::getSMS() {
    QNetworkAccessManager *networkManager = new QNetworkAccessManager();

    // Gets messages from gringo to Scrabble app.
    QString RESTpath = "https://api.twilio.com/2010-04-01/Accounts/" + sid + "/Messages.json?From="+ gringo +"&To=" + scrabble;
    QUrl RESTurl(RESTpath);
    QNetworkRequest networkRequest(RESTurl);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    //QObject::connect(networkManager, SIGNAL(finished(QNetworkReply *)),
                     //this, SLOT(hasReplied(QNetworkReply*)));
    QNetworkReply* reply = networkManager->get(networkRequest);
    QObject::connect(reply, &QNetworkReply::finished, [reply]() {
        // read data
        QString ReplyText = reply->readAll();
        //qDebug() << ReplyText;
        // ask doc to parse it
        QJsonDocument doc = QJsonDocument::fromJson(ReplyText.toUtf8());
        // we know first element in file is object, to try to ask for such
        QJsonObject obj = doc.object();
        // ask object for value
        QJsonValue value = obj.value(QString("Body"));
        //qDebug() << "Bid value is" << value.toString();;
        reply->deleteLater(); // make sure to clean up
    });

    QObject::connect(networkManager, SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),
                     this, SLOT(authenticate(QNetworkReply*,QAuthenticator*)));


    return "hello";
}