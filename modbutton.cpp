#include "modbutton.h"

modButton::modButton(QWidget *parent, QVector<QRgb> color, QString text)
{
    ButtonColor << color;
    ButtonText = text;

    Fonts customFont;

    button = new QPushButton(this);
    buttonTimer = new QTimer(this);

    r_tmp = (int)qRed(ButtonColor[0]);
    g_tmp = (int)qGreen(ButtonColor[0]);
    b_tmp = (int)qBlue(ButtonColor[0]);

    button->setText(ButtonText);
    button->setStyleSheet(buttonStyle.arg(qRed(ButtonColor[0])).arg(qGreen(ButtonColor[0])).arg(qBlue(ButtonColor[0])).arg(qRed(ButtonColor[1])).arg(qGreen(ButtonColor[1])).arg(qBlue(ButtonColor[1])));
    button->setFont(customFont);

    connect(button, &QPushButton::pressed, this, &modButton::onButtonPressed);
    connect(button, &QPushButton::released, this, &modButton::onButtonReleased);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);
    setLayout(layout);
}

void modButton::onButtonPressed(){

    button->setStyleSheet(buttonStyle.arg(qRed(ButtonColor[2])).arg(qGreen(ButtonColor[2])).arg(qBlue(ButtonColor[2])).arg(qRed(ButtonColor[3])).arg(qGreen(ButtonColor[3])).arg(qBlue(ButtonColor[3])));

}

void modButton::onButtonReleased(){


    button->setStyleSheet(buttonStyle.arg(qRed(ButtonColor[0])).arg(qGreen(ButtonColor[0])).arg(qBlue(ButtonColor[0])).arg(qRed(ButtonColor[0])).arg(qGreen(ButtonColor[0])).arg(qBlue(ButtonColor[0])));
    buttonTimer->stop();

    r_tmp = (int)qRed(ButtonColor[0]);
    g_tmp = (int)qGreen(ButtonColor[0]);
    b_tmp = (int)qBlue(ButtonColor[0]);

    emit modButtonClicked();

}

modButton::~modButton(){


}
