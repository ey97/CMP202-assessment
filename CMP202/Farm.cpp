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
		std::thread* t = new std::thread([&] {infinite_loop(results);}); //create thread and run function
		threads.push_back(t);
	}


	for (int i = 0; i < threads.size(); i++) {
			threads[i]->join();
	}

	for (int i = 0; i < threads.size(); i++) {
		delete threads[i];
	}



}

void Farm::infinite_loop(int& results) {
	
	
	while (!queue.empty())
	{	
		queue_mutex.lock();
		if (queue.empty()) {
			queue_mutex.unlock();
			return;
		}
		auto temp = queue.front();
		
		queue.pop();
		queue_mutex.unlock();
		temp->run(results); //memory violation here when running hgh numbers of instances of the test, smaller numbers work fine // variables being reused upon re-entry of function? FIX ME //
		
	}

	return;
}