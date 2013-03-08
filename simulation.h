#ifndef SIMULATION_H
#define SIMULATION_H

enum integrator
{
    EULER
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
    static double acceleration(parameters p, double t0, double x0, double v0);
    void euler(double t0, double x0, double v0,
               double (*a)(parameters, double, double, double), double &x1, double &v1);
    bool simulationLock;
};

#endif // SIMULATION_H
