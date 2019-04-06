#include "task.h"

Task::Task(): QRunnable()
{
}

Task::~Task()
{
}

void Task::run()
{
	int number = 0;

	for (int i = 0; i < 100; i++)
	{
		number = i;
	}

	emit result(number);
}
