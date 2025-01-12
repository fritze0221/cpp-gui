#ifndef MODLABEL_H
#define MODLABEL_H

#include <QWidget>
#include <QLabel>
#include <QLayout>

#include "fonts.h"

class modLabel : public QWidget
{
    Q_OBJECT
public:
    explicit modLabel(QWidget *parent, QString text);

    QLabel* label;

private:

    QString labelText;

signals:
};

#endif // MODLABEL_H
