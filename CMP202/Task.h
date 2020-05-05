#ifndef TASK_H
#define TASK_H

#include <mutex>
/** Abstract base class: a task to be executed. */
class Task
{
protected:

	std::mutex results_lock;

public:
	virtual ~Task()
	{
	}

	/** Perform the task. Subclasses must override this. */
	//virtual void run() = 0;
	virtual void run(int& results) = 0;

};

#endif