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

class Generator{
	private:
		std::vector<float> data;
		std::ofstream outfile ("data.csv");
		float min, max;
	public:
		Generator();
		Generator(float, float);
		vector<float> WriteFile(void);
}
Generator::Generator(float a, float b){
	min = a;
	max = b;
	int x = 0;
	for (int x=0;x<24;x++)
	{
		data.push_back(((float(rand()) / float(RAND_MAX)) * (max - min)) + min);
	}
	std::sort(data.begin(), data.end());
}
vector<float> Generator::WriteFile(){
	int x = 0;
	for(int x = 0; x < 24; x++){
		outfile << x << ", " << data[x] << "\n";
	}
}

int main()
{
	float min , max;
	vector<float> myData;
	cout << "Enter max number:\n";
	cin >> min;
	cout << "Enter min number:\n";
	cin >> max;
	cout << "\n";
	Generator* generator = new Generator(min, max);
]	myData = generator->WriteFile();
	// std::vector<float> data;
	int i =0;
	for(int i = 0; i < myData.size(); i++){
		cout << myData[i] << endl;
	}

	return 0;
}