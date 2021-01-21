#pragma once
#include "include.h"

Clock timer;  //Initialize timer

void jobGenerator()
{
	double jobChance = randomDouble(0.0, 1.0); // generate random numbers
	while (jobChance < 0.75) //40% chance
	{
		Job new_job = createJob(); //Create jobs and enqueue
		enqueue(new_job);
		jobChance = randomDouble(0.0, 1.0);//Made the chance of generating a second job a little better.
	}
}