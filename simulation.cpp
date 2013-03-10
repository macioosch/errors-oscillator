#include "simulation.h"
#include <math.h>

double a(const parameters &p, double x0, double v0, double t0);
void euler(const parameters &p, double &xf, double &vf);
void rK4(const parameters &p, double &xf, double &vf);


Simulation::Simulation()
{
    // do not draw before setting the variables (by reset)!
    simulationLock = true;
}
void Simulation::reset(parameters p0)
{
    p = p0;
    simulationLock = false;
}

void Simulation::step()
{
    if (simulationLock)
        return;
    simulationLock = true;

    double x1, v1;
    void (*chosenAlgorithm)(const parameters&, double&, double&);

    switch (p.algorithm)
    {
    case EULER:
        chosenAlgorithm = euler;
        break;
    case RUNGE_KUTTA_4:
        chosenAlgorithm = rK4;
        break;
    }

    for (int i=0; i<1e4; i++)
    {
        (*chosenAlgorithm)( p, x1, v1);
        p.v = v1;
        p.x = x1;
        p.t += p.Dt;
    }

    simulationLock = false;
}

double a(const parameters &p, double x0, double v0, double t0)
{
    return (-p.k*x0 -p.b*v0 +p.F0*sin(p.w0*t0))/p.m;
}

void euler(const parameters &p, double &xf, double &vf)
{
    vf = p.v +p.Dt *a(p, p.x, p.v, p.t);
    xf = p.x +p.Dt *p.v;
}

void rK4(const parameters &p, double &xf, double &vf)
{
    double  x1, v1, a1,
            x2, v2, a2,
            x3, v3, a3,
            x4, v4, a4;

    x1 = p.x;
    v1 = p.v;
    a1 = a(p, x1, v1, p.t);

    x2 = p.x + 0.5*v1*p.Dt;
    v2 = p.v + 0.5*a1*p.Dt;
    a2 = a(p, x2, v2, p.t + 0.5*p.Dt);

    x3 = p.x + 0.5*v2*p.Dt;
    v3 = p.v + 0.5*a2*p.Dt;
    a3 = a(p, x3, v3, p.t + 0.5*p.Dt);

    x4 = p.x + v3*p.Dt;
    v4 = p.v + a3*p.Dt;
    a4 = a(p, x4, v4, p.t + p.Dt);

    xf = p.x + (p.Dt/6.0)*(v1 + 2*v2 + 2*v3 + v4);
    vf = p.v + (p.Dt/6.0)*(a1 + 2*a2 + 2*a3 + a4);
}
