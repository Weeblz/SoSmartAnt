#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qtimer>
#include <memory>
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), gameField(nullptr),
    ui(new Ui::MainWindow), currentScene(nullptr)
{
    ui->setupUi(this);

    ui->visualizeButton->setEnabled(false);
    image = QImage(":/img/res/grid.jpg");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawPoint(QPainter& p, int fieldX, int fieldY, QBrush color) {
    QPen pen(color, 1);
    p.setPen(pen);
    QBrush brush(color);
    p.setBrush(brush);

    int x = 20 * fieldX + 6;
    int y = 20 * fieldY + 6;
    p.drawRect(x, y, 10, 10);
}

void MainWindow::drawField(QPixmap& image, const std::vector<std::vector<Cell>>& cells, Direction antDirection) {
    //auto scene = std::make_shared<QGraphicsScene>(this);
    if(currentScene) delete currentScene;
    currentScene = new QGraphicsScene(this);
    QPainter p(&image);
    p.setRenderHint(QPainter::Antialiasing, true);

    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            if (cells[j][i].type == APPLE) {
                drawPoint(p, j, i, Qt::black);
            }
            else if (cells[j][i].type == APPLEWAY) {
                drawPoint(p, j, i, Qt::gray);
            }
            else if (cells[j][i].type == PASSED){
                QImage antImg;
                switch (antDirection){
                    case RIGHT: antImg = QImage(":/img/res/ant_east.png"); break;
                    case LEFT: antImg = QImage(":/img/res/ant_west.png"); break;
                    case DOWN: antImg = QImage(":/img/res/ant_south.png"); break;
                    default: antImg = QImage(":/img/res/ant_north.png"); break;
                }
                QPixmap antPm = QPixmap::fromImage(antImg);
                int x = 20 * j + 2;
                int y = 20 * i + 2;
                p.drawPixmap(x, y, 20, 20, antPm);
            }
        }
    }

    currentScene->addPixmap(image);
    currentScene->setSceneRect(image.rect());
    ui->graphicsView->setScene(currentScene);
}

void MainWindow::onEvolveButton() {
    ui->evolveButton->setText("Evolving...");
    ui->evolveButton->setEnabled(false);
    ui->visualizeButton->setEnabled(false);
    QTimer::singleShot(100, this, SLOT(timerGenerateField()));
}

void MainWindow::onVisualizeButton() {
    //qDebug() << visualizedSteps;

    if (stopVis){
        ui->evolveButton->setEnabled(false);
        ui->visualizeButton->setText("Stop");
        QTimer::singleShot(500, this, SLOT(timerMoveAnt()));
        stopVis = false;
    }
    else {
        ui->evolveButton->setEnabled(true);
        ui->visualizeButton->setText("Resume");
        stopVis = true;
    }
}

void MainWindow::timerGenerateField() {
    if(gameField) delete gameField;
    visualizedSteps = 0;
    stopVis = true;
    gameField = new Field(Position(0, 0));

    ui->evolveButton->setText("Regenerate");
    ui->visualizeButton->setText("Visualize");
    ui->evolveButton->setEnabled(true);
    ui->visualizeButton->setEnabled(true);
    ui->scoreLabel->setText(QString("Steps: 0\n\nApples: 0"));
}

void MainWindow::timerMoveAnt() {
    // Stop pressed
    if (stopVis) return;

    QPixmap pm = QPixmap::fromImage(image);
    gameField->updateField();
    std::vector<std::vector<Cell>> cells = gameField->getPlayingGrid();

    drawField(pm, cells, gameField->ant.getDirection());

    visualizedSteps++;

    int eatenApples = APPLES_COUNT - gameField->getApplesLeft();
    QString str;
    str.sprintf("Steps: %d\n\nApples: %d", visualizedSteps, eatenApples);
    ui->scoreLabel->setText(str);

    if (visualizedSteps >= 200){
        ui->visualizeButton->setText("End reached");
        ui->visualizeButton->setEnabled(false);
        ui->evolveButton->setEnabled(true);
        return;
    }
    else if (ui->horizontalSlider->value() != sliderValue){
        sliderValue = ui->horizontalSlider->value();
    }
    int interval = 200 + (100 - sliderValue) * 10;

    QTimer::singleShot(interval, this, SLOT(timerMoveAnt()));
}
