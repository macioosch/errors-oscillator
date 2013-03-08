#include "QTimer"
#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent)
{
    QTimer *plotTimer = new QTimer(this);
    connect(plotTimer, SIGNAL(timeout()), this, SLOT(update()));
    // a magic number - this should be changable in the GUI
    plotTimer->start(15);

    QTimer *simTimer = new QTimer(this);
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
}

void simulate()
{

}
