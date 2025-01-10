#include "traincontrol.h"

Traincontrol::Traincontrol(QWidget *parent)
    : QWidget{parent}
{

    slider = new veloSlider(this,veloSliderColor,5,1,10);
    button = new modButton(this,modButtonColor,1,"Stop");

    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(slider);
    layout->addWidget(button);


    setLayout(layout);

}

void Traincontrol::paintEvent(QPaintEvent* event){

    QColor color(89,89,89);
    QBrush brush(color);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QRect rect = this->rect().adjusted(1, 1, -1, -1); // Anpassung für saubere Kanten
    painter.setBrush(brush); // Beispielhafte Hintergrundfarbe
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect, 15, 15);

}

