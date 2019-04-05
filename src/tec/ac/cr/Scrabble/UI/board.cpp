#include "board.h"
#include "ui_board.h"
#include "../Logic/Data/Holder.h"
#include "../Logic/Lists/Matrix/Matrix.h"
#include "../Logic/Lists/Matrix/List.h"

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

    // Test Matrix
    Matrix* m = Matrix::getInstance();
    m->addIndex("A", 2, 7);
    m->addIndex("Y", 2, 3);
    m->addIndex("Q", 1, 3);


    int width = 800;
    int height = 600;

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width, height);
    view = ui->graphicsView;
    view->setScene(scene);
    view->setFixedSize(width, height);
    view->setStyleSheet("background: transparent");

    initializeBoard();
    updateBoard(m);
}

/**
* Adds letter to matrix in specific id from 0 to 225.
* @param int id
* @param string letter
*/
void Board::addLetterToMatrix(int id, string letter) {
    Matrix* board = Matrix::getInstance();
    List* currentList = board->head;
    Node* tmp = board->head->getHead();
    while (currentList != nullptr) {
            while (tmp != nullptr) {
                if (tmp->getID() == id) {
                    tmp->setLetter(letter);
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
    //TEMP
    QVector<QString> LetterList;
    LetterList.append("A");
    LetterList.append("C");
    LetterList.append("F");
    LetterList.append("E");
    LetterList.append("P");
    LetterList.append("O");

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
        for(int i = 0; i < 3; i++) {
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
    replaceLetters(LetterList);
}

void Board::on_nextButton_clicked() {
    //Holder* holder = Holder::getInstance();
    //if (holder->getValidatedPlay() == true) {

    //} else {
        //resetLetters()
        //}
    //}
    writeMatrix();
}

/**
* Replaces draggable letters with new letter list.
* @param
*/
void Board::replaceLetters(QVector<QString> LetterList) {
    for (int i = 0; i < 6; i++) {
        QString letterToAssign = LetterList[i];
        DraggableRectItem* currentLetter = allLetters[i];
        currentLetter->letter = letterToAssign;
        assignLetter(currentLetter, letterToAssign);
    }
}

/**
* Sends letters to their original anchor points if play is not valid.
*/
void Board::resetLetters() {
    for (int i = 0; i < 6; i++) {
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
    for (int i = 0; i < 6; i++) {
        DraggableRectItem* currentLetter = allLetters[i];
        for (int j = 0; j < 225; j++) {
            QGraphicsRectItem* item = allSquares[j];
            QPointF itemPos = item->pos();
            if (itemPos == currentLetter->pos()) {
                QString toAssign = currentLetter->letter;
                string convertedLetter = toAssign.toStdString();
                addLetterToMatrix(j + 1, convertedLetter);
            }
        }
    }
}

Board::~Board()
{
    delete ui;
}
