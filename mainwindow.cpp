#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jfind.h"
#include <QLayout>
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	JFind* jfind = new JFind();
	QHBoxLayout* layout = new QHBoxLayout;
//	layout->addWidget(jfind, Qt::AlignCenter);
//	setLayout(layout);
	this->layout()->addWidget(jfind);
	int x = this->width() / 2 -70;
	int y = this->height() /2 - 50;
	jfind->move(x,y);


}

MainWindow::~MainWindow()
{
	delete ui;
}

