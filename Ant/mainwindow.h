#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <vector>
#include "field.h"

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
    Field* gameField;
    int visualizedSteps;
    int sliderValue;
    QImage image;
    bool stopVis;
    QGraphicsScene* currentScene;

    void drawPoint(QPainter& p, int fieldX, int fieldY, QBrush color);
    void drawField(QPixmap& image, const std::vector<std::vector<Cell>>& cells, Direction antDirection);
    void testGen();
private slots:
    void onEvolveButton();
    void onVisualizeButton();
    void timerGenerateField();
    void timerMoveAnt();
};

#endif // MAINWINDOW_H
