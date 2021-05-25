#ifndef JFIND_H
#define JFIND_H


#include <QWidget>
#include <QLineEdit>
#include <memory>
#include <QLabel>
#include <QPushButton>
#include <QDialog>
#include "data/daocorp.h"
#include <QListView>

class JFind : public QDialog
{
	Q_OBJECT
public:
	static const int widtch = 300;
	static const int height = 200;
	explicit JFind(QWidget *parent = nullptr);
protected:
	std::unique_ptr<DaoCorp> dao;
	std::unique_ptr<QLineEdit> corp;
	std::unique_ptr<QPushButton> button;
	std::unique_ptr<QListView> corpList;
	void fillList();
	void setup();
private slots:
	void find();
signals:

};

#endif // JFIND_H
