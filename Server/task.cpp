#include "task.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <QPixmap>
#include <QBuffer>

Task::Task(int width, int height)
	: QRunnable()
	, m_width(width)
	, m_height(height)
{}

Task::~Task()
{}

void Task::run()
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
