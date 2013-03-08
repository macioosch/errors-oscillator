#include "simulation.h"
#include <math.h>

Simulation::Simulation()
{
    // do not draw before setting the variables (by reset)!
    simulationLock = true;
}

void Simulation::euler(double t0, double x0, double v0,
                       double (*a)(double, double, double), double &x1, double &v1)
{
    v1 = v0 +p.Dt *(*a)( t0, x0, v0);
    x1 = x0 +p.Dt *v0;
}

void Simulation::reset(parameters p0)
{
    p = p0;
}

void Simulation::step()
{
    if (simulationLock)
        return;
    simulationLock = true;

    double x1, v1;

    switch (p.algorithm)
    {
    case EULER: euler( p.t, p.x, p.v, acceleration, x1, v1);
    }

    p.v = v1;
    p.x = x1;
    p.t += p.Dt;

    simulationLock = false;
}

double Simulation::acceleration(double t0, double x0, double v0)
{
    return - p.k *pow( x0,2) - p.b*v0 + p.F0 *sin( p.w0*t0);
}
