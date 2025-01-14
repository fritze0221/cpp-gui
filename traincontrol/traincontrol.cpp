#include "traincontrol.h"

Traincontrol::Traincontrol(QWidget *parent)
    : QWidget{parent}
{

    wVeloSlider = new veloSlider(this,veloSliderColor,5,1,80,"Speed");
    wAccSlider = new accSlider(this,accSliderColor,10,1,1,2,"Acc");

    wStopButton = new modButton(this,stopButtonColor,1,"Stop");
    //wApplyButton = new modButton(this, applyButtonColor,1, "Apply");

    connect(wStopButton, &modButton::modButtonClicked, wVeloSlider, &veloSlider::onStopButton);
    connect(wAccSlider, &accSlider::sendTime, wVeloSlider, &veloSlider::onTimeValue);

    QHBoxLayout* velolayout = new QHBoxLayout();

    velolayout->addWidget(wAccSlider);
    velolayout->addWidget(wVeloSlider);

    QVBoxLayout* buttonlayout = new QVBoxLayout();

    //buttonlayout->addWidget(wApplyButton);
    buttonlayout->addWidget(wStopButton);

    QVBoxLayout* layout = new QVBoxLayout();

    layout->addLayout(velolayout);
    layout->addLayout(buttonlayout);

    setLayout(layout);
}

void Traincontrol::paintEvent(QPaintEvent* event){

    QColor color(89,89,89);
    QBrush brush(color);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QRect rect = this->rect().adjusted(1, 1, -1, -1);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect, 15, 15);

}

