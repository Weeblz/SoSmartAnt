/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *scoreLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *generationSize;
    QLabel *numberOfGenerations;
    QLabel *mutationProbability;
    QLabel *numberOfStates;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *evolveButton;
    QPushButton *visualizeButton;
    QSlider *horizontalSlider;
    QLabel *antScore;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(847, 729);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 661, 661));
        scoreLabel = new QLabel(centralWidget);
        scoreLabel->setObjectName(QStringLiteral("scoreLabel"));
        scoreLabel->setGeometry(QRect(680, 160, 161, 51));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(680, 250, 161, 72));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        generationSize = new QLabel(widget);
        generationSize->setObjectName(QStringLiteral("generationSize"));

        verticalLayout_3->addWidget(generationSize);

        numberOfGenerations = new QLabel(widget);
        numberOfGenerations->setObjectName(QStringLiteral("numberOfGenerations"));

        verticalLayout_3->addWidget(numberOfGenerations);

        mutationProbability = new QLabel(widget);
        mutationProbability->setObjectName(QStringLiteral("mutationProbability"));

        verticalLayout_3->addWidget(mutationProbability);

        numberOfStates = new QLabel(widget);
        numberOfStates->setObjectName(QStringLiteral("numberOfStates"));

        verticalLayout_3->addWidget(numberOfStates);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(680, 10, 161, 141));
        verticalLayout_4 = new QVBoxLayout(widget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        evolveButton = new QPushButton(widget1);
        evolveButton->setObjectName(QStringLiteral("evolveButton"));

        verticalLayout->addWidget(evolveButton);

        visualizeButton = new QPushButton(widget1);
        visualizeButton->setObjectName(QStringLiteral("visualizeButton"));

        verticalLayout->addWidget(visualizeButton);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalSlider = new QSlider(widget1);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);


        verticalLayout_4->addLayout(verticalLayout_2);

        antScore = new QLabel(widget1);
        antScore->setObjectName(QStringLiteral("antScore"));

        verticalLayout_4->addWidget(antScore);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 847, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(evolveButton, SIGNAL(clicked()), MainWindow, SLOT(onEvolveButton()));
        QObject::connect(visualizeButton, SIGNAL(clicked()), MainWindow, SLOT(onVisualizeButton()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        scoreLabel->setText(QString());
        generationSize->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        numberOfGenerations->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        mutationProbability->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        numberOfStates->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        evolveButton->setText(QApplication::translate("MainWindow", "Evolve Ant", Q_NULLPTR));
        visualizeButton->setText(QApplication::translate("MainWindow", "Vizualize", Q_NULLPTR));
        antScore->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
