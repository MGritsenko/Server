#pragma once

#include <QRunnable>
#include <QObject>
#include <QMap>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

enum class Colors
{
	RED,
	GREEN,
	BLUE,
	YELLOW,
	ORANGE,
	PURPLE,
	CYAN,
	MAGENTA,
	TEAL,
	BROWN,
	MAROON,
	NAVY,
	GREY,
	WHITE,
	BLACK
};

class Task : public QObject, public QRunnable
{
	Q_OBJECT

public:
	Task(int width, int height, int color, bool isColor = true);
	~Task();

signals:
	void result(QByteArray data);

protected:
	virtual void run() override;

private:
	void generateRect();
	void generateColor();

private:
	int m_width;
	int m_height;
	bool m_isColor;
	Colors m_color;

	QMap<Colors, cv::Scalar> m_colors;
};