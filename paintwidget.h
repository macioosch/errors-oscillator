#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include "simulation.h"

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = 0);
    
public slots:
    void resetSimulation(struct parameters p);
    void simulate();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Simulation sim;
};

#endif // PAINTWIDGET_H
