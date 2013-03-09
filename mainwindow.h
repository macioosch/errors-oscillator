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

private slots:
    void toggleDamping(bool value);
    void toggleForce(bool value);
    void resetSimulation();
    void updateLabels();
    void simulate();
    void tabChanged(int currentTab);
    void updatePaintWidgets();
};

#endif // MAINWINDOW_H
