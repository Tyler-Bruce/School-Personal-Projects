#pragma once
#include "include.h"

int total = 0;

//Job Class

class Job
{
public:
	int job_id = total;		//Job id; should equal total as total increments;
	int job_time = rand() % 10 + 1;	//job time random number between 1-10; added 1 to not have job time = 0;
	bool complete = false;	//See if the job is complete or not;


	Job() = default;		//Default constructor and destructor
	~Job() = default;

	bool operator < (const Job& j) const  //< operator override for std::sort to sort vector of jobs: BUG: vector not sorting properly
	{
		return (job_time > j.job_time);
	}

	 int getId()    
	{
		return job_id;
	}

	int getJTime()
	{
		return job_time;
	}

	bool isComplete()
	{
		return complete;
	}

	void status(const bool& b)
	{
		complete = b;
	}

	

};

Job createJob()      //Use this when creating new jobs, increments total after creation.
{
		Job j;
		total++;
		return j;
}

double randomDouble(double d1, double d2)      //Generates random doubles
{
	std::random_device device;
	std::mt19937 rng(device());
	std::uniform_real_distribution<> dist(d1, d2);
	return dist(rng);
}


