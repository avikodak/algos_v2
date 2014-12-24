/****************************************************************************************************************************************************
 *  File Name   		: commonds.h 
 *	File Location		: D:\algos\algos_v2\src\lib\ds\commonds.h
 *  Created on			: Oct 9, 2014 :: 12:38:37 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef COMMONDS_H_
#define COMMONDS_H_

struct iPair{
	int firstValue;
	int secondValue;

	iPair(){

	}

	iPair(int firstValue,int secondValue){
		this->firstValue = firstValue;
		this->secondValue = secondValue;
	}
};

struct iTriplet{
	int firstValue;
	int secondValue;
	int thirdValue;

	iTriplet(){

	}

	iTriplet(int firstValue,int secondValue,int thirdValue){
		this->firstValue = firstValue;
		this->secondValue = secondValue;
		this->thirdValue = thirdValue;
	}
};

struct iFrequency{
	int value;
	unsigned int frequency;

	iFrequency(){

	}

	iFrequency(int value){
		this->value = value;
		this->frequency = 1;
	}

	iFrequency(int value,unsigned int frequency){
		this->value = value;
		this->frequency = frequency;
	}
};

struct iPairVector{
	vector<int> firstVector;
	vector<int> secondVector;

	iPairVector(){

	}

	iPairVector(vector<int> firstVector){
		this->firstVector = firstVector;
	}

	iPairVector(vector<int> firstVector,vector<int> secondVector){
		this->firstVector = firstVector;
		this->secondVector = secondVector;
	}
};

struct iMaxMin{
	int maxValue;
	int minValue;

	iMaxMin(){
		this->maxValue = INT_MIN;
		this->minValue = INT_MAX;
	}

	iMaxMin(int minValue,int maxValue){
		this->minValue = minValue;
		this->maxValue = maxValue;
	}
};

struct floorceiling{
	int floor;
	int ceiling;

	floorceiling(){

	}

	floorceiling(int floor,int ceiling){
		this->floor = floor;
		this->ceiling = ceiling;
	}
};

struct iQuadruple{
	int firstValue;
	int secondValue;
	int thirdValue;
	int fourthValue;

	iQuadruple(){
		this->firstValue = INT_MAX;
		this->secondValue = INT_MAX;
		this->thirdValue = INT_MAX;
		this->fourthValue = INT_MAX;
	}

	iQuadruple(int firstValue,int secondValue,int thirdValue,int fourthValue){
		this->firstValue = firstValue;
		this->secondValue = secondValue;
		this->thirdValue = thirdValue;
		this->fourthValue = fourthValue;
	}
};

struct iValueIndex{
	int value;
	unsigned int firstValueIndex;
	unsigned int secondvalueIndex;

	iValueIndex(){

	}

	iValueIndex(int value,unsigned int firstIndex,unsigned int secondIndex){
		this->value = value;
		this->firstValueIndex = firstIndex;
		this->secondvalueIndex = secondIndex;
	}

};

struct matrixsize{
	int rows;
	int columns;

	matrixsize(){
		this->rows = 0;
		this->columns = 0;
	}

	matrixsize(int rows,int columns){
		this->rows = rows;
		this->columns = columns;
	}
};

struct iInterval{
	int start;
	int end;

	iInterval(){

	}

	iInterval(int start,int end){
		this->start = start;
		this->end = end;
	}
};

struct rowColumn{
	int row;
	int column;

	rowColumn(){
		this->row = INT_MAX;
		this->column = INT_MAX;
	}

	rowColumn(int row,int column){
		this->row = row;
		this->column = column;
	}
};

struct iRowColumn{
	int value;
	int row;
	int column;

	iRowColumn(){
		this->value = INT_MIN;
		this->row = INT_MAX;
		this->column = INT_MAX;
	}

	iRowColumn(int value,int row,int column){
		this->value = value;
		this->row = row;
		this->column = column;
	}
};

#endif /* COMMONDS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

