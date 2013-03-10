#include "phaseplot.h"
#define MAXPOINTS 0x1000

static QVector <double> x(MAXPOINTS), v(MAXPOINTS);
static int points = 0;

void phasePlot(QCustomPlot *plt)
{
    static bool plotadded = false;
    if (!plotadded)
    {
        plotadded = true;
        plt->addGraph();
        plt->xAxis->setLabel("x");
        plt->yAxis->setLabel("v");
        plt->xAxis->setRange(-2, 2);
        plt->yAxis->setRange(-2, 2);
    }

    if (points < MAXPOINTS)
    {
        plt->graph(0)->clearData();
        plt->graph(0)->setData( x, v);
        plt->replot();
    }
}

void phasePlotReset()
{
    x.fill(0.0);
    v.fill(0.0);
    points = 0;
}

void phaseUpdateData(parameters p)
{
    if (points < MAXPOINTS)
    {
        x[points] = -p.x;
        v[points] = p.v;
        points++;
    }
}
