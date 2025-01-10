#include "timeslider.h"

timeSlider::timeSlider(QWidget *parent, QVector<QRgb> color, int range, int intervall)
    :range(range), intervall(intervall)
{

    sliderColor << color;

    slider = new QSlider(Qt::Vertical);

    QSizePolicy policy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    slider->setSizePolicy(policy);
    slider->setMinimum(0);
    slider->setMaximum(range);
    slider->setTickInterval(intervall);
    slider->setStyleSheet(sliderStyle.arg(qRed(sliderColor[0])).arg(qGreen(sliderColor[0])).arg(qBlue(sliderColor[0])));

    slider->setMinimumSize(min_width,min_height);

    connect(slider, &QSlider::valueChanged, this, &timeSlider::onValueChanged);

    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(slider);
    setLayout(layout);

}

void timeSlider::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    Fonts customfont;
    painter.setFont(customfont);
    painter.setPen(Qt::white);

    int sliderMin = slider->minimum();
    int sliderMax = slider->maximum();
    int tickInterval = slider->tickInterval();
    int numTicks = (sliderMax - sliderMin) / tickInterval;

    QStyleOptionSlider opt;
    opt.initFrom(slider);
    opt.rect = slider->geometry();
    opt.minimum = slider->minimum();
    opt.maximum = slider->maximum();
    opt.tickPosition = slider->tickPosition();
    opt.tickInterval = slider->tickInterval();
    opt.orientation = slider->orientation();

    opt.upsideDown = (slider->orientation() == Qt::Horizontal) ?
                         (slider->invertedAppearance() != (slider->layoutDirection() == Qt::RightToLeft)) :
                         (!slider->invertedAppearance());

    QRect sliderRect = slider->style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, slider);

    int sliderHeight = sliderRect.height();
    int availableHeight = slider->height() - sliderHeight;

    QFontMetrics fm = painter.fontMetrics();
    int fontWidth = fm.horizontalAdvance("0"); // Breite eines Zeichens (z. B. "0")

    for (int i = 0; i <= numTicks; ++i) {
        int value = sliderMax - i * tickInterval; // Werte umkehren: Maximalwert oben
        double ratio = static_cast<double>(i) / numTicks; // Verhältnis bleibt gleich

        // Berechnung der Y-Position: Invertiert (Max oben, Min unten)
        int y = slider->y() + sliderHeight / 2 + static_cast<int>(ratio * availableHeight);
        int x = slider->x() - fontWidth - man_off;

        // Text zeichnen
        painter.drawText(QPoint(x, y + fm.height() / 2), QString::number(value));


    }

}

void timeSlider::onValueChanged(){

    emit sendTime((int)slider->value()*1000);

}

