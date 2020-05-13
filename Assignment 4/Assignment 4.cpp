

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Student.h"


const int MAX_GROUP_SIZE = 40;    //Max group size with the 3 arrays of students
Student list1[MAX_GROUP_SIZE];
Student list2[MAX_GROUP_SIZE];
Student sorted[MAX_GROUP_SIZE];


Student create(std::string& s)      //Student factory
{
	Student stud;
	stud.id = std::stoi(s.substr(0, 4));
	stud.name = s.substr(5, 9);
	stud.gpa = std::stod(s.substr(14, 4));
	stud.major = s.substr(20, s.length());
	return stud;
}

void BubbleSort(Student s[])  //Bubble sort to sort arrays of Students.
{
	int i, j = 0;
	Student temp;
	for (i = 0; i < MAX_GROUP_SIZE; i++)
	{
		for (j = 0; j < (MAX_GROUP_SIZE - 1); j++)
		{
			if (s[j+1].get_ID() < s[j].get_ID() && s[j + 1].get_ID() > 0)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}

void Merge()
/*
	Primary function of program. Uses two files to input data into list1 and list2. 
	Both arrays are then sorted with the bubble sort method and then merge sorted into the final array.
*/
{
	std::ifstream studinfo1{ "C:/Users/Tyler/source/repos/Assignment 4/studinfo1.txt" };  //Input file 1
	std::ifstream studinfo2{ "C:/Users/Tyler/source/repos/Assignment 4/studinfo2.txt" };  //Input file 2
	std::string input;  //Strings to hold data of std::getline()
	std::string input2;
	Student new_stu;    
	Student new_stu2;
	int i = 0;
	int temp = 0;
	while (!studinfo1.eof())       //While file1 has not reached the end of file, list1 is filled from the data in file1.
	{
		if (!std::getline(studinfo1, input, '\n'))
		{
			break;
		}
		new_stu = create(input);
		list1[i] = new_stu;
		i++;
	}
	i = 0;
	while (!studinfo2.eof())    //Same as above, but for file 2.
	{
		if (!std::getline(studinfo2, input2, '\n'))
		{
			break;
		}
		new_stu2 = create(input2);
		list2[i] = new_stu2;
		i++;
	}
	BubbleSort(list1);     //List1 and list2 are both sorted to prepare for merge sort.
	i = 0;
	BubbleSort(list2);
	i = 0;                //Iterators for mergesort
	int j = 0;
	int k = 0;          
	while (k < MAX_GROUP_SIZE)  //Merge sorting by student ID#.
	{
		if (list1[i].get_ID() < list2[j].get_ID() && list1[i].get_ID() > 0)     //Compares the Ids of the first 2 students.
		{
			sorted[k] = list1[i];    //If list1's student is less then it gets pushed onto the sorted array first.
			i++;               //Look to the next object of list1.
		}
		else if (list2[j].get_ID() > 0)
		{
			sorted[k] = list2[j];
			j++;
		}
		k++;   //Prepare the next slot of the sorted array.
	}
}

int main()
{
	std::ofstream output{ "C:/Users/Tyler/source/repos/Assignment 4/output.txt" };  //Output File
	Merge();
	std::cout << "List 1 is: " << std::endl;
	for (int i = 0; i < MAX_GROUP_SIZE; i++)
	{
		if (list1[i].get_ID() > 0)
		{
			list1[i].display();
		}
		else
		{
			continue;
		}
 
	}
	std::cout << "\nList 2 is: " << std::endl;
	for (int i = 0; i < MAX_GROUP_SIZE; i++)
	{
		if (list2[i].get_ID() > 0)
		{
			list2[i].display();
		}
		else
		{
			continue;
		}
	}
	std::cout << "\nThe array sorted by student ID is: " << std::endl;
	for (int i = 0; i < MAX_GROUP_SIZE; i++)
	{
		if (sorted[i].get_ID() > 0)
		{
			sorted[i].display();
			output << sorted[i].id << " " << sorted[i].name << " " << sorted[i].gpa << " " << sorted[i].major << std::endl;
		}
		else
		{
			continue;
		}
	}
	return 0;
}
