#include "my_widget.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include <QPainter>

#include <memory>

MyWidget::MyWidget(QWidget * parent) : QWidget(parent) {

    figList.push_back(new Triangle({2, 3}, {30, 40}, {70, 80}));

    figArray[0] = make_unique<Triangle>();
    figArray[1] = make_unique<Rectangle>();

    list<int> newRectangle_params = { 200, 70, 250, 100 };
    figArray[1]->setParams(newRectangle_params);

    figArray[2] = make_unique<Circle>();
    figArray[3] = make_unique<Circle>();

    list<int> newCircle_params = { 100, 100, 30 };
    figArray[3]->setParams(newCircle_params);

    figArray[4] = make_unique<Rectangle>();

    setMouseTracking(true);
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this); // Создаём новый объект рисовальщика
    for (int it = 0; it < FIG_NUM; ++it) {
        figArray[it]->drawFigure(&p);
    }

    p.setPen(QPen(Qt::black, 2, Qt::SolidLine));
    p.drawLine(10, 10, 310, 10);
    p.drawLine(310, 10, 310, 310);
    p.drawLine(310, 310, 10, 310);
    p.drawLine(10, 310, 10, 10);

    QFont font;
    font.setPixelSize(12);
    p.setFont(font);
    p.drawText(figInfoPos, QString::fromStdString(figInfo));
}

void MyWidget::mouseMoveEvent(QMouseEvent *event) {

    for (int it = 0; it < FIG_NUM; it++) {
        if (figArray[it]->isMouseInside(event->pos())) {
            figArray[it]->setColor(Qt::green);
            update();
        } else {
            figArray[it]->setColor(Qt::red);
            update();
        }
    }
}

void MyWidget::mousePressEvent(QMouseEvent *event){

    for (int it = 0; it < FIG_NUM; it++) {
        if (figArray[it]->isMouseInside(event->pos())) {
            figInfo = figArray[it]->getName();
            figInfoPos.setX(event->pos().x());
            figInfoPos.setY(event->pos().y() - 10);
            update();
        }
    }
}
