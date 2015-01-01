/****************************************************************************************************************************************************
 *  File Name   		: findsmallestmissingnumber.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\findsmallestmissingnumber.h
 *  Created on			: Nov 26, 2014 :: 6:27:58 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-the-first-missing-number/
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

#ifndef FINDSMALLESTMISSINGNUMBER_H_
#define FINDSMALLESTMISSINGNUMBER_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int findSmallestMissingNumberMain(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return userInput.size();
	}
	if(startIndex != userInput[startIndex]){
		return startIndex;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] > middleIndex){
		return findSmallestMissingNumberMain(userInput,startIndex,middleIndex-1);
	}else{
		return findSmallestMissingNumberMain(userInput,middleIndex+1,endIndex);
	}
}

//Tested
int findSmallestMissingNumber(vector<int> userInput){
	return findSmallestMissingNumberMain(userInput,0,userInput.size()-1);
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int findSmallestMissingNumbersLinear(vector<unsigned int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(counter != userInput[counter]){
			return counter;
		}
	}
	return userInput.size();
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool smnBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return false;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return true;
	}else if(userInput[middleIndex] > key){
		return smnBinarySearch(userInput,key,startIndex,middleIndex-1);
	}else{
		return smnBinarySearch(userInput,key,middleIndex+1,endIndex);
	}
}

//Tested
unsigned int findSmallestMissingNumbers(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(!smnBinarySearch(userInput,counter,0,userInput.size()-1)){
			return counter;
		}
	}
	return userInput.size();
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int findSmallestMissingNumberON2(vector<unsigned int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	bool valFound;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		valFound = false;
		for(unsigned int innerCounter = 0;innerCounter < userInput.size();innerCounter++){
			if(userInput[innerCounter] == counter){
				valFound = true;
				break;
			}
		}
		if(!valFound){
			return counter;
		}
	}
	return userInput.size();
}

#endif /* FINDSMALLESTMISSINGNUMBER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
