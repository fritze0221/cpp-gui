#ifndef TURBINCONTROL_H
#define TURBINCONTROL_H

#include <QWidget>
#include <QPainter>
#include <QLayout>

#include "modbutton.h"

class Turbincontrol : public QWidget
{
    Q_OBJECT
public:
    explicit Turbincontrol(QObject *paren);

    modButton* button;

private:

    QVector<QRgb> buttonColor = {
        qRgb(12,23,123),
        qRgb(112,21,21),
        qRgb(112,21,21),
        qRgb(12,23,123)

    };

protected:

    void paintEvent(QPaintEvent* event) override;

signals:
};

#endif // TURBINCONTROL_H
