#include "timeplot.h"

static QVector <double> t, x;

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

    if (!t.empty())
    {
        plt->graph(0)->clearData();
        plt->graph(0)->setData( t, x);
        plt->xAxis->setRange( 0, *(t.end()-1));
        plt->replot();
    }
}

void timePlotReset()
{
    t.clear();
    x.clear();
}

void timeUpdateData(parameters p)
{
    t +=  p.t;
    x += -p.x;
}
