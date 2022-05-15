#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "abstract_figure.h"
#include <QMouseEvent>

#define FIG_NUM 5

class MyWidget : public QWidget {

    string figInfo = "";
    QPoint figInfoPos;

    std::unique_ptr<AbstractFigure> figArray[FIG_NUM];

  protected:
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
  public:
	MyWidget(QWidget * parent = 0);

};

#endif // MYWIDGET_H
