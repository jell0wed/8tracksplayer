#include "MixPreviewWidget.h"


MixPreviewWidget::MixPreviewWidget(Entities::Mix* mix, QObject* parent = 0) : QPushButton((QWidget*)parent)
{
	this->currentMix = mix;
	this->setupWidget();
	// settings in widget
	this->setMaximumWidth(250);
	this->setMinimumHeight(56);

	connect(this, SIGNAL(clicked()), this, SLOT(mix_Clicked()));
}

MixPreviewWidget::~MixPreviewWidget()
{
	
}

void MixPreviewWidget::setupWidget()
{
	this->layout = new QHBoxLayout;

	// set the label (image)
	QLabel* imgLabel = new QLabel;
	imgLabel->setScaledContents(false);
	imgLabel->setGeometry(0, 0, 56, 56);
	imgLabel->setMaximumSize(56, 56);

	// download the image
	ImageDownloader imgDownload(this->currentMix->getCovers()->find(AVATAR_TYPES::SQUARE_56)->second, this);
	this->img = imgDownload.getPixmap();
	imgLabel->setPixmap(this->img);

	// set the text
	QLabel* mixText = new QLabel;
	mixText->setWordWrap(true);
	mixText->setText(QString(this->currentMix->getName().c_str()));
	mixText->setAlignment(Qt::AlignLeft);

	// add the image to the layout
	this->layout->addWidget(imgLabel);
	this->layout->addWidget(mixText);

	this->setLayout(this->layout);
}

void MixPreviewWidget::mix_Clicked()
{
	MusicPlayer::getInstance()->playMix(this->currentMix);
}