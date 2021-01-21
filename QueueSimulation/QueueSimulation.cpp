#include "include.h"
//TODO:
/* Calculate the following information about the queue: 
1.	Maximum queue length and the time that the queue was at its maximum length
2.	Total and average wait time inside the queue for all jobs.
3.	Total number of jobs waited in the queue.
4.	Percentage of jobs that had to wait in the queue as it relates to the total number of jobs served by the system.*/
//TODO:


int main()
{
	srand(time(NULL));
	Stats s;
	int c;
	std::cout << "Please enter queue size: \n";
	std::cin >> c;
	SetQueueSize(c);
	while (timer.start < 600)
	{
		work();
		timer.start++;
	}
	s.min_max();
	s.results();
	s.output << "Results with queue size: " << c;
	return 0;
}
