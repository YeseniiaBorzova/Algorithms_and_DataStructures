#pragma once
#include<iostream>
#include<bitset>
#include<cmath>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

string errorBasicVar = "basic variable [0,1)!\n";
string errorLagA = "1 < Lag A < 256 \n";
string errorLagB = "1 < Lag B < Lag A \n";

class BitFrequency
{  
public:
	void setSize(int n) 
	{
		this->sizeOfarr = n;
	}

	void convertToBits(double sequen[]) 
	{
		string str;
		for (int i = 0; i < sizeOfarr; i++) 
		{
			arr[i].ld = sequen[i];
		}
		for (int i = 0; i < sizeOfarr; i++) 
		{
			bitset<64> bit(arr[i].uc);
			str = bit.to_string();
			binaryString.push_back(str);
		}
	}
	double findQuantityOf01(double sequen[])
	{
		string str;
		double sum = 0.0;
		for (int i = 0; i < sizeOfarr; i++)
		{
			arr[i].ld = sequen[i];
		}
		for (int i = 0; i < sizeOfarr; i++)
		{
			bitset<64> bit(arr[i].uc);
			str = bit.to_string();
			binaryString.push_back(str);
			quantityOf1 = bit.count();
			quantityOf0 = bit.size() - bit.count();
		}
		sum = quantityOf1 - quantityOf0;
		return abs(sum);
	}

	int lengOfstr(vector<string> binaryString)
	{
		return binaryString.size();
	}
	void test()
	{
		displayStr(binaryString); cout << endl;
	}
	int test2() 
	{
		int k = lengOfstr(binaryString);
		return k;
	}
	

private:
	int sizeOfarr,quantityOf1,quantityOf0;
	double sum = 0.0;
	vector<string> binaryString;
	union HelpUn					
	{
		double     ld;			
		unsigned long long uc;	
	};
	HelpUn arr[256];
	void displayStr(vector<string> binaryString)
	{
		for (int i = 0; i < binaryString.size(); i++)
		{
			cout << binaryString[i];
		}
	}

};
template<typename T>
void checkInput(T &var)
{
	while (!(cin >> var) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		printf("Invalid intup!\n");
		printf("Try again : ");
	}
}
bool checkConditions(bool condition, string error)
{
	if (!condition)
	{
		printf("%s", error.c_str());
		cin.clear();
		return false;
	}
	else
		return true;
}

double FibonacciGenerator(int a, int b, int k, double arr[])
{
	double x;
	if (arr[k - a] >= arr[k - b])
		x = arr[k - a] - arr[k - b];
	else if (arr[k - a] < arr[k - b])
		x = arr[k - a] - arr[k - b] + 1;
	return x;
}

double autocorrelation(double arr[], int i, int size)
{
	double pValue, pNum = 0, pDenum = 0;
	for (int k = 0; k < size; k++)
	{
		pNum += arr[k] * arr[(k + i) % size];
		pDenum += arr[k] * arr[k];
	}
	pValue = pNum / pDenum;
	return pValue;
}

double Randomize(double min, double max)
{
	double f = (double)rand()/ RAND_MAX;
	return min + f * (max - min);
}
/*	void convertToBits(double sequen[]) 
	{
		string str;
		for (int i = 0; i < sizeOfarr; i++) 
		{
			arr[i].ld = sequen[i];
		}
		for (int i = 0; i < sizeOfarr; i++) 
		{
			bitset<64> bit(arr[i].uc);
			str = bit.to_string();
			binaryString.push_back(str);
		}
	}*/
	/*double findQuantity(double sequen[])
	{
	int n;
	for (int i = 0; i < sizeOfarr; i++)
	{
	arr[i].ld = sequen[i];
	}
	for (int i = 0; i < sizeOfarr; i++)
	{
	bitset<64> bit(arr[i].uc);
	n = bit.size();
	}

	return n;
	}*/