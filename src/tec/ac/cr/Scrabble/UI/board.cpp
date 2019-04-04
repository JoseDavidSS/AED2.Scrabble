#include "board.h"
#include "ui_board.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "draggablerectitem.h"
#include <QStyleOptionGraphicsItem>

Board::Board(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);

    int width = 600;
    int height = 600;

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width, height);
    view = ui->graphicsView;
    view->setScene(scene);
    view->setFixedSize(width, height);

    view->setStyleSheet("background: transparent");

    QRectF rect(0,0,30,30);


    double xpos = 0.5;
    double ypos = 0;

    for(int i = 0; i < 15; i++) {
        for (int i = 0; i < 15; i++) {
            QGraphicsRectItem *item = new QGraphicsRectItem(rect);
            scene->addItem(item);
            item->setPos(xpos, ypos);
            xpos += 39;
        }
        xpos = 0;
        ypos += 39.7;
    }

    DraggableRectItem* dItem = new DraggableRectItem;
    scene->addItem(dItem);
    dItem->setRect(rect);
    dItem->setPos(500,100);
    //dItem->setBrush(QBrush(QColor("#ffa07a")));
    dItem->setAnchorPoint(dItem->pos());

}

Board::~Board()
{
    delete ui;
}
