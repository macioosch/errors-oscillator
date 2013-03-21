#include "errorplot.h"

// time, Energy difference, sum of squares of dE, standard deviation of dE
static QVector <double> t, dE, sKwDE, stDevE, dx, dv;
static double maxE = 0.0;

double theoreticalX(double x0, double v0, double b, double k, double m, double t)
{
    static double px0, pv0, pb, pk, pm,
                  c0, c1, c2, c3, c4;
    if (!(    x0 == px0
           && v0 == pv0
           && b  == pb
           && k  == pk
           && m  == pm  ))
    {
        px0 = x0;
        pv0 = v0;
        pb  = b;
        pk  = k;
        pm  = m;

        c0 = sqrt( 4.0*k*m - pow(b,2) );
        c1 = -b/(2.0*m);
        c2 = c0*x0;
        c3 = c0/(2.0*m);
        c4 = 2.0*m*v0 + x0*b;
    }

    return exp(c1*t)*( c2*cos(c3*t) + c4*sin(c3*t) ) / c0;
}

double theoreticalV(double x0, double v0, double b, double k, double m, double t)
{
    static double px0, pv0, pb, pk, pm,
                  c0, c1, c2, c3, c4;
    if (!(    x0 == px0
           && v0 == pv0
           && b  == pb
           && k  == pk
           && m  == pm  ))
    {
        px0 = x0;
        pv0 = v0;
        pb  = b;
        pk  = k;
        pm  = m;

        c0 = sqrt( 4.0*k*m - pow(b,2) );
        c1 = -b/(2.0*m);
        c2 = c0*v0;
        c3 = c0/(2.0*m);
        c4 = -2.0*k*x0 - v0*b;
    }

    return exp(c1*t)*( c2*cos(c3*t) + c4*sin(c3*t) ) / c0;
}

void errorPlot(QCustomPlot *plt)
{
    static bool plotadded = false;
    if (!plotadded)
    {
        plotadded = true;
        plt->addGraph();
        plt->addGraph();
        plt->addGraph();
        plt->addGraph();
        plt->xAxis->setLabel("t [a. u.]");
        plt->yAxis->setLabel("dE, dx [a. u.]");
        plt->graph(0)->setName("|DE/E0 - 1|");
        plt->graph(1)->setName("sqrt(<(DE/E0 - 1)^2>)");
        plt->graph(2)->setName("Error of x");
        plt->graph(2)->setName("Error of v");
        plt->graph(0)->setPen(QPen(Qt::gray));
        plt->graph(1)->setPen(QPen(Qt::red));
        plt->graph(2)->setPen(QPen(Qt::green));
        plt->graph(3)->setPen(QPen(Qt::blue));
        plt->legend->setVisible(true);
        plt->legend->setPositionStyle(QCPLegend::psTopLeft);
    }

    if (!dE.empty())
    {
        maxE = std::max( maxE, std::max( dE.last(), stDevE.last() ));

        plt->graph(0)->clearData();
        plt->graph(1)->clearData();
        plt->graph(2)->clearData();
        plt->graph(3)->clearData();
        plt->graph(0)->setData( t, dE);
        plt->graph(1)->setData( t, stDevE);
        plt->graph(2)->setData( t, dx);
        plt->graph(3)->setData( t, dv);
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
    dx.clear();
    dv.clear();
}

void errorUpdateData(parameters p)
{
    static double e0 = 0.0, tx, tv;
    tx = theoreticalX(p.x0, p.v0, p.b, p.k, p.m, p.t);
    tv = theoreticalV(p.x0, p.v0, p.b, p.k, p.m, p.t);
    dx += p.x - tx;
    dv += p.v - tv;
    if (dE.empty())
    {
        e0 = 0.5*(p.k*pow(p.x,2) + p.m*pow(p.v,2));
        dE += 0.0;
        sKwDE += 0.0;
        stDevE += 0.0;
        maxE = 0.0;
    } else {
        if (p.b == 0.0)
            dE += 0.5*(p.k*pow(p.x,2) + p.m*pow(p.v,2))/e0 - 1.0;
        else
            dE += (p.k*pow(p.x,2) + p.m*pow(p.v,2))
                / (p.k*pow(tx, 2) + p.m*pow(tv, 2)) - 1.0;
        sKwDE += sKwDE.last() + pow( dE.last(), 2);
        stDevE += sqrt( sKwDE.last() /sKwDE.size());
    }
    t += p.t;
}
