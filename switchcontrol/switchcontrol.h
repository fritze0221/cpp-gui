#ifndef SWITCHCONTROL_H
#define SWITCHCONTROL_H

#include <QWidget>
#include <QPainter>
#include <QLayout>
#include <QVector>

#include "modbutton.h"

class Switchcontrol : public QWidget
{
    Q_OBJECT
public:
    explicit Switchcontrol(QWidget *parent);

    modButton* wInnerButton;
    modButton* wOuterButton;

private:

    QVector<QRgb> innerButtonColor = {

        qRgb(31,131,13),
        qRgb(12,12,43),
        qRgb(123,112,32),
        qRgb(123,57,23)

    };

    QVector<QRgb> outerButtonColor = {

        qRgb(31,131,13),
        qRgb(12,12,43),
        qRgb(123,112,32),
        qRgb(123,34,32)

};

signals:

protected:

    void paintEvent(QPaintEvent* event) override;
};

#endif // SWITCHCONTROL_H
