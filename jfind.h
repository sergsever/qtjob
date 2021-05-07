#ifndef JFIND_H
#define JFIND_H


#include <QWidget>
#include <QLineEdit>
#include <memory>
#include <QLabel>
#include <QPushButton>

class JFind : public QWidget
{
	Q_OBJECT
public:
	explicit JFind(QWidget *parent = nullptr);
protected:
	QLineEdit* corp;
	QPushButton* button;
	void setup();

signals:

};

#endif // JFIND_H
