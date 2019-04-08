#ifndef MARMOTA_H
#define MARMOTA_H

#include <QMainWindow>

namespace Ui {
class marmota;
}

class marmota : public QMainWindow
{
    Q_OBJECT

public:
    explicit marmota(QWidget *parent = nullptr);
    ~marmota();

private:
    Ui::marmota *ui;
};

#endif // MARMOTA_H
