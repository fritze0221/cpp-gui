#include "modlayout.h"

modLayout::modLayout(QWidget *parent)
    : QLayout(parent) {}


void modLayout::addItem(QLayoutItem *item) {
    items.append(item);
}

QSize modLayout::sizeHint() const {
    QSize size;
    for (const QLayoutItem *item : items)
        size = size.expandedTo(item->sizeHint());
    return size;
}

QSize modLayout::minimumSize() const {
    QSize size;
    for (const QLayoutItem *item : items)
        size = size.expandedTo(item->minimumSize());
    return size;
}

int modLayout::count() const {
    return items.size();
}

QLayoutItem* modLayout::itemAt(int index) const {
    return items.value(index);
}

QLayoutItem* modLayout::takeAt(int index) {
    if (index >= 0 && index < items.size())
        return items.takeAt(index);
    return nullptr;
}

void modLayout::setGeometry(const QRect &rect) {
    QLayout::setGeometry(rect);

    QRect test = rect.adjusted(0, -100, 0, 100); // Erstellt ein vergrößertes Rechteck

    for (QLayoutItem *item : items){

        item->setGeometry(test);
    }
}
