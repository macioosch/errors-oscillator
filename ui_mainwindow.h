/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *x0Label;
    QSlider *x0HorizontalSlider;
    QHBoxLayout *horizontalLayout_4;
    QLabel *v0Label;
    QSlider *v0HorizontalSlider;
    QCheckBox *dampingCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *bLabel;
    QSlider *bHorizontalSlider;
    QCheckBox *forceCheckBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *f0Label;
    QSlider *f0HorizontalSlider;
    QHBoxLayout *horizontalLayout_6;
    QLabel *w0Label;
    QSlider *w0HorizontalSlider;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(760, 542);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        x0Label = new QLabel(centralWidget);
        x0Label->setObjectName(QStringLiteral("x0Label"));

        horizontalLayout_3->addWidget(x0Label);

        x0HorizontalSlider = new QSlider(centralWidget);
        x0HorizontalSlider->setObjectName(QStringLiteral("x0HorizontalSlider"));
        x0HorizontalSlider->setMinimum(-100);
        x0HorizontalSlider->setMaximum(100);
        x0HorizontalSlider->setValue(100);
        x0HorizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(x0HorizontalSlider);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        v0Label = new QLabel(centralWidget);
        v0Label->setObjectName(QStringLiteral("v0Label"));

        horizontalLayout_4->addWidget(v0Label);

        v0HorizontalSlider = new QSlider(centralWidget);
        v0HorizontalSlider->setObjectName(QStringLiteral("v0HorizontalSlider"));
        v0HorizontalSlider->setMinimum(-100);
        v0HorizontalSlider->setMaximum(100);
        v0HorizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(v0HorizontalSlider);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_4);

        dampingCheckBox = new QCheckBox(centralWidget);
        dampingCheckBox->setObjectName(QStringLiteral("dampingCheckBox"));

        verticalLayout->addWidget(dampingCheckBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        bLabel = new QLabel(centralWidget);
        bLabel->setObjectName(QStringLiteral("bLabel"));

        horizontalLayout_2->addWidget(bLabel);

        bHorizontalSlider = new QSlider(centralWidget);
        bHorizontalSlider->setObjectName(QStringLiteral("bHorizontalSlider"));
        bHorizontalSlider->setMinimum(-200);
        bHorizontalSlider->setMaximum(200);
        bHorizontalSlider->setValue(-100);
        bHorizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(bHorizontalSlider);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        forceCheckBox = new QCheckBox(centralWidget);
        forceCheckBox->setObjectName(QStringLiteral("forceCheckBox"));

        verticalLayout->addWidget(forceCheckBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        f0Label = new QLabel(centralWidget);
        f0Label->setObjectName(QStringLiteral("f0Label"));

        horizontalLayout_5->addWidget(f0Label);

        f0HorizontalSlider = new QSlider(centralWidget);
        f0HorizontalSlider->setObjectName(QStringLiteral("f0HorizontalSlider"));
        f0HorizontalSlider->setMaximum(200);
        f0HorizontalSlider->setValue(100);
        f0HorizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(f0HorizontalSlider);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        w0Label = new QLabel(centralWidget);
        w0Label->setObjectName(QStringLiteral("w0Label"));

        horizontalLayout_6->addWidget(w0Label);

        w0HorizontalSlider = new QSlider(centralWidget);
        w0HorizontalSlider->setObjectName(QStringLiteral("w0HorizontalSlider"));
        w0HorizontalSlider->setMinimum(1);
        w0HorizontalSlider->setMaximum(200);
        w0HorizontalSlider->setSliderPosition(100);
        w0HorizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(w0HorizontalSlider);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());

        horizontalLayout->addWidget(tabWidget);

        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 760, 24));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        x0Label->setText(QApplication::translate("MainWindow", "x0 = ", 0));
        v0Label->setText(QApplication::translate("MainWindow", "v0 = ", 0));
        dampingCheckBox->setText(QApplication::translate("MainWindow", "Damping", 0));
        bLabel->setText(QApplication::translate("MainWindow", "b = ", 0));
        forceCheckBox->setText(QApplication::translate("MainWindow", "Force", 0));
        f0Label->setText(QApplication::translate("MainWindow", "F0 =", 0));
        w0Label->setText(QApplication::translate("MainWindow", "w0 =", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Visualisation", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Phase plot", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Error", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Error versus timestep", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
