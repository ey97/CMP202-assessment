#include "Farm.h"


Farm::Farm(int threadcount)
{
	thread_count = threadcount;
}

void Farm::add_task(Task* task)
{
	queue.push(task);

}

void Farm::run(int& results)
{
	



	for (int i = 0; i < thread_count; i++) {
		std::thread* t = new std::thread([&] {infinite_loop(results);});
		threads.push_back(t);
	}


	for (int i = 0; i < threads.size(); i++) {
		if (threads[i]->joinable())
		{
			threads[i]->join();
			



		}


	}

	for (int i = 0; i < threads.size(); i++) {
		delete threads[i];
	}



}

void Farm::infinite_loop(int& results) { // run needs to be passed a promise

	while (!queue.empty())
	{	
		queue_mutex.lock();
		auto temp = queue.front();
		queue.pop();
		queue_mutex.unlock();
		temp->run(results);
		delete temp;
	}

	return;
}