#ifndef TIMEPLOT_H
#define TIMEPLOT_H

#include "qcustomplot.h"
#include "simulation.h"

void timeUpdateData(parameters p);
void timePlot(QCustomPlot *plt);
void timePlotReset();

#endif // TIMEPLOT_H
