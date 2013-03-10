#ifndef ERRORPLOT_H
#define ERRORPLOT_H

#include "qcustomplot.h"
#include "simulation.h"

void errorUpdateData(parameters p);
void errorPlot(QCustomPlot *plt);
void errorPlotReset();

#endif // ERRORPLOT_H
