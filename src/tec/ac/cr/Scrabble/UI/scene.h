//
// Created by parallels on 4/1/19.
//

#ifndef SCRABBLE_SCENE_H
#define SCRABBLE_SCENE_H


#include <QGraphicsScene>
#include <QPainter>
#include <QApplication>

class Scene : public QGraphicsScene {
Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);
    int getGridSize() const {return this->gridSize;}

protected:
    void drawBackground (QPainter* painter, const QRectF &rect);
private:
    int gridSize;
};


#endif //SCRABBLE_SCENE_H
