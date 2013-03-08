#include <math.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->dampingCheckBox, SIGNAL(clicked(bool)),
            this, SLOT(toggleDamping(bool)));
    connect(ui->forceCheckBox, SIGNAL(clicked(bool)),
            this, SLOT(toggleForce(bool)));
    connect(ui->resetPushButton, SIGNAL(clicked()),
            this, SLOT(resetSimulation()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)),
            ui->visualisationWidget, SLOT(tabChanged(int)));

    connect(ui->x0HorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateLabels()));

    updateLabels();
    resetSimulation();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleDamping(bool value)
{
    ui->bLabel->setEnabled(value);
    ui->bHorizontalSlider->setEnabled(value);
}

void MainWindow::toggleForce(bool value)
{
    ui->f0Label->setEnabled(value);
    ui->f0HorizontalSlider->setEnabled(value);
    ui->w0Label->setEnabled(value);
    ui->w0HorizontalSlider->setEnabled(value);
}

void MainWindow::resetSimulation()
{
    ui->visualisationWidget->resetSimulation(p);
}

void MainWindow::updateLabels()
{
    // values
    p.t = 0;
    p.x =  ui->x0HorizontalSlider->sliderPosition()/100.;
    p.v =  ui->v0HorizontalSlider->sliderPosition()/100.;
    if (ui->dampingCheckBox->isChecked())
        p.b =  pow10( ui->bHorizontalSlider->sliderPosition()/100.);
    else
        p.b = 0.0;
    if (ui->forceCheckBox->isChecked()) {
        p.F0 = ui->f0HorizontalSlider->sliderPosition()/100.;
        p.w0 = ui->w0HorizontalSlider->sliderPosition()/100.;
    } else {
        p.F0 = 0.0;
        p.w0 = 0.0;
    }
        p.k =  ui-> kHorizontalSlider->sliderPosition()/100.;
        p.m =  ui-> mHorizontalSlider->sliderPosition()/100.;
    p.Dt = pow10( ui->dtHorizontalSlider->sliderPosition()/10.);

    switch (ui->algorithmComboBox->currentIndex())
    {
    default : p.algorithm = EULER;
    }

    // text
    ui->x0Label->setText( QString( "x0 = %1").arg(p.x));
}
