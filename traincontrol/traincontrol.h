#ifndef TRAINCONTROL_H
#define TRAINCONTROL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPaintEvent>
#include <QPainterPath>
#include <QResizeEvent>
#include <QStackedLayout>
#include <QVector>

#include "modbutton.h"
#include "veloslider.h"
#include "timeslider.h"

class Traincontrol : public QWidget
{
    Q_OBJECT
public:
    explicit Traincontrol(QWidget *parent);

    veloSlider* wVeloSlider;
    modButton* wStopButton;
    timeSlider* wTimeSlider;

    QVector<QRgb> veloSliderColor = {
        qRgb(28, 100, 255),
        qRgb(255, 255, 255),
        qRgb(255, 0, 0),
        qRgb(57, 61, 48)
    };

    QVector<QRgb> timeSliderColor = {
        qRgb(173, 101, 114)
    };

    QVector<QRgb> modButtonColor = {
        qRgb(173, 152, 59),
        qRgb(201, 4, 40)
    };


signals:

protected:

    void paintEvent(QPaintEvent *event) override;

};

#endif // TRAINCONTROL_H
