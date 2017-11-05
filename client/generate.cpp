
#include<stdio.h>
// #include "stdafx.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


std::vector<float> data;

void RandomData(float Min, float Max)
{
	int x = 0;
	for (int x=0;x<24;x++)
	{
    data.push_back(((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min);
	}
	std::sort(data.begin(), data.end());
}

int main()
{
	std::ofstream outfile ("data.csv");

	float min , max;
	cout << "Enter max number:\n";
	cin >> min;
	cout << "Enter min number:\n";
	cin >> max;
	cout << "\n";
	RandomData(min, max);
	int x = 0;
	for(int x = 0; x < 24; x++){
		outfile << x << ", " << data[x] << "\n";
	}
	// std::vector<float> data;
	int i =0;
	for(int i = 0; i < data.size(); i++){
		cout << data[i] << endl;
	}

	return 0;
}