#include "traincontrol.h"

Traincontrol::Traincontrol(QWidget *parent)
    : QWidget{parent}
{

    wVeloSlider = new veloSlider(this,veloSliderColor,5,1,50,"Speed");
    wAccSlider = new accSlider(this,accSliderColor,10,1,1,2,"Acc");

    wStopButton = new modButton(this,stopButtonColor,"Stop",0);
    //wApplyButton = new modButton(this, applyButtonColor,1, "Apply");

    wInfoLabel = new infoLabel(this, infoLabelColor, "0");

    connect(wAccSlider,&accSlider::sendTime, wVeloSlider, &veloSlider::onTimeValue);
    connect(wStopButton,&modButton::sendButtonClicked, wVeloSlider, &veloSlider::onStopButton);


    QHBoxLayout* velolayout = new QHBoxLayout();

    velolayout->addWidget(wAccSlider);
    velolayout->addWidget(wVeloSlider);
    //velolayout->addWidget(wInfoLabel);

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

