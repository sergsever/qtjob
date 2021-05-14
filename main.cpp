#include "mainwindow.h"
#include "jfind.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
//	MainWindow w;
	JFind jfind;

	jfind.show();
	return a.exec();
}
