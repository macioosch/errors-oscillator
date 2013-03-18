#ifndef SIMULATION_H
#define SIMULATION_H

enum integrator
{
    EULER,
    RUNGE_KUTTA_4,
    VERLET,
    VERLET_LEAP_FROG,
    VERLET_VELOCITY
};

typedef struct {
    double t;
    double x;
    double v;
    double b;
    double F0;
    double w0;
    double k;
    double m;
    double Dt;
    integrator algorithm;
} parameters;

class Simulation
{
public:
    Simulation();
    parameters p;
    void reset(parameters p0);
    void step();

private:
    bool simulationLock;
};

#endif // SIMULATION_H
