#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "simulation.h"

QVector <QPointF> springGenerator(int n);

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = 0);
    parameters p;

protected:
    void paintEvent(QPaintEvent *event);

private:
    void paintVisualisation(QPainter &painter);
};

#endif // PAINTWIDGET_H
