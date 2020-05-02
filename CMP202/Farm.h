#ifndef FARM_H
#define FARM_H

#include "task.h"
#include <queue>
#include <vector>
#include <mutex>
#include <thread>
#include <iostream>
#include <future>
#include <string>




/** A collection of tasks that should be performed in parallel. */
class Farm {
public:
	Farm(int threadcount);
	void add_task(Task* task);

	

	/** Run all the tasks in the farm.
		This method only returns once all the tasks in the farm
		have been completed. */
	void run(int& results);


	


	


private:
	std::queue<Task*> queue;
	std::vector<std::thread*> threads;
	bool tasks_done = false;
	std::mutex queue_mutex;
	std::mutex completion_mutex;

	int thread_count;

	void infinite_loop(int& results);


};

#endif

