#pragma once
#include "include.h"
//Create CPU object. 
CPU cpu;

//Main engine of program
void work()
{
	jobGenerator();    //Generates new jobs
	if (!cpu.isRunning() && !cpu.getStatus() && !isEmpty()) 
	{
		cpu.begin();   //Boot CPU and load first job
	};  
	while (cpu.isRunning() && cpu.getStatus()) //Process jobs while CPU is running and has a job.
	{
		cpu.process();
	}
}