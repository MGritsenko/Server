#pragma once

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QColor>

class SliderTabWidget : public QWidget
{
	Q_OBJECT

public:
	SliderTabWidget(QWidget *parent, const QVector<int>& values);
	~SliderTabWidget();
	
	QColor getFromColor() const;
	QColor getToColor() const;

private:
	QLabel* m_toRedLabel;
	QLabel* m_toGreenLabel;
	QLabel* m_toBlueLabel;

	QLabel* m_fromRedLabel;
	QLabel* m_fromGreenLabel;
	QLabel* m_fromBlueLabel;

	QLabel* m_toRedLabelVal;
	QLabel* m_toGreenLabelVal;
	QLabel* m_toBlueLabelVal;

	QLabel* m_fromRedLabelVal;
	QLabel* m_fromGreenLabelVal;
	QLabel* m_fromBlueLabelVal;

	QSlider* m_toRedSlider;
	QSlider* m_toGreenSlider;
	QSlider* m_toBlueSlider;

	QSlider* m_fromRedSlider;
	QSlider* m_fromGreenSlider;
	QSlider* m_fromBlueSlider;

	QWidget* m_fromColor;
	QWidget* m_toColor;
};