/****************************************************************************************************************************************************
 *  File Name   		: mergeoverlappinginterval.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\mergeoverlappinginterval.h
 *  Created on			: Dec 22, 2014 :: 8:22:37 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/merging-intervals/
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

#ifndef MERGEOVERLAPPINGINTERVAL_H_
#define MERGEOVERLAPPINGINTERVAL_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int divideStepQuickSortIntervals(vector<iInterval *> &userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int pivotIndex = endIndex;
	int key = userInput[pivotIndex]->start;
	while(startIndex < endIndex){
		while(userInput[startIndex]->start < key){
			startIndex++;
		}
		while(startIndex < endIndex && userInput[endIndex]->start >= key){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	swap(userInput[pivotIndex],userInput[endIndex]);
	return endIndex;
}

//Tested
void quickSortIntervals(vector<iInterval *> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int dividingIndex = divideStepQuickSortIntervals(userInput,startIndex,endIndex);
	quickSortIntervals(userInput,startIndex,dividingIndex-1);
	quickSortIntervals(userInput,dividingIndex+1,endIndex);
}

//Tested
void mergeStepInterval(vector<iInterval *> &userInput,int startIndex,int middleIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	vector<iInterval *> auxSpace;
	int firstCrawler = startIndex,secondCrawler = middleIndex+1;
	while(firstCrawler <= middleIndex || secondCrawler <= endIndex){
		if(firstCrawler > middleIndex || secondCrawler > endIndex){
			if(firstCrawler <= middleIndex){
				auxSpace.push_back(userInput[firstCrawler++]);
			}else{
				auxSpace.push_back(userInput[secondCrawler++]);
			}
		}else{
			if(userInput[firstCrawler]->start < userInput[secondCrawler]->start){
				auxSpace.push_back(userInput[firstCrawler++]);
			}else{
				auxSpace.push_back(userInput[secondCrawler++]);
			}
		}
	}
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		userInput[startIndex + counter] = auxSpace[counter];
	}
}

//Tested
void mergeSortInterval(vector<iInterval *> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	mergeSortInterval(userInput,startIndex,middleIndex);
	mergeSortInterval(userInput,middleIndex+1,endIndex);
	mergeStepInterval(userInput,startIndex,middleIndex,endIndex);
}

//Tested
vector<iInterval *> mergeOverLappingInterval(vector<iInterval *> userInput){
	vector<iInterval *> mergedIntervals;
	if(userInput.size() == 0){
		return mergedIntervals;
	}
	mergeSortInterval(userInput,0,userInput.size()-1);
	unsigned int firstCrawler = 0,secondCrawler;
	while(firstCrawler < userInput.size()){
		secondCrawler = firstCrawler;
		while(secondCrawler+1 < userInput.size() && userInput[secondCrawler]->end > userInput[secondCrawler+1]->start){
			secondCrawler++;
		}
		mergedIntervals.push_back(new iInterval(userInput[firstCrawler]->start,userInput[secondCrawler]->end));
		firstCrawler = secondCrawler+1;
	}
	return mergedIntervals;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* MERGEOVERLAPPINGINTERVAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
