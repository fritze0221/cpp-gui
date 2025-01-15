#ifndef SWITCHCONTROL_H
#define SWITCHCONTROL_H

#include <QWidget>
#include <QPainter>
#include <QLayout>
#include <QVector>

#include "modbutton.h"

class Switchcontrol : public QWidget
{
    Q_OBJECT
public:
    explicit Switchcontrol(QWidget *parent);

    modButton* wButton;

private:

    QVector<QRgb> buttonColor = {

        qRgb(31,131,13),
        qRgb(12,12,43),
        qRgb(123,112,32)
    };

signals:

protected:

    void paintEvent(QPaintEvent* event) override;
};

#endif // SWITCHCONTROL_H
