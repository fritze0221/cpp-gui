#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <QWidget>
#include <QPainter>
#include <QLayout>

#include "ledcontrol/led.h"

class Ledcontrol : public QWidget
{
    Q_OBJECT
public:
    explicit Ledcontrol(QWidget *parent);

    LED* wLed;

private:

    QVector<QRgb> ledColor = {
        qRgb(214,51,21),
        qRgb(21,21,54),
        qRgb(55,47,147),
        qRgb(21,21,141)
    };

signals:

protected:

    void paintEvent(QPaintEvent* event) override;
};

#endif // LEDCONTROL_H
