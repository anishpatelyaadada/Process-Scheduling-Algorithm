#include "Schedule.h"
#include <iostream>
#include<string>
#include <Windows.h>
using namespace std;


Schedule::Schedule()
{
	head = nullptr;
}

void Schedule::read_data(string &Process_Title, int &End_Time, int &IO_Request, int &Rank) {
	ProcessData *newNode;
	ProcessData *traverse;
	newNode = new ProcessData;
	newNode->Process_Name = Process_Title;
	newNode->Burst_Time = End_Time;
	newNode->I_O_Request = IO_Request;
	newNode->Priority = Rank;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
	}
	else {
		traverse = head;
		while (traverse->next) {
			traverse = traverse->next;
		}
		traverse->next = newNode;
		traverse = head;
	}
}

void Schedule::displayData() {
	ProcessData *traverse;
	traverse = head;
	while (traverse->next)
	{
		cout << traverse->Process_Name << " " << traverse->Burst_Time << " " << traverse->I_O_Request << " " << traverse->Priority << endl;
		traverse = traverse->next;
	}

}

// round robin
void Schedule::round_robin() {
	ProcessData *traverse;

	bool exit = false;
	traverse = head;
	int j = 1, a = 1;
	
	while (traverse->next)
	{
		//cout << traverse->Process_Name << " " << traverse->Burst_Time << endl;

		for (int i = 0; i < 100; i++) {
			if (traverse->Burst_Time <= 0) {
				break;				
			}
			else {
				traverse->Burst_Time--;
			}
			// cout << "Burst time " << i + 1 << " = " << traverse->Burst_Time << endl;
			if (traverse->Burst_Time == 0 && traverse->Burst_Time <= 0)
			{
				cout << "This Processor out of list.\n";
				// delete_node(traverse->Process_Name, traverse->Burst_Time, traverse->I_O_Request, traverse->Priority);		
				cout << traverse->Process_Name << " " << traverse->Burst_Time << endl;
			}
			if (GetAsyncKeyState(VK_ESCAPE)) {
				exit = true;
			}
			if (exit == true) {
				cout << "a = " << a << endl;
				a++;
				if (a == 50) {
					break;
				}
			}
		}
		exit = false;
		a = 0;
		traverse = traverse->next;

		if (j == 250) {
			break;
		}
		else if (j % 10 == 0) {
			traverse = head;
		}
		j++;
	}
	displayRoundRobin();
	cout << endl;
	cout << "Data After Shortest Job first algorithm.\n";
	bubble_sort();
	
}

void Schedule::displayRoundRobin() {
	cout << "\nDisplay Round Robin Data.\n";
	ProcessData *traverse;
	traverse = head;
	while (traverse->next)
	{
		cout << traverse->Process_Name << " " << traverse->Burst_Time << " " << traverse->I_O_Request << " " << traverse->Priority << endl;
		traverse = traverse->next;
	}

}

// sorting and shortest job first algorithm
void Schedule::bubble_sort() {
	ProcessData *traverse;
	traverse = head;
	bool exit = false;
	string Process_Name_SJF[10], ProcessName;
	int Burst_Time_SJF[10], BurstTime;
	int I_O_Request_SJF[10], IORequest;
	int Priority_SJF[10], Priority;
   int a=0;

	while (traverse->next) {
		Process_Name_SJF[a] = traverse->Process_Name;
		Burst_Time_SJF[a] = traverse->Burst_Time;
		I_O_Request_SJF[a] = traverse->I_O_Request;
		Priority_SJF[a] = traverse->Priority;
		//cout << "A " << a + 1 << " = " << Process_Name_SJF[a] << " " << Burst_Time_SJF[a] << " " << I_O_Request_SJF[a] << " " << Priority_SJF[a] << endl;
		traverse = traverse->next;
		a++;
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (Burst_Time_SJF[j+1] < Burst_Time_SJF[j]) {
				ProcessName = Process_Name_SJF[j];
				BurstTime = Burst_Time_SJF[j];
				IORequest = I_O_Request_SJF[j];
				Priority = Priority_SJF[j];

				Process_Name_SJF[j] = Process_Name_SJF[j + 1];
				Burst_Time_SJF[j] = Burst_Time_SJF[j + 1];
				I_O_Request_SJF[j] = I_O_Request_SJF[j + 1];
				Priority_SJF[j] = Priority_SJF[j + 1];

				Process_Name_SJF[j + 1] = ProcessName;
				Burst_Time_SJF[j + 1] = BurstTime;
				I_O_Request_SJF[j + 1] = IORequest;
				Priority_SJF[j + 1] = Priority;
			}
		}
	}
	int b = 0,c=1;
	while (b < 6) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 50; k++) {

				//cout << "J " << j + 1 << " = " << Process_Name_SJF[j] << " " << Burst_Time_SJF[j] << " " << I_O_Request_SJF[j] << " " << Priority_SJF[j] << endl;

				if (Burst_Time_SJF[j] == 0) {
					break;
				}
				else {
					Burst_Time_SJF[j]--;
				}
				if (GetAsyncKeyState(VK_ESCAPE)) {
					exit = true;
				}
				if (exit == true) {
					cout << "c = " << c << endl;
					c++;
					if (c == 35) {
						break;
					}
				}
			}
		}
		b++;
	}
	
	for (int j = 0; j < 10; j++) {

		cout << "J " << j + 1 << " = " << Process_Name_SJF[j] << " " << Burst_Time_SJF[j] << " " << I_O_Request_SJF[j] << " " << Priority_SJF[j] << endl;
	}
	priority_scheduling(Process_Name_SJF, Burst_Time_SJF, I_O_Request_SJF, Priority_SJF);
}

//
void Schedule::priority_scheduling(string Process_Name_SJF[10], int Burst_Time_SJF[10], int I_O_Request_SJF[10], int Priority_SJF[10]) {
	string  ProcessName;
	int  BurstTime;
	int  IORequest;
	int Priority;
	bool exit = false;
	int c = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (Priority_SJF[j + 1] > Priority_SJF[j]) {
				ProcessName = Process_Name_SJF[j];
				BurstTime = Burst_Time_SJF[j];
				IORequest = I_O_Request_SJF[j];
				Priority = Priority_SJF[j];

				Process_Name_SJF[j] = Process_Name_SJF[j + 1];
				Burst_Time_SJF[j] = Burst_Time_SJF[j + 1];
				I_O_Request_SJF[j] = I_O_Request_SJF[j + 1];
				Priority_SJF[j] = Priority_SJF[j + 1];

				Process_Name_SJF[j + 1] = ProcessName;
				Burst_Time_SJF[j + 1] = BurstTime;
				I_O_Request_SJF[j + 1] = IORequest;
				Priority_SJF[j + 1] = Priority;
			}
		}
	}
	for (int j = 0; j < 10; j++) {

		//cout << "J " << j + 1 << " = " << Process_Name_SJF[j] << " " << Burst_Time_SJF[j] << " " << I_O_Request_SJF[j] << " " << Priority_SJF[j] << endl;

		while (Burst_Time_SJF[j] != 0) {
			if (Burst_Time_SJF[j] == 0) {
				break;
			}
			else {
				Burst_Time_SJF[j]--;
			}
			if (GetAsyncKeyState(VK_ESCAPE)) {
				exit = true;
			}
			if (exit == true) {
				cout << "c = " << c << endl;
				if (c == 1) {
					break;
				}
			}
		}
	}
	cout << "\nData After Priority Scheduling algorithm.\n";
	for (int j = 0; j < 10; j++) {

		cout << "J " << j + 1 << " = " << Process_Name_SJF[j] << " " << Burst_Time_SJF[j] << " " << I_O_Request_SJF[j] << " " << Priority_SJF[j] << endl;
	}
}

void Schedule::delete_node(string &Process_Title, int &End_Time, int &IO_Request, int &Rank) {
	ProcessData *nodePtr;
	ProcessData *previoudNode;
	nodePtr = new ProcessData;
	previoudNode = new ProcessData;
	/*nodePtr->Process_Name = Process_Title;
	nodePtr->Burst_Time = End_Time;
	nodePtr->I_O_Request = IO_Request;
	nodePtr->Priority = Rank;*/


	if (!head)
		return;

	if(head->Priority == Rank)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->Priority != Rank) {
			previoudNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr) {
			previoudNode->next = nodePtr->next;
			delete nodePtr;
		}
	}

}

Schedule::~Schedule()
{
}
