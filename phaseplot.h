#ifndef PHASEPLOT_H
#define PHASEPLOT_H

#include "qcustomplot.h"
#include "simulation.h"

void phaseUpdateData(parameters p);
void phasePlot(QCustomPlot *plt);
void phasePlotReset();

#endif // PHASEPLOT_H
