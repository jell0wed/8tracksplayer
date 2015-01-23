#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 Main window of the application (singleton)
*/

#include <vector>
#include <algorithm>
#include <string>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QFrame>
#include <QMessageBox>
#include "ProfileView.h"
#include "APIWindow.h"
#include "ui_MainWindow.h"
#include "MixPreviewWidget.h"
#include "CurrentlyListen.h"

using std::vector;
using std::string;
using std::find;
using namespace tracksAPI;

class MainWindow : public APIWindow<QMainWindow>
{
	Q_OBJECT
public:
	static MainWindow* getInstance(tracksAPI::I8tracksAPI* api = 0, QWidget* parent = 0);
	static void shutdown();

	void MainWindow::searchMixes(vector<string> selectedTags);
	void MainWindow::searchMixes(string terms, string sort);
	void show();
public slots:
	void asyncProcessInitStart();
	void asyncProcessInitEnd();
private slots:
	void action_currentlyListenLaunch();
	void action_searchFromTags();
	void action_searchFromTerms();
	void tags_addToCheckedList(bool checked);
	void profile_show();
	void exitApp();
private:
	Ui::MainWindow ui;
	vector<tracksAPI::Entities::Tag*>* exploreTags;
	vector<tracksAPI::Entities::Mix*>* hotMixes;
	vector<tracksAPI::Entities::Mix*>* mixesSearch;
	vector<string> selectedTags;
	ProfileView* currentUserProfile;

	MainWindow(tracksAPI::I8tracksAPI* api, QWidget* parent);
	~MainWindow();

	// methods
	void setupExploreTags();
	void setupHotMixes();
	void setupSearchMixes();

	static MainWindow* instance;
};

#endif