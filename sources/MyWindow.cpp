
#include "../headers/MyWindow.h"
#include <QTimer>
#include <random>



MyWindow::MyWindow() {
    // Start timer for ball movement
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MyWindow::onTimer);
    timer->start(16); // ~60 FPS
    setWindowTitle("breakout");
    resize(800, 600);
    background = QPixmap("../resources/background.png");
    // Center the bar
    bar.x = (width() - bar.pixmap.width()) / 2;
    bar.y = height() - bar.pixmap.height() - 30;
    // Attach ball to bar
    ball = Ball(bar.x + (bar.pixmap.width() - ball.pixmap.width()) / 2,
               bar.y - ball.pixmap.height());

    // Create 5x3 grid of bricks in upper part of window
    int cols = 4, rows = 3;
    int spacing = 10;
    int brickW = Brick().pixmap.width();
    int brickH = Brick().pixmap.height();
    int totalW = cols * brickW + (cols - 1) * spacing;
    int startX = (width() - totalW) / 2;
    int startY = 40;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            float x = startX + col * (brickW + spacing);
            float y = startY + row * (brickH + spacing);
            bricks.emplace_back(x, y);
        }
    }
}

void MyWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Q) {
        close();
    } else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right) {
        bar.handleKeyPress(event, width());
        if (ballAttached) {
            ball.x = bar.x + (bar.pixmap.width() - ball.pixmap.width()) / 2;
            ball.y = bar.y - ball.pixmap.height();
        }
        update();
    } else if (event->key() == Qt::Key_Space) {
        if (ballAttached) {
            ballAttached = false;
            // Random velocity
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<float> vxDist(-4.0f, 4.0f);
            float vx = vxDist(gen);
            // Ensure vx is not too small (avoid vertical launch)
            if (std::abs(vx) < 1.0f) {
                vx = (vx < 0 ? -1.0f : 1.0f);
            }
            ball.vx = vx;
            ball.vy = -4.0f;
        }
    } else {
        QWidget::keyPressEvent(event);
    }
}

void MyWindow::onTimer() {
    if (!ballAttached) {
        ball.x += ball.vx;
        ball.y += ball.vy;
        // Simple wall collision
        if (ball.x < 0) {
            ball.x = 0;
            ball.vx = -ball.vx;
        } else if (ball.x + ball.pixmap.width() > width()) {
            ball.x = width() - ball.pixmap.width();
            ball.vx = -ball.vx;
        }
        if (ball.y < 0) {
            ball.y = 0;
            ball.vy = -ball.vy;
        }
        // Ball goes under bottom: reset and re-attach
        if (ball.y > height()) {
            ballAttached = true;
            ball.vx = 0;
            ball.vy = 0;
            ball.x = bar.x + (bar.pixmap.width() - ball.pixmap.width()) / 2;
            ball.y = bar.y - ball.pixmap.height();
        }

        // Ball-brick collision
        float ballLeft = ball.x;
        float ballRight = ball.x + ball.pixmap.width();
        float ballTop = ball.y;
        float ballBottom = ball.y + ball.pixmap.height();
        for (auto& brick : bricks) {
            if (brick.destroyed) continue;
            float brickLeft = brick.x;
            float brickRight = brick.x + brick.pixmap.width();
            float brickTop = brick.y;
            float brickBottom = brick.y + brick.pixmap.height();
            if (ballRight >= brickLeft && ballLeft <= brickRight && ballBottom >= brickTop && ballTop <= brickBottom) {
                brick.destroyed = true;
                ball.vy = -ball.vy;
                break;
            }
        }
        // Ball-bar collision
        float barLeft = bar.x;
        float barRight = bar.x + bar.pixmap.width();
        float barTop = bar.y;
        float barBottom = bar.y + bar.pixmap.height();
        if (ballBottom >= barTop && ballTop <= barBottom && ballRight >= barLeft && ballLeft <= barRight && ball.vy > 0) {
            ball.y = barTop - ball.pixmap.height(); // Place ball above bar
            ball.vy = -ball.vy;
        }

        update();
    }
}




void MyWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    // Draw background
    painter.drawPixmap(0, 0, width(), height(), background);
    // Draw bricks
    for (const auto& brick : bricks) {
        if (!brick.destroyed)
            painter.drawPixmap((int)brick.x, (int)brick.y, brick.pixmap);
    }
    // Draw bar
    painter.drawPixmap((int)bar.x, (int)bar.y, bar.pixmap);
    // Draw ball
    painter.drawPixmap((int)ball.x, (int)ball.y, ball.pixmap);
}
