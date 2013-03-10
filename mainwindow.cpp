#include <math.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timeplot.h"
#include "phaseplot.h"
#include "errorplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->dampingCheckBox, SIGNAL(clicked(bool)), this, SLOT(toggleDamping(bool)));
    connect(ui->forceCheckBox, SIGNAL(clicked(bool)), this, SLOT(toggleForce(bool)));
    connect(ui->resetPushButton, SIGNAL(clicked()), this, SLOT(updateLabels()));
    connect(ui->algorithmComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateLabels()));

    connect(ui->x0HorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateLabels()));
    connect(ui->v0HorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateLabels()));
    connect(ui-> bHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateLabels()));
    connect(ui->f0HorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateLabels()));
    connect(ui->w0HorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateLabels()));
    connect(ui-> kHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateLabels()));
    connect(ui-> mHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateLabels()));
    connect(ui->dtHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateLabels()));

    updateLabels();

    savedDataPoints = 0;
    enoughDataPoints = false;

    plotTimer = new QTimer(this);
    connect(plotTimer, SIGNAL(timeout()), this, SLOT(updatePaintWidgets()));
    // a magic number - this should be changable in the GUI
    plotTimer->start(30);

    simTimer = new QTimer(this);
    connect(simTimer, SIGNAL(timeout()), this, SLOT(simulate()));
    // a magic number (10) - how to get rid of it?!
    simTimer->start(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleDamping(bool value)
{
    ui->bLabel->setEnabled(value);
    ui->bHorizontalSlider->setEnabled(value);
    updateLabels();
}

void MainWindow::toggleForce(bool value)
{
    ui->f0Label->setEnabled(value);
    ui->f0HorizontalSlider->setEnabled(value);
    ui->w0Label->setEnabled(value);
    ui->w0HorizontalSlider->setEnabled(value);
    updateLabels();
}

void MainWindow::resetSimulation()
{
    sim.reset(p);
    timePlotReset();
    phasePlotReset();
    errorPlotReset();
    savedDataPoints = 0;
    enoughDataPoints = false;
}

void MainWindow::updateLabels()
{
    // values
    p.t = 0;
    p.x =  ui->x0HorizontalSlider->sliderPosition()/100.;
    p.v =  ui->v0HorizontalSlider->sliderPosition()/100.;
    p.k =  ui-> kHorizontalSlider->sliderPosition()/100.;
    p.m =  ui-> mHorizontalSlider->sliderPosition()/100.;
    p.Dt = pow10( ui->dtHorizontalSlider->sliderPosition()/10.);
    if (ui->dampingCheckBox->isChecked())
        p.b =  pow10( ui->bHorizontalSlider->sliderPosition()/100.);
    else
        p.b = 0.0;
    if (ui->forceCheckBox->isChecked()) {
        p.F0 = ui->f0HorizontalSlider->sliderPosition()/100.;
        p.w0 = ui->w0HorizontalSlider->sliderPosition() *sqrt(p.k/p.m)/100.;
    } else {
        p.F0 = 0.0;
        p.w0 = 0.0;
    }

    switch (ui->algorithmComboBox->currentIndex())
    {
    case 0:
        p.algorithm = EULER;
        break;
    case 1:
        p.algorithm = RUNGE_KUTTA_4;
        break;
    default:
        p.algorithm = EULER;
    }

    // text
    ui->x0Label->setText( QString( "x0 = %L1").arg(p.x,  0, 'f', 2));
    ui->v0Label->setText( QString( "v0 = %L1").arg(p.v,  0, 'f', 2));
    ui-> bLabel->setText( QString(  "b = %L1").arg(p.b,  0, 'e', 1));
    ui->f0Label->setText( QString( "f0 = %L1").arg(p.F0, 0, 'f', 2));
    ui->w0Label->setText( QString( "w0 = %L1").arg(p.w0, 0, 'f', 2));
    ui-> kLabel->setText( QString(  "k = %L1").arg(p.k,  0, 'f', 2));
    ui-> mLabel->setText( QString(  "m = %L1").arg(p.m,  0, 'f', 2));
    ui->dtLabel->setText( QString( "dt = %L1").arg(p.Dt, 0, 'e', 1));

    resetSimulation();
}

void MainWindow::simulate()
{
    sim.step();

    const int maxPoints = 0x4000;
    if (savedDataPoints++ > maxPoints) enoughDataPoints = true;
    if (!enoughDataPoints)
    {
        timeUpdateData( sim.p);
        phaseUpdateData( sim.p);
        errorUpdateData( sim.p);
    }
}

void MainWindow::updatePaintWidgets()
{
    switch (ui->tabWidget->currentIndex())
    {
    case 0:
        ui->visualisationWidget->p = sim.p;
        ui->visualisationWidget->update();
        timePlot( ui->timePlot);
        break;
    case 1:
        phasePlot( ui->phasePlot);
        break;
    case 2:
        errorPlot( ui->errorPlot);
        break;
    }
}
