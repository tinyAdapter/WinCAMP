#include "mainwindow.h"
#include "hello.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	statusBar()->showMessage(Hello::getHelloWorldPrompt());
}
