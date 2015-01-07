/****************************************************************************************************************************************************
 *  File Name   		: findfirstrepeating.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\findfirstrepeating.h
 *  Created on			: Jan 5, 2015 :: 8:50:09 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-first-repeating-element-array-integers/
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

#ifndef FINDFIRSTREPEATING_H_
#define FINDFIRSTREPEATING_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int findFirstRepeatingHashmapON(vector<int> userInput){
	if(userInput.size() < 2){
		return INT_MIN;
	}
	hash_map<int,unsigned int> visitedVal;
	hash_map<int,unsigned int>::iterator itToVisitedVal;
	unsigned int minIndex = UINT_MAX;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToVisitedVal = visitedVal.find(userInput[counter])) != visitedVal.end()){
			minIndex = min(minIndex,itToVisitedVal->second);
		}
		visitedVal.insert(pair<int,bool>(userInput[counter],counter));
	}
	return minIndex != INT_MAX?userInput[minIndex]:INT_MAX;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int gfrGetLowerIndex(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		if(userInput[startIndex] == key){
			return startIndex;
		}
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex - 1 >= startIndex && userInput[middleIndex-1] == key){
			return gfrGetLowerIndex(userInput,key,startIndex,middleIndex-1);
		}else{
			return middleIndex;
		}
	}else{
		if(userInput[middleIndex] > key){
			return gfrGetLowerIndex(userInput,key,startIndex,middleIndex-1);
		}else{
			return gfrGetLowerIndex(userInput,key,middleIndex+1,endIndex);
		}
	}
}

//Tested
int gfrGetHigherIndex(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		if(userInput[startIndex] == key){
			return startIndex;
		}
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex+1 <= endIndex && userInput[middleIndex+1] == key){
			return gfrGetHigherIndex(userInput,key,middleIndex+1,endIndex);
		}else{
			return middleIndex;
		}
	}else{
		if(userInput[middleIndex] > key){
			return gfrGetHigherIndex(userInput,key,startIndex,middleIndex-1);
		}else{
			return gfrGetHigherIndex(userInput,key,middleIndex+1,endIndex);
		}
	}
}

//Tested
int gfrGetFrequency(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return 0;
	}
	return gfrGetHigherIndex(userInput,key,0,userInput.size()-1) - gfrGetLowerIndex(userInput,key,0,userInput.size()-1) + 1;
}

//Tested
int getFirstRepeatingSorting(vector<int> userInput){
	if(userInput.size() < 2){
		return INT_MIN;
	}
	vector<int> auxSpace(userInput.size());
	copy(userInput.begin(),userInput.end(),auxSpace.begin());
	sort(auxSpace.begin(),auxSpace.end());
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(gfrGetFrequency(auxSpace,userInput[counter]) > 1){
			return userInput[counter];
		}
	}
	return INT_MIN;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getFirstRepeatingON2(vector<int> userInput){
	if(userInput.size() < 2){
		return INT_MIN;
	}
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				return userInput[outerCrawler];
			}
		}
	}
	return INT_MIN;
}

#endif /* FINDFIRSTREPEATING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
