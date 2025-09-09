#pragma once
#include "Actor.h"
#include <QPixmap>

class Ball : public Actor {
public:
    QPixmap pixmap;
    Ball(float x = 0, float y = 0, float vx = 0, float vy = 0)
        : Actor(x, y, vx, vy) {
        QPixmap original("../resources/ball.png");
        pixmap = original.scaled(original.width() / 2, original.height() / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
};
