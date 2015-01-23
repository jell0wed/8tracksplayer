#include "ImageDownloader.h"


ImageDownloader::ImageDownloader(string url, QObject *parent = 0) : QObject(parent)
{
	this->finished = false;

	this->netManage = new QNetworkAccessManager();
	this->netManage->setConfiguration(this->netConfig.defaultConfiguration());

	// create the request
	QNetworkRequest* request = new QNetworkRequest(QUrl(QString(url.c_str())));
	// connect the finished signal
	connect(this->netManage, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));
	// process the request
	this->netManage->get(*request);
	// block thread until finished
	while(!this->finished) { QApplication::processEvents(); } // block thread until finished

	delete request;
}

ImageDownloader::~ImageDownloader()
{
	// image must be handled outside of the imagedownload class
	// (since its a utility class)
	// (will mostly be managed by qt)
	delete this->netManage;
}


bool ImageDownloader::isFinished() const
{
	return this->finished;
}

QPixmap ImageDownloader::getPixmap() const
{
	return this->image;
}

void ImageDownloader::downloadFinished(QNetworkReply* rep)
{
	this->finished = true;
	QByteArray arr = rep->readAll();

	this->image.loadFromData(arr);

	return;
}
