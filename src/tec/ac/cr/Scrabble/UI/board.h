#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QLabel>
#include <QMediaPlayer>
#include "scene.h"
#include "customrectitem.h"
#include "draggablerectitem.h"
#include "../Logic/Lists/Matrix/Matrix.h"
#include "../Logic/Data/Holder.h"

namespace Ui {
class Board;
}

class Board : public QMainWindow
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    void addLetterToMatrix(int id, string letter);
    void assignLetter(DraggableRectItem* dItem, QString letter);
    void assignLetter(QGraphicsRectItem* dItem, QString letter);
    void blockPlay(bool state);
    void initializeBoard(bool isOnline);
    void replaceLetters(LetterList* letterlist);
    void resetLetters();
    void setRoom(int number);
    void updateBoard(Matrix* board);
    void updatePoints(int points);
    void writeMatrix();

private:
    Ui::Board *ui;
    QGraphicsView* view;
    QGraphicsScene* scene;
    QVector<QGraphicsRectItem*> allSquares;
    QVector<DraggableRectItem*> allLetters;
    QMediaPlayer* music = new QMediaPlayer();

private slots:
    void on_nextButton_clicked();
    void on_resetButton_clicked();

};

#endif // BOARD_H
