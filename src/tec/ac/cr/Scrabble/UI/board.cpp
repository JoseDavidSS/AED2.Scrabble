#include "board.h"
#include "ui_board.h"
#include "../Logic/Data/Holder.h"
#include "../Logic/Lists/Matrix/Matrix.h"
#include "../Logic/Lists/Matrix/List.h"
#include "../Server/ASync.h"
#include "draggablerectitem.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMediaPlaylist>
#include <QStyleOptionGraphicsItem>
#include <QVector>
#include <QDir>
#include <QMovie>
#include <iostream>

using namespace std;
Board::Board(QWidget *parent) :
    // Main setup of board UI elements.
    QMainWindow(parent),
    ui(new Ui::Board) {
    ui->setupUi(this);

    // Width and height of window.
    int width = 800;
    int height = 600;

    // Connects designer UI with programatically added UI elements.
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width, height);
    view = ui->graphicsView;
    view->setScene(scene);
    view->setFixedSize(width, height);
    view->setStyleSheet("background: transparent");
    QMovie* movie = new QMovie("qrc:/fireplace.gif");
    ui->fireplace->setMovie(movie);
    movie->start();
    ui->fireplace->show();
    ui->fireplace->raise();


    // Checks if connection with server is established for offline tests if necessary.
    Holder* holder = Holder::getInstance();
    bool isOnline;
    if (holder->getCodeToEnter() != 0) {
        isOnline = true;
    } else {
        isOnline = false;
    }
    initializeBoard(isOnline);

    // Plays music.
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/noir.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer* background_music = new QMediaPlayer();
    background_music->setMedia(playlist);
    background_music->play();
}

/// Adds letter to matrix in specific id from 0 to 225.
///@param id
///@param letter
void Board::addLetterToMatrix(int id, string letter) {
    Matrix* board = Matrix::getInstance();
    QVector<int>* letterCoords = board->idToCoordinates(id);
    int i = letterCoords->at(0);
    int j = letterCoords->at(1);
    board->addIndex(letter, i, j);
    Matrix::setInstance(board);
}

/// Assigns specific letter to draggable square.
/// @param dItem
/// @param letter
void Board::assignLetter(DraggableRectItem* dItem, QString letter) {
    QString dir = "://letters/" + letter + ".png";
    QPixmap pixmap = QPixmap(dir);
    QPixmap scaled = pixmap.scaled(30,30);
    dItem->setBrush(QBrush(scaled));
}

/// Assigns specific letter to empty non-draggable square.
/// @param item
/// @param letter
void Board::assignLetter(QGraphicsRectItem* item, QString letter) {
    QString dir = "://letters/" + letter + ".png";
    QPixmap pixmap = QPixmap(dir);
    QPixmap scaled = pixmap.scaled(30,30);
    item->setBrush(QBrush(scaled));
}

/// Blocks the ability to place any letter in board.
/// @param state true or false
void Board::blockPlay(bool state) {
    for (int i = 0; i < 225; i ++) {
        allSquares[i]->setAcceptDrops(state);
    }
}

/// Initializes board with all of its starting default attributes with size corrections.
/// @param isOnline boolean value if game is online
void Board::initializeBoard(bool isOnline){
    QRectF rect(0,0,30,30);
    double xpos = 10;
    double ypos = 14;
    double xcorrection = 0;
    double ycorrection = 0.2;
    double xseparation = 38;

    for(int i = 0; i < 15; i++) {
        if (i == 14) {
            xseparation = 38.5;
        }
        for (int i = 0; i < 15; i++) {
            QGraphicsRectItem *item = new QGraphicsRectItem(rect);
            item->setPen(Qt::NoPen);
            allSquares.append(item);
            scene->addItem(item);
            item->setPos(xpos, ypos);
            xpos += xseparation;
        }
        xpos = 10 - xcorrection;
        ypos += 39.7 - ycorrection;
        if (i < 9) {
            ycorrection += 0.2;
        } else {
            xcorrection += 0.8;
            ycorrection -= 1.3;
        }
    }

    xpos = 650;
    ypos = 90;

    for(int i = 0; i < 4; i++) {
        for(int i = 0; i < 2; i++) {
            DraggableRectItem* dItem = new DraggableRectItem();
            allLetters.append(dItem);
            scene->addItem(dItem);
            dItem->setRect(rect);
            dItem->setPos(xpos,ypos);
            dItem->setAcceptDrops(true);
            xpos += 50;
            dItem->setAnchorPoint(dItem->pos());
        }
        xpos = 650;
        ypos += 40;
    }

    Holder* holder = Holder::getInstance();
    LetterList* letters;

    if (isOnline) {
        setRoom(holder->getCodeToEnter());
        letters = holder->letterList;
    } else {
        LetterList* defaultList = new LetterList();
        defaultList->insertNode("A", 1, 0);
        defaultList->insertNode("B", 1, 0);
        defaultList->insertNode("C", 1, 0);
        defaultList->insertNode("D", 1, 0);
        defaultList->insertNode("E", 1, 0);
        defaultList->insertNode("F", 1, 0);
        defaultList->insertNode("G", 1, 0);
        defaultList->insertNode("H", 1, 0);
        letters = defaultList;
        ui->marmota->setText("offline.");
    }
    replaceLetters(letters);
}

void Board::on_nextButton_clicked() {
    writeMatrix();
    Holder* holder = Holder::getInstance();
    Holder::setInstance(ASync::thread());
    holder = Holder::getInstance();
    if (holder->getValidatedPlay() == true) {

    } else {
        resetLetters();
    }
}

void Board::on_resetButton_clicked() {
    resetLetters();
}

/// Replaces draggable letters with new letter list.

void Board::replaceLetters(LetterList* letterList) {
    LetterNode* tmp = letterList->head;
    int i = 0;
    while (tmp != nullptr) {
        QString letterToAssign = QString::fromStdString(tmp->getLetter());
        DraggableRectItem* currentLetter = allLetters[i];
        currentLetter->letter = letterToAssign;
        assignLetter(currentLetter, letterToAssign);
        tmp = tmp->next;
        i++;
    }
}

/// Sends letters to their original anchor points if play is not valid.
void Board::resetLetters() {
    for (int i = 0; i < 8; i++) {
        DraggableRectItem* currentLetter = allLetters[i];
        currentLetter->setPos(currentLetter->anchorPoint);
    }
}

/// Modifies room number label in GUI.
/// @param number
void Board::setRoom(int number) {
    ui->roomLabel->setText("Código de sala: " + QString::number(number));
}

/// Updates Matrix Singleton, current board in play, with new data. Blocks squares with letters on them.
/// @param board
void Board::updateBoard(Matrix* board) {
    List* currentList = board->head;
    Node* tmp = board->head->getHead();
    while (currentList != nullptr) {
            while (tmp != nullptr) {
                if (tmp->getLetter() != "") {
                    int pos = tmp->getID() - 1;
                    QString letter = QString::fromStdString(tmp->getLetter());
                    QGraphicsRectItem* square = allSquares[pos];
                    square->setAcceptDrops(true);
                    square->setEnabled(false);
                    assignLetter(square, letter);
                }
                tmp = tmp->next;
            }
            currentList = currentList->next;
            if (currentList != nullptr) {
                tmp = currentList->getHead();
            }
        }
}

/// Modifies points label in GUI.
/// @param points
void Board::updatePoints(int points) {
    ui->pointsLabel->setText("Puntos: " + QString::number(points));
}

/// Takes placed letters in GUI and writes contents to Matrix Singleton.
void Board::writeMatrix() {
    for (int i = 0; i < 8; i++) {
        DraggableRectItem* currentLetter = allLetters[i];
        QPointF letterPos = currentLetter->pos();
        for (int j = 0; j < 225; j++) {
            QGraphicsRectItem* item = allSquares[j];
            QPointF itemPos = item->pos();
            if (itemPos == letterPos) {
                QString toAssign = currentLetter->letter;
                string convertedLetter = toAssign.toStdString();
                addLetterToMatrix(j + 1, convertedLetter);
            }
        }
    }
    resetLetters();
}

Board::~Board()
{
    delete ui;
}
