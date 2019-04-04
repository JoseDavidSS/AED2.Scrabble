#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include <QGraphicsView>
#include "scene.h"
#include "customrectitem.h"
#include "draggablerectitem.h"

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
    void initializeBoard();

private:
    Ui::Board *ui;
    QGraphicsView* view;
    QGraphicsScene* scene;
};

#endif // BOARD_H
