#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <board.h> // Include board

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void goToBoard(); // Make a new function to call the window

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    Board     *winBoard; // Make a new declaration for the new window

private slots:
    void on_exitButton_clicked();
    void on_startButton_clicked();
};

#endif // MAINWINDOW_H
