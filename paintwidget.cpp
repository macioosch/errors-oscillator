#include <math.h>
#include <QPainter>
#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent)
{
    plotTimer = new QTimer(this);
    connect(plotTimer, SIGNAL(timeout()), this, SLOT(update()));
    // a magic number - this should be changable in the GUI
    plotTimer->start(15);

    simTimer = new QTimer(this);
    connect(simTimer, SIGNAL(timeout()), this, SLOT(simulate()));
    // a magic number (10) - how to get rid of it?!
    simTimer->start(10);
}

void PaintWidget::paintEvent(QPaintEvent *)
{
    QPainter painter( this);

    // brush and colors:
    static QPalette palette;
    painter.setBrush( palette.window());
    painter.setRenderHint( QPainter::Antialiasing, true);
    painter.setPen( QPen( Qt::black, 0.0));

    painter.translate( width()/2., height()/2.);
    double scale = height()/4.0;
    painter.scale( scale, scale);

    painter.drawEllipse( QPointF(0.0, sim.p.x), 0.2, 0.2);
    double baseX = sin( sim.p.w0 *sim.p.t) *sim.p.F0 /sim.p.k;
    painter.drawLine( QPointF(-0.3, baseX), QPointF(0.3, baseX));

    static const QVector <QPointF> spring = springGenerator(10);
    painter.translate( 0.0, baseX);
    painter.scale( 0.2, sim.p.x -baseX);
    painter.drawLines( spring);
}

void PaintWidget::resetSimulation(parameters p)
{
    sim.reset(p);
}

void PaintWidget::simulate()
{
    sim.step();
}

void PaintWidget::tabChanged(int currentTab)
{
    if (currentTab == 0 && ! plotTimer->isActive())
        plotTimer->start();
    if (currentTab != 0 && plotTimer->isActive())
        plotTimer->stop();
}

QVector <QPointF> springGenerator(int n)
{
    QVector <QPointF> s;
    QPointF tempPoint;
    s += QPointF(0,0);
    for (int i=1; i<n-1; i++)
    {
        tempPoint = QPointF( 0.5*pow(-1,i), (i-0.5)/(n-2.0));
        s += tempPoint;
        s += tempPoint;
    }
    s += QPointF(0,1);
    return s;
}
