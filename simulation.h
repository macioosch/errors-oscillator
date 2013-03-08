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
    struct integrator algorithm;
} parameters;

class Simulation
{
public:
    Simulation();
    ~Simulation();
    struct parameters p;

private:
    double acceleration(double t0, double x0, double v0);
    void euler(double t0, double x0, double v0,
               double (*a)(double, double, double), double &x1, double &v1);
    bool simulationLock;

public slots:
    void reset(struct parameters p0);
    void step();
};

#endif // SIMULATION_H
