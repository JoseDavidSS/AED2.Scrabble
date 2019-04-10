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