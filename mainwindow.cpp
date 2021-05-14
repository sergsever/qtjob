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
	JFind* jfind = new JFind(this);
	QHBoxLayout* layout = new QHBoxLayout;
//	layout->addWidget(jfind, Qt::AlignCenter);
//	setLayout(layout);
//	this->layout()->addWidget(jfind);
//	setCentralWidget(jfind);
	int x = this->width() / 2 - (JFind::widtch/2);
	int y = this->height() /2 - (JFind::height/2);
//	jfind->move(x,y);


}

MainWindow::~MainWindow()
{
	delete ui;
}

