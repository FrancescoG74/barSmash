#pragma once
#include "Actor.h"
#include <QPixmap>

class Brick : public Actor {
public:
    QPixmap pixmap;
    bool destroyed = false;
    Brick(float x = 0, float y = 0)
        : Actor(x, y, 0, 0) {
        pixmap = QPixmap("../resources/tileBlue.png");
    }
};
