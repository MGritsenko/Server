#include "task.h"

#include <QRandomGenerator>

Task::Task(): QRunnable()
{
}

Task::~Task()
{
}

void Task::run()
{
	auto value = static_cast<int>(QRandomGenerator::global()->generate());

	emit result(value);
}
