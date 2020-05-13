#pragma once
#include <string>
#include <iostream>
class Student
{
public:
	/*
	Student Class consisting of id, name gpa and major with basic getter and setter member functions.
	*/
	int id;
	std::string name;
	double gpa;
	std::string major;

	Student() = default;

	int get_ID()
	{
		return id;
	}

	std::string get_name()
	{
		return name;
	}

	double get_GPA()
	{
		return gpa;
	}

	std::string get_major()
	{
		return major;
	}

	void display()
	{
		std::cout << id << " " << name << " " << gpa << " " << major << std::endl;
	}

};
