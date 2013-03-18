#include "phaseplot.h"

// globalne zmienne - nieładnie! :/
static QVector <double> x, v, x0, v0;

void phasePlot(QCustomPlot *plt)
{
    static QCPCurve *vx, *vx0;
    static QCPItemText *textLabel;
    static QCPItemLine *arrow;

    static bool plotadded = false;
    if (!plotadded)
    {
        plotadded = true;
        plt->xAxis->setLabel("x");
        plt->yAxis->setLabel("v");
        plt->xAxis->setRange(-2, 2);
        plt->yAxis->setRange(-2, 2);
        plt->xAxis->setAutoTickStep(false);
        plt->yAxis->setAutoTickStep(false);
        plt->xAxis->setTickStep(0.5);
        plt->yAxis->setTickStep(0.5);

        // ball's curve (blue)
        vx  = new QCPCurve(plt->xAxis, plt->yAxis);
        vx->setPen(QPen(Qt::blue));
        plt->addPlottable(vx);
        // driving force's curve (red)
        vx0 = new QCPCurve(plt->xAxis, plt->yAxis);
        vx0->setPen(QPen(Qt::red));
        plt->addPlottable(vx0);
        // blue dot
        plt->addGraph();
        plt->graph(0)->setPen(QPen(QColor(127,127,255)));
        plt->graph(0)->setLineStyle(QCPGraph::lsNone);
        plt->graph(0)->setScatterStyle(QCP::ssDisc);
        // red dot
        plt->addGraph();
        plt->graph(1)->setPen(QPen(QColor(255,127,127)));
        plt->graph(1)->setLineStyle(QCPGraph::lsNone);
        plt->graph(1)->setScatterStyle(QCP::ssDisc);

        // text label indicating t=0 point
        textLabel = new QCPItemText(plt);
        plt->addItem(textLabel);
        textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
        textLabel->setText("t = 0");
        // arrow
        arrow = new QCPItemLine(plt);
        plt->addItem(arrow);
        arrow->start->setParentAnchor(textLabel->bottom);
        arrow->setHead(QCPLineEnding::esSpikeArrow);
    }

    if (!x.empty())
    {
        vx->clearData();
        vx->setData( x, v);

        vx0->clearData();
        vx0->setData( x0, v0);

        plt->graph(0)->clearData();
        plt->graph(0)->addData( x.last(), v.last() );

        plt->graph(1)->clearData();
        plt->graph(1)->addData( x0.last(), v0.last() );

        textLabel->position->setCoords(x[0]-0.3,v[0]+0.2);
        arrow->end->setCoords(x[0],v[0]);

        plt->replot();
    }
}

void phasePlotReset()
{
    x.clear();
    v.clear();
    x0.clear();
    v0.clear();
}

void phaseUpdateData(parameters p)
{
    x += -p.x;
    v +=  p.v;
    x0 += -sin(p.w0*p.t)*p.F0/p.k;
    v0 += cos(p.w0*p.t)*p.w0*p.F0/p.k;
}
