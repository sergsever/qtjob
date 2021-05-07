#include "jfind.h"
#include <QSizePolicy>
#include <QLayout>
#include <QFormLayout>
#

JFind::JFind(QWidget *parent) : QWidget(parent)
{
	setup();
}

void JFind::setup()
{

//	label_corp = std::make_unique<QLabel>(new QLabel("corp:", this));
//	corp = std::make_unique<QLineEdit>(new QLineEdit());
//	corp->setMaximumWidth(100);
//	button = std::make_unique<QPushButton>(new QPushButton(this));
//	button->setMaximumWidth(100);
//	button->setText("Find or Add");
//	QFormLayout* layout = new QFormLayout;
	QHBoxLayout* corplayout = new QHBoxLayout;
	QLabel* l = new QLabel("corp:");
	corplayout->addWidget(l);
	corp = new QLineEdit;
	corplayout->addWidget(corp);
	QGridLayout* vlayout = new QGridLayout;
	vlayout->addItem(corplayout, 0, 0);
	button = new QPushButton("Find");
	QHBoxLayout* blayout = new QHBoxLayout;
	blayout->addWidget(button);
	vlayout->addItem(blayout,1, 0);
//	vlayout->addWidget(button.get());
	this->setLayout(vlayout);
	setMaximumHeight(100);
	setMaximumWidth(150);
//	label_corp->setBuddy(corp.get());
//	label_corp->setFixedWidth(100);
//	corp->setFixedWidth(150);
//	button->setFixedWidth(100);
//	layout->addRow("corp:", corp.get());
//	layout->addWidget(button.get());
//	this->seWidth(350);
//	this->setMinimumHeight(200);

//	corp->setSizePolicy(QSizePolicy::Fixed);
//	this->layout()->addWidget(corp);
}
