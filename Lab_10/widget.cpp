#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	  , ui(new Ui::Widget) {
	ui->setupUi(this);

	// Создаем виджет
	wgt = new MyWidget(this);

	// И кладём его в лайаут
	ui->verticalLayout->addWidget(wgt);
}

Widget::~Widget() {
	delete ui;
}

