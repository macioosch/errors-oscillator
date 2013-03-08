#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QTimer>
#include "simulation.h"

QVector <QPointF> springGenerator(int n);

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = 0);
    
public slots:
    void resetSimulation(parameters p);
    void simulate();
    void tabChanged(int currentTab);

protected:
    void paintEvent(QPaintEvent *event);

private:
    Simulation sim;
    QTimer *plotTimer, *simTimer;
};

#endif // PAINTWIDGET_H
