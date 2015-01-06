/****************************************************************************************************************************************************
 *  File Name   		: nutsblotsproblem.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\nutsblotsproblem.h
 *  Created on			: Jan 5, 2015 :: 10:26:12 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/nuts-bolts-problem-lock-key-problem/
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef NUTSBLOTSPROBLEM_H_
#define NUTSBLOTSPROBLEM_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int nabpDivideStep(vector<char> &userInput,char key,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return INT_MIN;
	}
	int initStartIndex = startIndex;
	while(startIndex < endIndex){
		while(userInput[startIndex] <= key){
			if(userInput[startIndex] == key){
				swap(userInput[initStartIndex],userInput[startIndex]);
			}
			startIndex++;
		}
		while(userInput[endIndex] > key){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	swap(userInput[initStartIndex],userInput[endIndex]);
	return endIndex;
}

//Tested
void nutsAndBoltsSortingMain(vector<char> &nuts,vector<char> &bolts,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int pivotIndex = nabpDivideStep(nuts,bolts[endIndex],startIndex,endIndex);
	nabpDivideStep(bolts,nuts[pivotIndex],startIndex,endIndex);
	nutsAndBoltsSortingMain(nuts,bolts,startIndex,pivotIndex-1);
	nutsAndBoltsSortingMain(nuts,bolts,pivotIndex+1,endIndex);
}

//Tested
void nutsAndBlotsProblem(vector<char> &nuts,vector<char> &bolts){
	if(nuts.size() < 2){
		return;
	}
	nutsAndBoltsSortingMain(nuts,bolts,0,nuts.size()-1);
}

#endif /* NUTSBLOTSPROBLEM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
