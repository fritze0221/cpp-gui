#ifndef MODLAYOUT_H
#define MODLAYOUT_H

#include <QLayout>
#include <QWidget>

class modLayout : public QLayout
{
public:

    modLayout(QWidget *parent = nullptr);

    void addItem(QLayoutItem *item) override;

    QSize sizeHint() const override;
    QSize minimumSize() const override;

    int count() const override;

    QLayoutItem* itemAt(int index) const override;
    QLayoutItem* takeAt(int index) override;

private:

    QList<QLayoutItem*> items;

protected:

    void setGeometry(const QRect &rect) override;

};

#endif // MODLAYOUT_H
