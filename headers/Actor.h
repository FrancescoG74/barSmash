#pragma once

class Actor {
public:
    Actor(float x = 0, float y = 0, float vx = 0, float vy = 0)
        : x(x), y(y), vx(vx), vy(vy) {}

    virtual void handleKeyPress(QKeyEvent *event, int windowWidth) {}

    float x;
    float y;
    float vx;
    float vy;
};
