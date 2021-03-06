/*
Noah Fulton

The goal of this program is to have C open a file and
read the files numbers saving only the first two and
last two as well as counting up how many numbers are
in the list. The program will then output the numbers
collected.

*/


#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//define variables needed to complete analysis
	double firstNum = NULL;
	double secondNum = NULL;
	double nearlyLast = NULL;
	double lastNum = NULL;
	int count = 0;	
	string userInput;
	ifstream theFile;
	
	//request the file name
	cout << "What file do you want analyzed?";
	cin >> userInput;
	
	//see if finding the file name failed.
	if (cin.fail() == false)
	{
		//access the file
		theFile.open(userInput);
		//create a temporary number to hold the value
		double tempNum;
		//loop until the file is out of numbers to fill
		while (theFile >> tempNum)
		{
			//assign the first number
			if (count == 0)
			{
				firstNum = tempNum;
			}
			else if (count == 1) 
			{
				//assign the second number
				secondNum = tempNum;
			}
			//save the previous last number as the second to last
			nearlyLast = lastNum;
			//save the last number as the currently accessed value
			lastNum = tempNum;
			//add one to the total count
			count++;
		}
		//close the file accessed
		theFile.close();
		//print out the numbers that were first, last, and the count
		cout << "The Numbers are " << firstNum << ' ' << secondNum << " first and " << nearlyLast << ' ' << lastNum << " last with a total of " << count << " numbers.";
	}


}

