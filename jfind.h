#ifndef JFIND_H
#define JFIND_H


#include <QWidget>
#include <QLineEdit>
#include <memory>
#include <QLabel>
#include <QPushButton>
#include <QDialog>

class JFind : public QDialog
{
	Q_OBJECT
public:
	static const int widtch = 200;
	static const int height = 100;
	explicit JFind(QWidget *parent = nullptr);
protected:
	std::unique_ptr<QLineEdit> corp;
	std::unique_ptr<QPushButton> button;
	void setup();
private slots:
	void find();
signals:

};

#endif // JFIND_H
