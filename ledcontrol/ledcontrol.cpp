#include "ledcontrol.h"

Ledcontrol::Ledcontrol(QWidget *parent)
{

    wLed = new LED(this, 8, ledColor);

    setMaximumSize(250,250);

    QHBoxLayout* layout = new QHBoxLayout();

    layout->addWidget(wLed);

    setLayout(layout);

}

void Ledcontrol::paintEvent(QPaintEvent* event){


    QColor color(89,89,89);
    QBrush brush(color);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QRect rect = this->rect().adjusted(1, 1, -1, -1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect, 15, 15);

}
