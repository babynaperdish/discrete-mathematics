#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

class mySet
{
private:
	vector<vector<int>> grayUniversum; //sets
	vector<int> universum; 
	vector<int> firstSet;
	vector<int> secondSet;

	int universumPower = 0; //sets characteristics
	int firstSetPower = 0;
	int secondSetPower = 0;
	int setsPower = 0;
	int setsMultiplicity = 0;

	vector<vector<int>> grayAlgoritm(int);
	
	void setRandomInput(vector<int>&, vector<int>&, int&);
	void setManualInput(vector<int>&, int&);

	void setsUnion(vector<int>&, const vector<int>&, const vector<int>&);  //sets functions +
	void setsIntersection(vector<int>&, const vector<int>&, const vector<int>&);	//+
	void setsSubtraction(vector<int>&, const vector<int>, const vector<int>);	//+
	void setsSymmetricSubtraction(vector<int>&, const vector<int>, const vector<int>);	//+
	void setsComplement(vector<int>&, const vector<int>);		//+
	void setsArithmeticSum(vector<int>&, const vector<int>, const vector<int>);		//-
	void setsArithmeticSubtraction(vector<int>&, const vector<int>, const vector<int>);	//-
	void setsArithmeticMultiplication(vector<int>&, const vector<int>, const vector<int>); //-
	void setsArithmeticDivision(vector<int>&, const vector<int>, const vector<int>);  //-

	int correctInput();
	void clearBuffer();

public:
	mySet();
	void printOperations();
	void setOut(const vector<int>&);
};

