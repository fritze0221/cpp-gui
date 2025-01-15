#include "modbutton.h"

modButton::modButton(QWidget *parent, QVector<QRgb> color, int time, QString text)
    :time(time)
{
    ButtonColor = color;
    ButtonText = text;

    Fonts customFont;

    button = new QPushButton(this);
    buttonTimer = new QTimer(this);

    r_tmp = (int)qRed(ButtonColor[0]);
    g_tmp = (int)qGreen(ButtonColor[0]);
    b_tmp = (int)qBlue(ButtonColor[0]);

    button->setText(ButtonText);
    button->setStyleSheet(buttonStyle.arg(qRed(ButtonColor[0])).arg(qGreen(ButtonColor[0])).arg(qBlue(ButtonColor[0])).arg(qRed(ButtonColor[0])).arg(qGreen(ButtonColor[0])).arg(qBlue(ButtonColor[0])));
    button->setFont(customFont);

    connect(button, &QPushButton::pressed, this, &modButton::onButtonPressed);
    connect(button, &QPushButton::released, this, &modButton::onButtonReleased);
    connect(buttonTimer, &QTimer::timeout, this, &modButton::onTimerOut);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);
    setLayout(layout);
}

void modButton::onButtonPressed(){

    button->setStyleSheet(buttonStyle.arg(qRed(ButtonColor[2])).arg(qGreen(ButtonColor[2])).arg(qBlue(ButtonColor[2])).arg(qRed(ButtonColor[3])).arg(qGreen(ButtonColor[3])).arg(qBlue(ButtonColor[3])));


    // buttonTimer->setInterval(time);
    // buttonTimer->start();

}

void modButton::onButtonReleased(){


    button->setStyleSheet(buttonStyle.arg(qRed(ButtonColor[0])).arg(qGreen(ButtonColor[0])).arg(qBlue(ButtonColor[0])).arg(qRed(ButtonColor[0])).arg(qGreen(ButtonColor[0])).arg(qBlue(ButtonColor[0])));
    buttonTimer->stop();

    r_tmp = (int)qRed(ButtonColor[0]);
    g_tmp = (int)qGreen(ButtonColor[0]);
    b_tmp = (int)qBlue(ButtonColor[0]);

    emit modButtonClicked();

}

void modButton::onTimerOut(){


        // Schrittweise Farbanpassung
    r_tmp = qBound(0, r_tmp + counter(r_tmp, (int)qRed(ButtonColor[2])), 255);
    g_tmp = qBound(0, g_tmp + counter(g_tmp, (int)qGreen(ButtonColor[2])), 255);
    b_tmp = qBound(0, b_tmp + counter(b_tmp, (int)qBlue(ButtonColor[2])), 255);


    // Button-Farbe aktualisieren
    updateButtonColor(r_tmp, g_tmp, b_tmp);

    // Timer erneut starten, falls noch nicht erreicht
    if (r_tmp == (int)qRed(ButtonColor[2]) &&
        g_tmp == (int)qGreen(ButtonColor[2]) &&
        b_tmp == (int)qBlue(ButtonColor[2])) {
        buttonTimer->stop(); // Zielwert erreicht, Timer stoppen
    }

}

void modButton::updateButtonColor(int r, int g, int b) {
    button->setStyleSheet(buttonStyle.arg(r).arg(g).arg(b).arg(qRed(ButtonColor[1])).arg(qGreen(ButtonColor[1])).arg(qBlue(ButtonColor[1])));
}

int modButton::counter(int color1, int color2){

    int ret = 0;

    if(color1 > color2) ret = -1;
    if(color1 < color2) ret = 1;

    return ret;

}

modButton::~modButton(){


}
