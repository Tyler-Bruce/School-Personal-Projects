#pragma once
#include "include.h"

int COUNT = 1;
std::vector<Job> completed_jobs;

class CPU
{
private:
	int cpu_id = COUNT;
	bool running = false;
	Job current;
	int time;
	int busy_time = 0;
	int idle_time = 0;
	bool hasJob = false;
	int finished = 0;

public:
	CPU() = default;
	~CPU() = default;

	Job getCurrentJob()
	{
		return current;
	}

	void setId(int& i)
	{
		cpu_id = i;
	}

	void setStatus(bool b)
	{
		hasJob = b;
	}

	int getId()
	{
		return cpu_id;
	}

	bool getStatus()
	{
		return hasJob;
	}

	bool isRunning()
	{
		return running;
	}
	void jobStatus(const bool& b)
	{
		hasJob = b;
	}
	void begin()
	{
		running = true;
		setCurrentJob(getFront());
		jobStatus(true);
	}
	int jobsWorked()
	{
		return finished;
	}
	void setCurrentJob(Job j)
	{
		current = j;
		dequeue(current);
	}

	void process()
	{
		if (hasJob)
		{
			running = true;
			busy_time++;
			time--;
		}
		if (time <= 0)
		{
			running = false;
			jobStatus(false);
			jobsComplete++;
			completed_jobs.push_back(current);
			idle_time++;
			finished++;
		}
	}
};

CPU CPUcreate()
{
	CPU cpu;
	COUNT++;
	return cpu;
}

CPU cpus[4];

CPU NextCPU()
{
	for (CPU& c : cpus)
	{
		c = CPUcreate();
		if (!c.getStatus())
			return c;
	}
}
