template <class T>
APIWindow<T>::APIWindow(tracksAPI::I8tracksAPI* api, QWidget* parent) : T(parent)
{
	this->apiAccess = api;
	this->currentThread = new QThread;
}

template <class T>
APIWindow<T>::~APIWindow()
{
	delete this->currentThread;
}


template <class T>
void APIWindow<T>::emitStart()
{
	this->currentThread->start();
}

template <class T>
void APIWindow<T>::emitFinished()
{
	this->currentThread->exit();
}

template <class T>
void APIWindow<T>::setupThread(const char* startSlot = "", const char* endSlot = "")
{
	if(startSlot == "" && endSlot == "")
	{
		startSlot = SLOT(asyncProcessInitStart());
		endSlot = SLOT(asyncProcessInitEnd());
	}

	if(this->currentThread != NULL && !this->currentThread->isRunning())
	{
		// reset current thread
		delete this->currentThread;
		this->currentThread = new QThread;

		this->moveToThread(this->currentThread);
		//connect(this->currentThread, SIGNAL(error(QString)), this, SLOT(handleError(QString)));
		connect(this->currentThread, SIGNAL(started()), this, startSlot);
		connect(this->currentThread, SIGNAL(finished()), this, endSlot);
	}
}

template<class T>
void APIWindow<T>::setLoading()
{
	// set action to do on loading
}

template<class T>
void APIWindow<T>::endLoading()
{
	// set action to do when loading ends
}

