#ifndef MODBUTTON_H
#define MODBUTTON_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QStyleOptionSlider>
#include <QFontDatabase>
#include <QSizePolicy>
#include <QPushButton>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QStyle>


#include "fonts/fonts.h"

class modButton : public QWidget
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
     *               - `color[1]`: Farbe für den Endwert.
     * @param time  Der maximale absolute Bereich des Sliders (z. B. `-range` bis `+range`).
     * @param text Buttontext.
     */


    modButton(QWidget *parent, QVector<QRgb> color, int time, QString text);
    ~modButton();

    QPushButton* button;
    QTimer* buttonTimer;

private:

    int r_tmp = 0;
    int g_tmp = 0;
    int b_tmp = 0;

    void updateButtonColor(int r, int g, int b);

    int counter(int color1,int color2);

    int time = 0;

    QVector<QRgb> ButtonColor;
    QString ButtonText;

    QString buttonStyle = R"(
    QPushButton {
        background-color: rgb(%1,%2,%3); /* Heller Hintergrund für den Button */
        border: 4px solid rgb(%4,%5,%6); /* Auffälliger blauer Rahmen */
        border-radius: 8px; /* Abgerundete Ecken */
        height: 20 px;
    }

    )";




signals:

    void modButtonClicked();

private slots:

    void onButtonReleased();
    void onButtonPressed();
    void onTimerOut();

};

#endif // MODBUTTON_H
