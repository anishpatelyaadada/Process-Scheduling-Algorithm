#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"Schedule.h"
#include"RoundRobin.h"
#include"ShortestJobFirst.h"
#include"PriorityScheduling.h"

using namespace std;

int main() {
	Schedule send_data;
	RoundRobin Round_Robin;
	ShortestJobFirst Shortest_Job_First;
	PriorityScheduling Priority_Scheduling;

	ifstream inputFile;
	string Process_Kind;
	int End_Time;
	int Request_Number;
	int Rank;

	inputFile.open("C:\\Users\\kings\\Desktop\\Operating System\\Job Scheduleing\\readData.txt");

	if (inputFile.is_open()) {
		cout << "File Open Successfully\n";
		
		while (!inputFile.eof()) {
			inputFile >> Process_Kind >> End_Time >> Request_Number >> Rank;
			//cout << Process_Kind << " " << End_Time << " " << Request_Number << " " << Rank << endl;			
			send_data.read_data(Process_Kind, End_Time, Request_Number, Rank);
		}
	}
	else
		cout << "Error Opening File\n";


	cout << "Read Data Using Linked List and Display It.\n";
	send_data.displayData();
	cout << endl;
	cout << "Display data using roundrobin algo.\n";
	send_data.round_robin();



	//cout << "\nSorted List.\n";
	//send_data.bubble_sort();
	inputFile.close();
	system("pause");
	return 0;
	}