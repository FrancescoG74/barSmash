#pragma once
#include "Actor.h"
#include <QPixmap>

class Bar : public Actor {
public:
    QPixmap pixmap;
    Bar(float x = 0, float y = 0, float vx = 0, float vy = 0)
        : Actor(x, y, vx, vy) {
        pixmap = QPixmap("../resources/bar1.png");
    }

    void handleKeyPress(QKeyEvent *event, int windowWidth) override {
        if (event->key() == Qt::Key_Left) {
            x = std::max(0.0f, x - 10.0f);
        } else if (event->key() == Qt::Key_Right) {
            x = std::min((float)(windowWidth - pixmap.width()), x + 10.0f);
        }
    }
};
