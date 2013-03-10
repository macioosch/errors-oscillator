#include "errorplot.h"

static QVector <double> t, dE, sKwDE, stDevE;
static double maxE = 0.0;

void errorPlot(QCustomPlot *plt)
{
    static bool plotadded = false;
    if (!plotadded)
    {
        plotadded = true;
        plt->addGraph();
        plt->addGraph();
        plt->xAxis->setLabel("t");
        plt->yAxis->setLabel("E");
        plt->graph(0)->setName("|DE/E0 - 1|");
        plt->graph(1)->setName("sqrt(<(DE/E0 - 1)^2>)");
        plt->graph(1)->setPen(QPen(Qt::red));
        plt->legend->setVisible(true);
        plt->legend->setPositionStyle(QCPLegend::psTopLeft);
    }

    if (!dE.empty())
    {
        maxE = std::max( maxE, std::max( dE.last(), stDevE.last() ));

        plt->graph(0)->clearData();
        plt->graph(1)->clearData();
        plt->graph(0)->setData( t, dE);
        plt->graph(1)->setData( t, stDevE);
        plt->xAxis->setRange( 0.0, t.last());
        plt->yAxis->setRange( 0.0, maxE);
        plt->replot();
    }
}

void errorPlotReset()
{
    t.clear();
    dE.clear();
    sKwDE.clear();
    stDevE.clear();
}

void errorUpdateData(parameters p)
{
    static double e0 = 0.0;
    if (dE.empty())
    {
        e0 = 0.5*(p.k*pow(p.x,2) + p.m*pow(p.v,2));
        dE += 0.0;
        sKwDE += 0.0;
        stDevE += 0.0;
        maxE = 0.0;
    } else {
        dE += fabs( 0.5*(p.k*pow( p.x, 2) + p.m*pow( p.v, 2))/e0 - 1.0);
        sKwDE += sKwDE.last() + pow( dE.last(), 2);
        stDevE += sqrt( sKwDE.last() /sKwDE.size());
    }
    t +=  p.t;
}
