#include "turbincontrol.h"

Turbincontrol::Turbincontrol(QObject *parent)
{

    //buttonColor << color;

    button = new modButton(this, buttonColor, "Turbin");

    QHBoxLayout* layout = new QHBoxLayout();

    layout->addWidget(button);

    setLayout(layout);

}


void Turbincontrol::paintEvent(QPaintEvent* event){

    QColor color(89,89,89);
    QBrush brush(color);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QRect rect = this->rect().adjusted(1, 1, -1, -1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect, 15, 15);

}

