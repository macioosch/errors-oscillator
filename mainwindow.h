#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simulation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    parameters p;
    Simulation sim;
    QTimer *plotTimer, *simTimer;
    int savedDataPoints;
    bool enoughDataPoints;

private slots:
    void toggleDamping(bool value);
    void toggleForce(bool value);
    void resetSimulation();
    void updateLabels();
    void simulate();
    void updatePaintWidgets();
};

#endif // MAINWINDOW_H
