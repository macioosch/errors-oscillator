#include <math.h>
#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent)
{
}

void PaintWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // brush and colors:
    static QPalette palette;
    painter.setBrush( palette.window());
    painter.setRenderHint( QPainter::Antialiasing, true);
    painter.setPen( QPen( Qt::black, 0.0));

    paintVisualisation( painter);
}

void PaintWidget::paintVisualisation(QPainter &painter)
{
    painter.translate( width()/2., height()/2.);
    double scale = height()/4.0;
    painter.scale( scale, scale);

    painter.drawEllipse( QPointF(0.0, p.x), 0.2, 0.2);
    double baseX = sin( p.w0 *p.t) *p.F0 /p.k;
    painter.drawLine( QPointF(-0.3, baseX), QPointF(0.3, baseX));

    static const QVector <QPointF> spring = springGenerator(10);
    painter.translate( 0.0, baseX);
    painter.scale( 0.2, p.x -baseX);
    painter.drawLines( spring);
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
