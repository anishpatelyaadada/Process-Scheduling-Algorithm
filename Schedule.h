#include <iostream>
#include<string>
using namespace std;
#pragma once
class Schedule
{
public:
	Schedule();
	struct ProcessData
	{
		string Process_Name;
		int Burst_Time;
		int I_O_Request;
		int Priority;
		struct ProcessData *next;
	};
	ProcessData *head;
	void read_data(string &, int &,int &,int &);
	void displayData();

	//round robin
	void round_robin();
	void delete_node(string &, int &, int &, int &);
	void displayRoundRobin();

	//shortest job first algorithm
	void bubble_sort();
	
	// Priority Scheduling
	void priority_scheduling(string [], int [], int [], int []);

	~Schedule();
};

