#include "precompiled.h"
#include <iostream>
#include "jfind.h"
#include <QSizePolicy>
#include <QLayout>
#include <QFormLayout>
#include <QMessageBox>


JFind::JFind(QWidget *parent) : QDialog(parent)
{

	setup();
}

void JFind::setup()
{
		dao = std::make_unique<DaoCorp>();
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
	corp = std::make_unique<QLineEdit>(new QLineEdit);
	corplayout->addWidget(corp.get());
	QGridLayout* vlayout = new QGridLayout;
	vlayout->addItem(corplayout, 0, 0);
	button = std::make_unique<QPushButton>(new QPushButton);
	button->setText("Find");
	connect(button.get(), SIGNAL(released()), this, SLOT(find()));
	QHBoxLayout* blayout = new QHBoxLayout;
	blayout->addWidget(button.get());
	vlayout->addItem(blayout,1, 0);
//	vlayout->addWidget(button.get());
	this->setLayout(vlayout);
	setMaximumHeight(height);
	setMaximumWidth(widtch);
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
void JFind::find()
{
	std::cout << "Button" << std::endl;
	QMessageBox box;
	QString tofind = corp->text();
	auto found = dao->findByTitle(tofind);
	if (found.size() != 0 )
	{
	tofind += "count:" + found.size();
	}
	else
	{

		tofind = dao->getSqlError().text();
		if (tofind == "")
			tofind = corp->text();
		QDateTime dt = QDateTime::currentDateTime();
		qDebug() << "tofind: " << tofind << "dt: " << dt;
		if (tofind == corp->text())
		{
			Corp c;
			c.title = tofind;
			c.added = dt;
			c.result = "start";
			c.keywords = "begining";
			dao->add(c);
		}
	}
	box.setText(tofind);
	box.exec();
}
