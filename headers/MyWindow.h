
#pragma once
#include <algorithm>


#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include "Ball.h"
#include "Bar.h"
#include "Brick.h"

class MyWindow : public QWidget {
//    Q_OBJECT
public:
    MyWindow();
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
private:
    QPixmap barPixmap;
    QPixmap background;
    QPixmap ballPixmap;
    Ball ball;
    Bar bar;
    std::vector<Brick> bricks;
    int score = 0;
    bool ballAttached = true;
    QTimer *timer = nullptr;
private slots:
    void onTimer();
};
