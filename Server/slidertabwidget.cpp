#include "slidertabwidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

SliderTabWidget::SliderTabWidget(QWidget *parent)
	: QWidget(parent)
{
	m_toBlueLabel = new QLabel("B", this);
	m_toGreenLabel = new QLabel("G", this);
	m_toRedLabel = new QLabel("R", this);

	m_fromBlueLabel = new QLabel("B", this);
	m_fromGreenLabel = new QLabel("G", this);
	m_fromRedLabel = new QLabel("R", this);

	m_toBlueLabelVal = new QLabel(this);
	m_toGreenLabelVal = new QLabel(this);
	m_toRedLabelVal = new QLabel(this);

	m_fromBlueLabelVal = new QLabel(this);
	m_fromGreenLabelVal = new QLabel(this);
	m_fromRedLabelVal = new QLabel(this);

	//--------------------------------------

	m_toBlueSlider = new QSlider(Qt::Orientation::Horizontal, this);
	m_toGreenSlider = new QSlider(Qt::Orientation::Horizontal, this);
	m_toRedSlider = new QSlider(Qt::Orientation::Horizontal, this);

	m_fromBlueSlider = new QSlider(Qt::Orientation::Horizontal, this);
	m_fromGreenSlider = new QSlider(Qt::Orientation::Horizontal, this);
	m_fromRedSlider = new QSlider(Qt::Orientation::Horizontal, this);

	m_toBlueSlider->setRange(0, 255);
	m_toGreenSlider->setRange(0, 255);
	m_toRedSlider->setRange(0, 255);
	m_fromBlueSlider->setRange(0, 255);
	m_fromGreenSlider->setRange(0, 255);
	m_fromRedSlider->setRange(0, 255);

	m_fromColor = new QWidget(this);
	m_toColor = new QWidget(this);

	m_fromColor->setAutoFillBackground(true);
	m_toColor->setAutoFillBackground(true);


	connect(m_toBlueSlider, &QSlider::valueChanged, this, 
		[&](int val)
	{
		m_toBlueLabelVal->setText(QString::number(val));
	});

	connect(m_toGreenSlider, &QSlider::valueChanged, this,
		[&](int val)
	{
		m_toGreenLabelVal->setText(QString::number(val));
	});

	connect(m_toRedSlider, &QSlider::valueChanged, this,
		[&](int val)
	{
		m_toRedLabelVal->setText(QString::number(val));
	});

	connect(m_fromBlueSlider, &QSlider::valueChanged, this,
		[&](int val)
	{
		m_fromBlueLabelVal->setText(QString::number(val));
	});

	connect(m_fromGreenSlider, &QSlider::valueChanged, this,
		[&](int val)
	{
		m_fromGreenLabelVal->setText(QString::number(val));
	});

	connect(m_fromRedSlider, &QSlider::valueChanged, this,
		[&](int val)
	{
		m_fromRedLabelVal->setText(QString::number(val));
	});

	QHBoxLayout* rL = new QHBoxLayout;
	QHBoxLayout* gL = new QHBoxLayout;
	QHBoxLayout* bL = new QHBoxLayout;

	rL->addWidget(m_fromRedLabel);
	rL->addWidget(m_fromRedLabelVal);
	rL->addWidget(m_fromRedSlider);
	gL->addWidget(m_fromGreenLabel);
	gL->addWidget(m_fromGreenLabelVal);
	gL->addWidget(m_fromGreenSlider);
	bL->addWidget(m_fromBlueLabel);
	bL->addWidget(m_fromBlueLabelVal);
	bL->addWidget(m_fromBlueSlider);

	QHBoxLayout* rLT = new QHBoxLayout;
	QHBoxLayout* gLT = new QHBoxLayout;
	QHBoxLayout* bLT = new QHBoxLayout;

	rLT->addWidget(m_toRedLabel);
	rLT->addWidget(m_toRedLabelVal);
	rLT->addWidget(m_toRedSlider);
	gLT->addWidget(m_toGreenLabel);
	gLT->addWidget(m_toGreenLabelVal);
	gLT->addWidget(m_toGreenSlider);
	bLT->addWidget(m_toBlueLabel);
	bLT->addWidget(m_toBlueLabelVal);
	bLT->addWidget(m_toBlueSlider);

	QVBoxLayout* vl = new QVBoxLayout;
	//vl->addWidget(m_fromColor);
	vl->addLayout(rL);
	vl->addLayout(bL);
	vl->addLayout(gL);
	//vl->addWidget(m_toColor);
	vl->addLayout(rLT);
	vl->addLayout(bLT);
	vl->addLayout(gLT);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(vl);
	mainLayout->addStretch(1);
	setLayout(mainLayout);
}

SliderTabWidget::~SliderTabWidget()
{
}

QColor SliderTabWidget::getFromColor() const
{
	auto c = QColor(m_fromBlueSlider->value(), m_fromGreenSlider->value(), m_fromRedSlider->value());
	QPalette p(c);
	m_fromColor->setPalette(p);

	return c;
}

QColor SliderTabWidget::getToColor() const
{
	auto c = QColor(m_toBlueSlider->value(), m_toGreenSlider->value(), m_toRedSlider->value());
	QPalette p(c);
	m_toColor->setPalette(p);

	return c;
}
