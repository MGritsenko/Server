#include "cropimagetask.h"
#include "findpatterntask.h"

CropImageTask::CropImageTask(QMap<QString, QVector<QPoint>> shapes, QPixmap pixmap)
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
	QVector<QPair<QPixmap, QString>> images;
	QVector<QPair<QByteArray, QString>> byteImages;

	for (const auto& key : m_shapes.keys())
	{
		int minX = 100000000;
		int maxX = -1;

		int minY = 100000000;
		int maxY = -1;

		for (const auto& point : m_shapes.value(key))
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

		if (maxY - minY < maxX - minX)
		{
			cv::rotate(croppedImage, croppedImage, cv::ROTATE_90_CLOCKWISE);
		}

		auto pixmap = QPixmap::fromImage(mat2qImage(croppedImage).rgbSwapped());

		QByteArray bArray;
		QBuffer buffer(&bArray);
		buffer.open(QIODevice::WriteOnly);
		pixmap.save(&buffer, "JPG");

		images.push_front(qMakePair(pixmap, key));
		byteImages.push_front(qMakePair(bArray, key));
	}

	emit result(images, byteImages);
}
