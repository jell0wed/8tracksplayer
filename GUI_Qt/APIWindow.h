#ifndef APIWINDOW_H
#define APIWINDOW_H

/**
 Class that represents a multithreaded window used by many windows and object in the application
*/

#include "../Core/I8tracksAPI.h"
#include <QApplication>
#include <QtWidgets/QWidget>
#include <QtCore/QObject>
#include <QtCore/QThread>
#include <QtCore/QString>
#include <QFrame>
#include <boost/utility/enable_if.hpp>

template <class T>
class APIWindow : public T
{
public:
	APIWindow(tracksAPI::I8tracksAPI*, QWidget*);
	~APIWindow();
protected:
	void emitStart();
	void emitFinished();
	void setupThread(const char* startSlot, const char* endSlot);
	
	virtual inline void setLoading();
	virtual inline void endLoading();
protected slots:
	// init process thread process function
	virtual void asyncProcessInitStart() {  };
	// init process thread process end function
	virtual void asyncProcessInitEnd() {  };
protected:
	QThread* currentThread;
	tracksAPI::I8tracksAPI* apiAccess;
};

#include "APIWindow.hpp"

#endif