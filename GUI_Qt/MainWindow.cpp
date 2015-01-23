#include "MainWindow.h"

#define WINDOW_WIDTH	1024
#define WINDOW_HEIGHT	600
#define TAG_MAX_ROW		10
#define HOT_MAX_ROW		4

MainWindow* MainWindow::instance = NULL;

MainWindow* MainWindow::getInstance(tracksAPI::I8tracksAPI* api, QWidget* parent)
{
	if(MainWindow::instance == NULL)
	{
		MainWindow::instance = new MainWindow(api, parent);
	}

	return MainWindow::instance;
}

void MainWindow::shutdown()
{
	if(MainWindow::instance != NULL)
	{
		delete MainWindow::instance;
	}
}

MainWindow::MainWindow(tracksAPI::I8tracksAPI* api, QWidget* parent = 0) : APIWindow<QMainWindow>(api, parent)
{
	// custom window modification
	QMainWindow::setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	QMainWindow::setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
	// end window modification

	this->setupThread(SLOT(asyncProcessInitStart()), SLOT(asyncProcessInitEnd()));
	this->ui.setupUi(this);

	this->exploreTags = NULL;
	this->hotMixes = NULL;
	this->mixesSearch = NULL;

	// connect currentlyplaying button
	connect(this->ui.actionEn_cours, SIGNAL(triggered()), this, SLOT(action_currentlyListenLaunch()));
	// connect explore button
	connect(this->ui.btnExplore, SIGNAL(clicked()), this, SLOT(action_searchFromTags()));
	// connect search term button
	connect(this->ui.btnSearch, SIGNAL(clicked()), this, SLOT(action_searchFromTerms()));
	// connect profile
	connect(this->ui.actionProfil, SIGNAL(triggered()), this, SLOT(profile_show()));
	// connect quit button
	connect(this->ui.actionQuitter, SIGNAL(triggered()), this, SLOT(exitApp()));

	this->currentUserProfile = new ProfileView(this->apiAccess, this);
	this->currentUserProfile->setUser(this->apiAccess->getLoggedInUser());
}

void MainWindow::show()
{
	this->emitStart();
	
	QMainWindow::show();
}

MainWindow::~MainWindow()
{
	// delete every explore tags
	I8tracksAPI::cleanupVector(this->exploreTags);
	// delete every hot mixes
	I8tracksAPI::cleanupVector(this->hotMixes);
	// delete every search mixes
	I8tracksAPI::cleanupVector(this->mixesSearch);
	// delete profile view
	if(this->currentUserProfile != NULL)
	{
		delete this->currentUserProfile;
	}
}


void MainWindow::asyncProcessInitStart()
{
	this->setLoading();
	//this->setEnabled(false);
	
	// render every tags in the explore section
	this->exploreTags = this->apiAccess->getTags();
	this->setupExploreTags();

	// render every hot mixes in the hot mix section
	this->hotMixes = this->apiAccess->searchMixes(NULL, MIX_SORT_HOT);
	this->setupHotMixes();

	this->emitFinished();
}

void MainWindow::asyncProcessInitEnd()
{
	this->endLoading();
}

void MainWindow::action_currentlyListenLaunch()
{
	CurrentlyListen::getInstance(this->apiAccess, NULL)->show();
}

void MainWindow::action_searchFromTags()
{
	this->searchMixes(this->selectedTags);
}

void MainWindow::action_searchFromTerms()
{
	string terms = this->ui.txtSearch->text().toUtf8().data();

	string sort = MIX_SORT_RECENT;
	if(this->ui.cmbOrder->currentText() == "Recent")
	{
		sort = MIX_SORT_RECENT;
	} else if(this->ui.cmbOrder->currentText() == "Popularity")
	{
		sort = MIX_SORT_POPULAR;
	} else if(this->ui.cmbOrder->currentText() == "Hot")
	{
		sort = MIX_SORT_HOT;
	}

	this->searchMixes(terms, sort);
}

void MainWindow::tags_addToCheckedList(bool checked)
{
	QPushButton* sender = (QPushButton*)QObject::sender();
	string tagValue = string(sender->text().toUtf8().data());
	if(checked)
	{
			
		if(this->selectedTags.size() >= 2)
		{
			QMessageBox::warning(this, "Error !", "You can select a maximum of 2 tags.", QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::NoButton);
			sender->setChecked(false);
		}
		else
		{
			this->selectedTags.push_back(tagValue);
		}
	}
	else
	{
		// remove from selected tags
		vector<string>::iterator itt = std::find(this->selectedTags.begin(), this->selectedTags.end(), tagValue);
		if(itt != this->selectedTags.end())
		{
			this->selectedTags.erase(itt);
		}
	}
}

void MainWindow::searchMixes(vector<string> selectedTags)
{
	if(this->mixesSearch != NULL) { I8tracksAPI::cleanupVector(this->mixesSearch); }

	// search mixes from tags
	if(selectedTags.size() > 0)
	{
		this->mixesSearch = this->apiAccess->searchMixes(selectedTags, 0, "", 0, 40);
		this->setupSearchMixes();
	}
	else
	{
		QMessageBox::warning(this, "Error !", "Please select at least one tag!", QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::NoButton);
	}
}

void MainWindow::searchMixes(string terms, string sort)
{
	if(this->mixesSearch != NULL) { I8tracksAPI::cleanupVector(this->mixesSearch); }

	// search mixes from terms
	if(terms != "")
	{
		this->mixesSearch = this->apiAccess->searchMixes(terms, 0, sort, 0, 0);
		this->setupSearchMixes();
	}
	else
	{
		QMessageBox::warning(this, "Error !", "Please, enter your search !", QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::NoButton);
	}
}

void MainWindow::setupExploreTags()
{
	// memory is managed automatically by Qt
	QGridLayout* exploreLayout = NULL;
	if(this->exploreTags != NULL)
	{
		exploreLayout = new QGridLayout();
		int row = 1;
		int col = 1;
		// add every tags into the explore grid layout
		vector<Entities::Tag*>::iterator itt = this->exploreTags->begin();
		for(itt; itt != this->exploreTags->end(); itt++)
		{
			QString btnStr = QString((*itt)->getName().c_str());
			QPushButton* btn = new QPushButton(btnStr);
			btn->setCheckable(true);
			exploreLayout->addWidget(btn, row, col, 1, 1, Qt::AlignCenter);

			connect(btn, SIGNAL(clicked(bool)), this, SLOT(tags_addToCheckedList(bool)));

			if(col % TAG_MAX_ROW == 0) {
				col = 1;
				row++;
			} else {
				col++;
			}
		}
		
		this->ui.widgExplore->setLayout(exploreLayout);
	}
}

void MainWindow::setupHotMixes()
{
	QGridLayout* hotLayout = NULL;
	if(this->hotMixes != NULL)
	{
		hotLayout = new QGridLayout();
		
		int row = 1;
		int col = 1;

		vector<Entities::Mix*>::iterator itt = this->hotMixes->begin();
		for(itt; itt != this->hotMixes->end(); itt++)
		{
			MixPreviewWidget* widgMix = new MixPreviewWidget(*itt, this);
			hotLayout->addWidget(widgMix, row, col, 1, 1);

			if(col % HOT_MAX_ROW == 0) {
				col = 1;
				row++;
			} else {
				col++;
			}
		}

		this->ui.widgHotMixes->setLayout(hotLayout);
	}
}

void MainWindow::setupSearchMixes()
{
	// clear layout from exisisting items
	QLayoutItem *item = NULL;
	while((item = this->ui.grdSearchMixes->takeAt(0)) != 0)
	{
		delete item->widget();
	}

	this->ui.tabMainWidget->setCurrentIndex(1);

	int row = 1;
	int col = 1;
	vector<Entities::Mix*>::iterator itt = this->mixesSearch->begin();
	for(itt; itt != this->mixesSearch->end(); itt++)
	{
		MixPreviewWidget* widgMix = new MixPreviewWidget(*itt, this);
		this->ui.grdSearchMixes->addWidget(widgMix, row, col, 1, 1);

		if(col % HOT_MAX_ROW == 0) {
			col = 1;
			row++;
		} else {
			col++;
		}
	}

}

void MainWindow::profile_show()
{
	this->currentUserProfile->show();	
}

void MainWindow::exitApp()
{
	this->close();
}