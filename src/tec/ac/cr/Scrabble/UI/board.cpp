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

using namespace std;
Board::Board(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);

    Matrix* m = Matrix::getInstance();
    m->addIndex("A", 2, 7);
    m->addIndex("Y", 2, 3);
    m->addIndex("Q", 0, 0);


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

void Board::initializeBoard(){
    QRectF rect(0,0,30,30);
    double xpos = 0.5;
    double ypos = 0;
    int squareCount = -0;

    for(int i = 0; i < 15; i++) {
        for (int i = 0; i < 15; i++) {
            QGraphicsRectItem *item = new QGraphicsRectItem(rect);
            allSquares.append(item);
            squareCount ++;
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
            scene->addItem(dItem);
            dItem->setRect(rect);
            dItem->setPos(xpos,ypos);
            dItem->setAcceptDrops(true);
            xpos += 50;
            assignLetter(dItem, "A");
            dItem->setAnchorPoint(dItem->pos());
        }
        xpos = 600;
        ypos += 50;
    }
}

QString Board::randomLetter() {
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    QString randomString;
    int index = qrand() % possibleCharacters.length();
    QChar nextChar = possibleCharacters.at(index);
    randomString.append(nextChar);
    return randomString;
}

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

void updatePoints(int points) {

}

Board::~Board()
{
    delete ui;
}
