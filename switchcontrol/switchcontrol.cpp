#include "switchcontrol.h"

Switchcontrol::Switchcontrol(QWidget *parent)
{

    wButton = new modButton(this, buttonColor, 1,"Test");

    QHBoxLayout* layout = new QHBoxLayout();

    layout->addWidget(wButton);

    setLayout(layout);

}

void Switchcontrol::paintEvent(QPaintEvent* event){


    QColor color(89,89,89);
    QBrush brush(color);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QRect rect = this->rect().adjusted(1, 1, -1, -1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect, 15, 15);

}
