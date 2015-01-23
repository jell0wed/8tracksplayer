#ifndef GUI_QT_H
#define GUI_QT_H

#include <QtWidgets/QMainWindow>
#include "ui_gui_qt.h"

class GUI_Qt : public QMainWindow
{
	Q_OBJECT

public:
	GUI_Qt(QWidget *parent = 0);
	~GUI_Qt();

private:
	Ui::GUI_QtClass ui;
};

#endif // GUI_QT_H
