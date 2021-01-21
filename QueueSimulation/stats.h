#pragma once
#include "include.h"


//Stats object to keep track of various projects. WIP
class Stats
{
public:
	int total_num_jobs = 0;
	int max_job_length = 0;
	int min_job_length = 0;
	int jobs_waitlisted = 0;
	int jobs_completed = 0;
	int queue_size = 0;
	std::ofstream output{ "C:/temp/output.json" };

	void results() //Display findings;
	{
		std::cout << "Max Job Length: " << max_job_length << std::endl;
		std::cout << "Min Job Length: " << min_job_length << std::endl;
		std::cout << "Total jobs(completed, in queue, and waitlisted): " << total_num_jobs << std::endl;  //Total jobs: BUG: Some jobs are being counted multiple times. 
		std::cout << "Jobs waitlisted: " << jobs_waitlisted << std::endl;								   //Will get wonky numbers occasionally.
		std::cout << "Jobs completed: " << jobs_completed << std::endl;
		std::cout << "Jobs still in queue: " << queue_size << std::endl;
	}

	void min_max()
	{
		std::sort(completed_jobs.begin(), completed_jobs.end()); // Sort completed_jobs std::vector<Job*>;
		max_job_length = completed_jobs.at(0).getJTime(); //After vector sorted, retrieve jobtime at index 0 of vector;
		min_job_length = completed_jobs.at(completed_jobs.size() - 1).getJTime(); //After vector sorted, retrieve jobtime at last index of vector;
		total_num_jobs = total_jobs(); //returns value from queue.h adding numItems + jobsComplete + waitlist.size()
		jobs_waitlisted = waitlist.size();  //Waitlist size
		jobs_completed = get_completed();   //jobs completed
	}
};
