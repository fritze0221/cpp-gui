#include <QPainter>
#include <QSlider>
#include <QStyleOptionSlider>
#include <QWidget>
#include "labeled_slider.h"

LabeledSlider::LabeledSlider(Qt::Orientation orientation, QWidget* parent)
    : QSlider(orientation, parent), currentValue(minimum()) {
  connect(this, &QSlider::valueChanged, this, [this](int value) {
    currentValue = value;  // Aktuellen Wert aktualisieren
    update();              // Neu zeichnen
  });
}

QSize LabeledSlider::sizeHint() const {
  // Erhöhe die empfohlene Größe des Sliders um Platz für den Text
  QSize baseSize = QSlider::sizeHint();
  if (orientation() == Qt::Horizontal)
    return baseSize + QSize(0, 40);  // 40 Pixel extra Höhe
  else
    return baseSize +
           QSize(40, 0);  // 50 Pixel extra Breite für vertikale Slider
}

void LabeledSlider::paintEvent(QPaintEvent* event) {
  QSlider::paintEvent(event);  // Zeichne zuerst den normalen Slider

  QPainter painter(this);
  painter.setPen(Qt::white);
  QFont font = painter.font();
  font.setPointSize(8);
  painter.setFont(font);

  // Slider-Geometrie berechnen
  QStyleOptionSlider opt;
  initStyleOption(&opt);

  QRect sliderRect = style()->subControlRect(QStyle::CC_Slider, &opt,
                                             QStyle::SC_SliderHandle, this);
  int sliderX = sliderRect.center().x();
  int sliderY = sliderRect.top() - 10;  // Position des Texts über dem Knauf

  // Aktuellen Wert über dem Knauf zeichnen
  QString valueText = QString::number(currentValue);
  painter.drawText(sliderX - 15, sliderY - 10, 30, 15, Qt::AlignCenter,
                   valueText);

  // Einteilungen unter dem Slider zeichnen
  int sliderWidth = this->width();
  int sliderHeight = this->height();
  const int offsetY = 20;  // Verschiebung der Zahlen unter den Slider
  int tickCount = (maximum() - minimum()) / tickInterval();

  for (int i = 0; i <= tickCount; ++i) {
    double ratio = static_cast<double>(i) / tickCount;
    int x = 15 + ratio * (sliderWidth - 30);

    int value = minimum() + i * tickInterval();

    // Zentriertes Rechteck um die X-Position erstellen
    QRect textRect(x - 15, sliderHeight - offsetY, 30,
                   15);  // 30 Pixel Breite, zentriert
    painter.drawText(textRect, Qt::AlignCenter, QString::number(value));
  }
}
