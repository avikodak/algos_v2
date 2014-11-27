/****************************************************************************************************************************************************
 *  File Name   		: leadersofarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\leadersofarray.h
 *  Created on			: Nov 25, 2014 :: 12:03:29 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/leaders-in-an-array/
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
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

#ifndef LEADERSOFARRAY_H_
#define LEADERSOFARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printLeadersInArray(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	int maxTillNow = INT_MIN;
	for(int counter = userInput.size()-1;counter >= 0;counter--){
		if(userInput[counter] > maxTillNow){
			printf("%d\t",userInput[counter]);
			maxTillNow = userInput[counter];
		}
	}
}

//Tested
int printLeaders(vector<int> userInput,unsigned int counter = 0){
	if(counter >= userInput.size()){
		return INT_MIN;
	}
	int resultTillNow = printLeaders(userInput,counter+1);
	if(userInput[counter] > resultTillNow){
		printf("%d\t",userInput[counter]);
		resultTillNow = userInput[counter];
	}
	return resultTillNow;
}

//Tested
void printLeadersAuxSpace(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	stack<int> auxSpace;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		auxSpace.push(userInput[counter]);
	}
	int maxTillNow = INT_MIN;
	while(!auxSpace.empty()){
		if(auxSpace.top() > maxTillNow){
			printf("%d\t",auxSpace.top());
			maxTillNow = auxSpace.top();
		}
		auxSpace.pop();
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printLeadersInArrayON2(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	bool isLeader;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		isLeader = true;
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(userInput[innerCounter] > userInput[outerCounter]){
				isLeader = false;
			}
		}
		if(isLeader){
			printf("%d\t",userInput[outerCounter]);
		}
	}
}

#endif /* LEADERSOFARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
