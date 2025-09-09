
#pragma once
#include <algorithm>

#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QPixmap>

class MyWindow : public QWidget {
public:
    MyWindow();
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
private:
    QPixmap bar;
    QPixmap background;
    QPixmap ball;
    int barX;
    int ballX = 0;
    int ballY = 0;
};
