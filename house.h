#ifndef HOUSE_H
#define HOUSE_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class House : public QWidget{
    Q_OBJECT

public:

    House(QMainWindow* parent, QString string);

private:

    QPushButton* newWindowButton;

signals:

    void requestOpenSubWindow();


};

#endif // HOUSE_H
