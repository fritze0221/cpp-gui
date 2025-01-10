#include "traincontrol.h"

Traincontrol::Traincontrol(QWidget *parent)
    : QWidget{parent}
{

    wVeloSlider = new veloSlider(this,veloSliderColor,5,1,10);
    wStopButton = new modButton(this,modButtonColor,1,"Stop");
    wTimeSlider = new timeSlider(this,timeSliderColor,5,1);
    wTimeLabel = new timeLabel(this,"Test");

    connect(wStopButton, &modButton::modButtonClicked, wVeloSlider, &veloSlider::onStopButton);
    connect(wTimeSlider, &timeSlider::sendTime, wVeloSlider, &veloSlider::onTimeValue);

    QHBoxLayout* velolayout = new QHBoxLayout();

    velolayout->addWidget(wTimeSlider);
    velolayout->addWidget(wVeloSlider);

    QVBoxLayout* timelayout = new QVBoxLayout();

    timelayout->addWidget(wStopButton);

    QVBoxLayout* layout = new QVBoxLayout();

    layout->addLayout(velolayout);
    layout->addLayout(timelayout);

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

