#ifndef TIMELABEL_H
#define TIMELABEL_H

#include <QWidget>
#include <QLabel>
#include <QLayout>

#include "fonts.h"

class timeLabel : public QWidget
{
    Q_OBJECT
public:
    explicit timeLabel(QWidget *parent,QString text);

    QLabel* label;

private:

    QString labelText;

signals:
};

#endif // TIMELABEL_H
