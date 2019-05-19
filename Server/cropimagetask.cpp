#include "cropimagetask.h"
#include "findpatterntask.h"

CropImageTask::CropImageTask(QVector<QVector<QPoint>> shapes, QPixmap pixmap)
	: QRunnable()
	, m_shapes(shapes)
	, m_image(pixmap.toImage())
{

}

CropImageTask::~CropImageTask()
{
}

void CropImageTask::run()
{
	cv::Mat src = qImage2mat(m_image);
	QVector<QPixmap> images;
	QVector<QByteArray> byteImages;

	for (const auto& shape : m_shapes)
	{
		int minX = 100000000;
		int maxX = -1;

		int minY = 100000000;
		int maxY = -1;

		for (const auto& point : shape)
		{
			if (point.x() < minX)
			{
				minX = point.x();
			}
			if (point.x() > maxX)
			{
				maxX = point.x();
			}

			if (point.y() < minY)
			{
				minY = point.y();
			}
			if (point.y() > maxY)
			{
				maxY = point.y();
			}
		}

		cv::Rect croppedArea(minX, minY, maxX - minX, maxY - minY);
		cv::Mat croppedImage = src(croppedArea);

		auto pixmap = QPixmap::fromImage(mat2qImage(croppedImage).rgbSwapped());

		QByteArray bArray;
		QBuffer buffer(&bArray);
		buffer.open(QIODevice::WriteOnly);
		pixmap.save(&buffer, "JPG");

		images.push_front(pixmap);
		byteImages.push_front(bArray);
	}

	emit result(images, byteImages);
}
