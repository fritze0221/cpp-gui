#include "ledcontrol.h"

Ledcontrol::Ledcontrol(QWidget *parent)
{

    wLedGrid = new ledGrid(this, 8, ledColor);

    wResetButton = new modButton(this, resetButtonColor, "Reset",0,false);
    wAllButton = new modButton(this, allButtonColor, "All", 0,false);

    connect(wResetButton, &modButton::sendButtonClicked, wLedGrid, &ledGrid::onResetButtonClicked);
    connect(wAllButton, &modButton::sendButtonClicked, wLedGrid, &ledGrid::onAllButtonClicked);

    QHBoxLayout* buttonlayout = new QHBoxLayout();

    buttonlayout->addWidget(wAllButton);
    buttonlayout->addWidget(wResetButton);

    QVBoxLayout* layout = new QVBoxLayout();

    layout->addWidget(wLedGrid);
    layout->addLayout(buttonlayout);


    setMaximumSize(250,250);
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
