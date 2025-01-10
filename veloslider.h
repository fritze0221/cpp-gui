#ifndef VELOSLIDER_H
#define VELOSLIDER_H

#include <QObject>
#include <QWidget>
#include <QStyleOptionSlider>
#include <QFontDatabase>
#include <QSizePolicy>
#include <QGridLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QStyle>
#include <QLayout>
#include <QTimer>
#include <QVector>

#include "fonts.h"

class veloSlider : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief Initialisiert den benutzerdefinierten Slider mit Farbschema, Bereich und Intervall.
     *
     * Diese Methode wird verwendet, um den Slider mit spezifischen Farben, einem Bereich für die
     * Minimal- und Maximalwerte sowie einem Intervall für die Tick-Anzeige zu initialisieren.
     *
     * @param parent Ein Zeiger auf das übergeordnete Widget.
     * @param color  Ein QVector mit QRgb-Werten, die die Farben des Sliders definieren.
     *               - `color[0]`: Farbe für den Neutralwert.
     *               - `color[1]`: Farbe für positive Werte.
     *               - `color[2]`: Farbe für negative Werte.
     *               - `color[3]`: Farbe für Reckteck.
     * @param range  Der maximale absolute Bereich des Sliders (z. B. `-range` bis `+range`).
     * @param intervall Das Intervall zwischen den Ticks (Schritte auf dem Slider).
     * @param scale für die Schrittweite der Rampe.
     */

    explicit veloSlider(QWidget *parent, QVector<QRgb> color, int range, int intervall, int scale);

    QSlider* slider;

    int ramp_time = 3000;

private:

    int range;

    QTimer* rampTimer;

    int ramp_time_delta;

    int max_pos = 0;
    int min_pos = 0;
    int zero_off = 0;
    int ramp_off = 0;
    int man_off = 10;

    int ramp_slider_value = 0;
    int scale_factor = 25;

    const int rect_width = 9;
    const int rect_height = 45;

    const int min_width = 350;
    const int min_height = 100;

    QVector<QRgb> sliderColor;

    QString sliderStyle = R"(
        QSlider::groove:horizontal {
        height: 6px;
        background: transparent;
        margin: 8px;
        border: 1px solid #c17d08;
        border-radius: 12px;
        }

        QSlider::sub-page:horizontal {
        background: rgb(%1,%2,%3);
        height: 6px;
        border-radius: 12px;
        }

        QSlider::add-page:horizontal {
        background: rgb(232, 218, 218);
        height: 10px;
        border-radius: 12px;
        }

        QSlider::handle:horizontal {
        background: transparent;
        margin: -10px;
        border: 1px solid transparent;
        border-radius: 5px;
        }
    )";

signals:

    void sendRampPaintEvent();
    void sendScalePaintEvent();

public slots:

    void onStopButton();
    void onTimeValue(int time);

private slots:

    void onValueChanged();
    void onTimer();

    void onScalePaintEvent();
    void onRampPaintEvent();

protected:

    void paintEvent(QPaintEvent* event) override;

};

#endif // VELOSLIDER_H

