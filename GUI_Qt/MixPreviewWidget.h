#ifndef MIXPREVIEWWIDGET_H
#define MIXPREVIEWWIDGET_H

/**
 Widget used to display a given mix to the user
 allows the user to play the selected mix
*/

#include <QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QPushButton>
#include <QtWidgets/QLabel>

#include "MusicPlayer.h"
#include "ImageDownloader.h"
#include "../Core/Mix.h"

using namespace tracksAPI;

class MixPreviewWidget : public QPushButton
{
	Q_OBJECT
public:
	MixPreviewWidget(Entities::Mix* mix, QObject* parent);
	~MixPreviewWidget();
private slots:
	void mix_Clicked();
private:
	QHBoxLayout* layout;
	QLabel* image;
	Entities::Mix* currentMix;
	QPixmap img;

	void setupWidget();
};

#endif