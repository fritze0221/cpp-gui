#ifndef TRAINCONTROL_H
#define TRAINCONTROL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPaintEvent>
#include <QPainterPath>
#include <QVector>

#include "modbutton.h"
#include "traincontrol/veloslider.h"
#include "traincontrol/accslider.h"
#include "traincontrol/infolabel.h"

class Traincontrol : public QWidget
{
    Q_OBJECT
public:
    explicit Traincontrol(QWidget *parent);

    veloSlider* wVeloSlider;
    accSlider* wAccSlider;
    infoLabel* wInfoLabel;

    modButton* wStopButton;
    modButton* wApplyButton;

    QVector<QRgb> veloSliderColor = {
        qRgb(110, 144, 212),
        qRgb(255, 255, 255),
        qRgb(110, 144, 212),
        qRgb(57, 61, 48)
    };

    QVector<QRgb> accSliderColor = {
        qRgb(173, 101, 114)
    };

    QVector<QRgb> stopButtonColor = {
        qRgb(242, 46, 46),
        qRgb(240, 91, 91),
        qRgb(173, 26, 26),
        qRgb(186, 74, 74),
    };

    QVector<QRgb> applyButtonColor = {
        qRgb(108, 140, 140),
        qRgb(201, 4, 40)
    };

    QVector<QRgb> infoLabelColor = {
      qRgb(255,255,255)
    };


signals:

protected:

    void paintEvent(QPaintEvent *event) override;

};

#endif // TRAINCONTROL_H
