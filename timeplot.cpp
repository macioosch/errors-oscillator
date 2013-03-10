#include "timeplot.h"
#define MAXPOINTS 0x1000

static QVector <double> t(MAXPOINTS), x(MAXPOINTS);
static int points = 0;

void timePlot(QCustomPlot *plt)
{
    static bool plotadded = false;
    if (!plotadded)
    {
        plotadded = true;
        plt->addGraph();
        plt->xAxis->setLabel("t");
        plt->yAxis->setLabel("x");
        plt->yAxis->setRange(-2, 2);
    }

    if (points < MAXPOINTS)
    {
        plt->graph(0)->clearData();
        plt->graph(0)->setData( t, x);
        plt->xAxis->setRange( 0, t[points-1]);
        plt->replot();
    }
}

void timePlotReset()
{
    t.fill(0);
    x.fill(0);
    points = 0;
}

void timeUpdateData(parameters p)
{
    if (points < MAXPOINTS)
    {
        t[points] = p.t;
        x[points] = -p.x;
        points++;
    }
}
