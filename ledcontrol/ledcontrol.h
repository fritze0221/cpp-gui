#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <QWidget>
#include <QPainter>
#include <QLayout>

#include "ledcontrol/led.h"
#include "modbutton.h"

class Ledcontrol : public QWidget
{
    Q_OBJECT
public:
    explicit Ledcontrol(QWidget *parent);

    ledGrid* wLedGrid;

    modButton* wResetButton;
    modButton* wAllButton;

private:

    QVector<QRgb> ledColor = {
        qRgb(214,51,21),
        qRgb(21,21,54),
        qRgb(55,47,147),
        qRgb(21,21,141)
    };

    QVector<QRgb> resetButtonColor = {
          qRgb(12,23,123),
          qRgb(112,21,21),
          qRgb(112,21,21),
          qRgb(12,23,123)
    };


    QVector<QRgb> allButtonColor = {
        qRgb(12,23,123),
        qRgb(112,21,21),
        qRgb(112,21,21),
        qRgb(12,23,123)
    };


signals:

protected:

    void paintEvent(QPaintEvent* event) override;
};

#endif // LEDCONTROL_H
