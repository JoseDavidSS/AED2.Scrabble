#include "board.h"
#include "ui_board.h"
#include "../Logic/Data/Holder.h"
#include "../Logic/Lists/Matrix/Matrix.h"
#include "../Logic/Lists/Matrix/List.h"
#include "../Server/ASync.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "draggablerectitem.h"
#include <QStyleOptionGraphicsItem>
#include <QVector>
#include <iostream>

using namespace std;
Board::Board(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Board) {

    ui->setupUi(this);

    int width = 800;
    int height = 600;

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width, height);
    view = ui->graphicsView;
    view->setScene(scene);
    view->setFixedSize(width, height);
    view->setStyleSheet("background: transparent");

    initializeBoard();
}

/**
* Adds letter to matrix in specific id from 0 to 225.
* @param int id
* @param string letter
*/
void Board::addLetterToMatrix(int id, string letter) {
    Matrix* board = Matrix::getInstance();
    QVector<int>* letterCoords = board->idToCoordinates(id);
    int i = letterCoords->at(0);
    int j = letterCoords->at(1);
    board->addIndex(letter, i, j);
    Matrix::setInstance(board);
    cout << letterCoords->at(0) << endl;
    cout << letterCoords->at(1) << endl;
    cout << letter << endl;
}

/**
* Assigns specific letter to draggable square.
* @param DraggableRectItem dItem
* @param QString letter
*/
void Board::assignLetter(DraggableRectItem* dItem, QString letter) {
    QString dir = "://letters/" + letter + ".png";
    QPixmap pixmap = QPixmap(dir);
    QPixmap scaled = pixmap.scaled(30,30);
    dItem->setBrush(QBrush(scaled));
}

void Board::assignLetter(QGraphicsRectItem* dItem, QString letter) {
    QString dir = "://letters/" + letter + ".png";
    QPixmap pixmap = QPixmap(dir);
    QPixmap scaled = pixmap.scaled(30,30);
    dItem->setBrush(QBrush(scaled));
}

/**
* Blocks the ability to place letter in board.
* @param bool state
*/
void Board::blockPlay(bool state) {
    for (int i = 0; i < 225; i ++) {
        allSquares[i]->setAcceptDrops(state);
    }
}
/**
* Initializes board with all of its starting default attributes.
*/
void Board::initializeBoard(){
    QRectF rect(0,0,30,30);
    double xpos = 0.5;
    double ypos = 0;

    Holder* holder = Holder::getInstance();
    setRoom(holder->getCodeToEnter());


    for(int i = 0; i < 15; i++) {
        for (int i = 0; i < 15; i++) {
            QGraphicsRectItem *item = new QGraphicsRectItem(rect);
            allSquares.append(item);
            scene->addItem(item);
            item->setPos(xpos, ypos);
            xpos += 39;
        }
        xpos = 0;
        ypos += 39.7;
    }

    xpos = 600;
    ypos = 100;

    for(int i = 0; i < 2; i++) {
        for(int i = 0; i < 4; i++) {
            DraggableRectItem* dItem = new DraggableRectItem();
            allLetters.append(dItem);
            scene->addItem(dItem);
            dItem->setRect(rect);
            dItem->setPos(xpos,ypos);
            dItem->setAcceptDrops(true);
            xpos += 50;
            dItem->setAnchorPoint(dItem->pos());
        }
        xpos = 600;
        ypos += 50;
    }
    LetterList* letters = holder->letterList;
    replaceLetters(letters);
}

void Board::on_nextButton_clicked() {
    writeMatrix();
    Holder* holder = Holder::getInstance();
    ASync* async = new ASync();
    Holder::setInstance(async->thread());
    holder = Holder::getInstance();
    if (holder->getValidatedPlay() == true) {

    } else {
        //resetLetters();
    }
}

/**
* Replaces draggable letters with new letter list.
* @param
*/
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

/**
* Sends letters to their original anchor points if play is not valid.
*/
void Board::resetLetters() {
    for (int i = 0; i < 8; i++) {
        DraggableRectItem* currentLetter = allLetters[i];
        currentLetter->setPos(currentLetter->anchorPoint);
    }
}

/**
* Modifies room number label in GUI.
* @param int number
*/
void Board::setRoom(int number) {
    ui->roomLabel->setText("Room: " + QString::number(number));
}

/**
* Updates Matrix Singleton, current board in play, with new data. Blocks squares with letters on them.
*/
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

/**
* Modifies points label in GUI.
* @param int points
*/
void Board::updatePoints(int points) {
    ui->pointsLabel->setText("Points: " + QString::number(points));
}

/**
* Takes placed letters in GUI and writes contents to Matrix Singleton.
*/
void Board::writeMatrix() {
    cout << "method activted" << endl;
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
