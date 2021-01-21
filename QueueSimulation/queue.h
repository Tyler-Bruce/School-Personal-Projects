#pragma once
#include "include.h"

int numItems = 0;    //Number of jobs currently in the queue.
int queueSize = 0;   //Size limit of the queue.
int jobsComplete = 0;   //Number of jobs completed by CPU
std::vector<Job> waitlist;    //Jobs are inserted here if the queue is full.

struct Node      //Node struct which contains jobs.
{
	Job job;
	Node* next;
};

struct Queue //Queue struct that contains two Node pointers
{
	Node* front = new Node();
	Node* rear = new Node();
};

Queue* q = new Queue(); //Create queue.

void SetQueueSize(int i)  //Sets the size of the queue.
{
	queueSize = i;
}

bool isFull()   //Check to see if the queue is full.

{
	bool status;
	if (numItems < queueSize)
		status = false;
	else status = true;
	return status;
}

bool isEmpty()     //Check to see if the queue is empty.
{
	bool status;
	if (numItems)
		status = false; 
	else
		status = true;
	return status;
}

void enqueue(Job num)    //Place job into queue.
{
		Node* newnode = new Node();
		newnode->job = num;
		newnode->next = nullptr;
		if (isEmpty())
		{
			q->front = newnode;
			q->rear = newnode;
			numItems++;
		}
		else if (isFull())
		{
			waitlist.push_back(num);
		}
		else 
		{
			if (!waitlist.empty())
			{
				newnode->job = waitlist.at(0);
				q->rear->next = newnode;
				q->rear = newnode;
				numItems++;
				return;
			}
			q->rear->next = newnode;
			q->rear = newnode;
			numItems++;
		}
}

void dequeue(Job num)     //Remove job from queue.
{
	if (isEmpty())
		std::cout << "Queue is empty";
	else
	{ 
		if (q->front == q->rear)
		{
			q->front = nullptr;
			q->rear = nullptr;
			num.status(true);
			numItems--; 
		}
		else
		{
			q->front = q->front->next;
			num.status(true);
			numItems--;
		} 
	}
}

Job getFront()   //Get the job at the front of the queue.
{
	return q->front->job;
}

int total_jobs()
{
	int i = jobsComplete + numItems + waitlist.size();
	return i;
}

int get_completed()
{
	int i = jobsComplete;
	return i;
}

int queue_size()
{
	int i = numItems;
	return i;
}

