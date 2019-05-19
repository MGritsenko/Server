#include "task.h"

#include <QPixmap>
#include <QBuffer>

SendColorsTask::SendColorsTask(int width, int height, int color, bool isColor)
	: QRunnable()
	, m_width(width)
	, m_height(height)
	, m_isColor(isColor)
	, m_color(static_cast<Colors>(color))

{
	m_colors[Colors::BLACK] = cv::Scalar(0, 0, 0);
	m_colors[Colors::BLUE] = cv::Scalar(0, 130, 200);
	m_colors[Colors::BROWN] = cv::Scalar(170, 110, 40);
	m_colors[Colors::CYAN] = cv::Scalar(70, 240, 240);
	m_colors[Colors::GREEN] = cv::Scalar(0, 255, 0);
	m_colors[Colors::GREY] = cv::Scalar(128, 128, 128);
	m_colors[Colors::MAGENTA] = cv::Scalar(240, 50, 230);
	m_colors[Colors::MAROON] = cv::Scalar(128, 0, 0);
	m_colors[Colors::NAVY] = cv::Scalar(0, 0, 128);
	m_colors[Colors::ORANGE] = cv::Scalar(245, 130, 48);
	m_colors[Colors::PURPLE] = cv::Scalar(145, 30, 180);
	m_colors[Colors::RED] = cv::Scalar(230, 25, 75);
	m_colors[Colors::TEAL] = cv::Scalar(0, 128, 128);
	m_colors[Colors::WHITE] = cv::Scalar(255, 255, 255);
	m_colors[Colors::YELLOW] = cv::Scalar(255, 255, 25);
}

SendColorsTask::~SendColorsTask()
{}

void SendColorsTask::run()
{
	if (m_isColor)
	{
		generateColor();
	}
	else
	{
		generateRect();
	}
}

void SendColorsTask::generateRect()
{
	cv::Mat img1(m_height, m_width, CV_8UC3, cv::Scalar(255, 0, 0));
	cv::rectangle
	(
		img1
		, cv::Point(0, 0)
		, cv::Point(m_width / 2, m_height)
		, cv::Scalar(0, 255, 0)
		, cv::LineTypes::FILLED
	);

	QImage img(img1.data, img1.cols, img1.rows, QImage::Format::Format_RGB888);
	auto pixmap = QPixmap::fromImage(img);
	QByteArray bArray;
	QBuffer buffer(&bArray);
	buffer.open(QIODevice::WriteOnly);
	pixmap.save(&buffer, "JPG");

	emit result(bArray);
}

void SendColorsTask::generateColor()
{
	cv::Mat img1(m_height, m_width, CV_8UC3, m_colors.value(m_color, cv::Scalar(0, 0, 0)));

	QImage img(img1.data, img1.cols, img1.rows, QImage::Format::Format_RGB888);
	auto pixmap = QPixmap::fromImage(img);
	QByteArray bArray;
	QBuffer buffer(&bArray);
	buffer.open(QIODevice::WriteOnly);
	pixmap.save(&buffer, "JPG");

	emit result(bArray);
}
