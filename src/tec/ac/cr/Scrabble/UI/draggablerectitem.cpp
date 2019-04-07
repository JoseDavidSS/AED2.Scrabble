//
// Created by parallels on 4/1/19.
//

#include "draggablerectitem.h"
#include <iostream>

DraggableRectItem::DraggableRectItem(QGraphicsRectItem* parent):
        QGraphicsRectItem(parent), m_dragged(false) {
    setFlags(QGraphicsRectItem::ItemIsSelectable|
             QGraphicsRectItem::ItemIsMovable);
    clack->setMedia(QUrl("qrc:/clack.mp3"));
    click->setMedia(QUrl("qrc:/click.mp3"));
}

void DraggableRectItem::setAnchorPoint(const QPointF &anchorPoint) {
    this->anchorPoint = anchorPoint;
}

void DraggableRectItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    m_dragged = true;
    QGraphicsRectItem::mouseMoveEvent(event);
}

int DraggableRectItem::randInt(int low, int high) {
    return qrand() % ((high + 1) - low) + low;
}

void DraggableRectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    int sound = randInt(0, 1);
    if (sound == 0) {
        click->play();
    } else {
        clack->play();
    }
    if(m_dragged){
        QList<QGraphicsItem*> colItems = collidingItems();
        if(colItems.isEmpty())
            this->setPos(anchorPoint);
        else {
            QGraphicsItem* closestItem = colItems.at(0);
            qreal shortestDist = 100000;
                    foreach(QGraphicsItem* item, colItems){
                    QLineF line(item->sceneBoundingRect().center(),
                                this->sceneBoundingRect().center());
                    if(line.length() < shortestDist){
                        shortestDist = line.length();
                        closestItem = item;
                    }
                }
            if (closestItem->acceptDrops() == false) {
                this->setPos(closestItem->scenePos());
            } else {
                this->setPos(anchorPoint);
            }
        }
        m_dragged = false;
    }
    QGraphicsRectItem::mouseReleaseEvent(event);
}
