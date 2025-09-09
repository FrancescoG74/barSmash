#include "../headers/MyWindow.h"



MyWindow::MyWindow() : barX(0) {
    setWindowTitle("breakout");
    resize(800, 600);
    bar = QPixmap("../resources/bar1.png");
    background = QPixmap("../resources/background.png");
    QPixmap originalBall("../resources/ball.png");
    ball = originalBall.scaled(originalBall.width() / 2, originalBall.height() / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    // Center the ball
    ballX = (width() - ball.width()) / 2;
    ballY = (height() - ball.height()) / 2;
}

void MyWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Q) {
        close();
    } else if (event->key() == Qt::Key_Left) {
        barX = std::max(0, barX - 10);
        update();
    } else if (event->key() == Qt::Key_Right) {
        barX = std::min(width() - bar.width(), barX + 10);
        update();
    } else {
        QWidget::keyPressEvent(event);
    }
}



void MyWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    // Draw background
    painter.drawPixmap(0, 0, width(), height(), background);
    // Draw bar a bit up from the bottom
    int margin = 30;
    int barY = height() - bar.height() - margin;
    painter.drawPixmap(barX, barY, bar);
    // Draw ball
    painter.drawPixmap(ballX, ballY, ball);
}
