#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include <QGraphicsView>
#include "scene.h"
#include "customrectitem.h"
#include "draggablerectitem.h"
#include "../Logic/Lists/Matrix/Matrix.h"

namespace Ui {
class Board;
}

class Board : public QMainWindow
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    void assignLetter(DraggableRectItem* dItem, QString letter);
    void assignLetter(QGraphicsRectItem* dItem, QString letter);
    void initializeBoard();
    QString randomLetter();
    void updateBoard(Matrix* board);
    void updatePoints(int points);

private:
    Ui::Board *ui;
    QGraphicsView* view;
    QGraphicsScene* scene;
    QVector<QGraphicsRectItem*> allSquares;
};

#endif // BOARD_H
