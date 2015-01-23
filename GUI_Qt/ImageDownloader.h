#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H

/**
 class used to download pixmap (image) over the internet
*/

#include <QApplication>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkConfigurationManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPixMap>
#include <QByteArray>
#include <string>


using std::string;

class ImageDownloader : public QObject
{
	Q_OBJECT
public:
	ImageDownloader(string url, QObject *parent);
	~ImageDownloader();
	bool isFinished() const;
	QPixmap getPixmap() const;
public slots:
	void downloadFinished(QNetworkReply*);
private:
	QNetworkConfigurationManager netConfig;

	QNetworkAccessManager* netManage;
	QPixmap image;
	bool finished;
};

#endif