//
// Created by parallels on 4/1/19.
//

#ifndef SCRABBLE_CUSTOMRECTITEM_H
#define SCRABBLE_CUSTOMRECTITEM_H


#include <QGraphicsRectItem>
#include "scene.h"
#include "math.h"

class CustomRectItem : public QGraphicsRectItem
{
public:
    CustomRectItem(const QRect& rect, QGraphicsItem* parent = 0);
protected:
    QVariant itemChange(GraphicsItemChange change,
                        const QVariant &value);
};


#endif //SCRABBLE_CUSTOMRECTITEM_H
