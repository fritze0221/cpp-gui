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

signals:

protected:

    void paintEvent(QPaintEvent* event) override;
};

#endif // LEDCONTROL_H
