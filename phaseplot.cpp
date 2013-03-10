#include "phaseplot.h"
#define MAXPOINTS 0x1000

static QVector <double> x, v;
static int points = 0;

void phasePlot(QCustomPlot *plt)
{
    static QCPCurve *vx;
    static QCPItemText *textLabel;
    static QCPItemLine *arrow;

    static bool plotadded = false;
    if (!plotadded)
    {
        plotadded = true;
        vx = new QCPCurve(plt->xAxis, plt->yAxis);
        plt->addPlottable(vx);
        plt->xAxis->setLabel("x");
        plt->yAxis->setLabel("v");
        plt->xAxis->setRange(-2, 2);
        plt->yAxis->setRange(-2, 2);
        plt->xAxis->setAutoTickStep(false);
        plt->yAxis->setAutoTickStep(false);
        plt->xAxis->setTickStep(0.5);
        plt->yAxis->setTickStep(0.5);

        // add the text label indicating t=0 point:
        textLabel = new QCPItemText(plt);
        plt->addItem(textLabel);
        textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
        textLabel->setText("t = 0");

        // add the arrow:
        arrow = new QCPItemLine(plt);
        plt->addItem(arrow);
        arrow->start->setParentAnchor(textLabel->bottom);
        arrow->setHead(QCPLineEnding::esSpikeArrow);
    }

    if (points < MAXPOINTS)
    {
        vx->clearData();
        vx->setData( x, v);
        textLabel->position->setCoords(x[0]-0.3,v[0]+0.2);
        arrow->end->setCoords(x[0],v[0]);
        plt->replot();
    }
}

void phasePlotReset()
{
    x.clear();
    v.clear();
    points = 0;
}

void phaseUpdateData(parameters p)
{
    if (points < MAXPOINTS)
    {
        x += -p.x;
        v +=  p.v;
        points++;
    }
}
