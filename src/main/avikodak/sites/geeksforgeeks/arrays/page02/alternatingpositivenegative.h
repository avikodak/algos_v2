/****************************************************************************************************************************************************
 *  File Name   		: alternatingpositivenegative.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\alternatingpositivenegative.h
 *  Created on			: Jan 5, 2015 :: 11:24:44 PM
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

#ifndef ALTERNATINGPOSITIVENEGATIVE_H_
#define ALTERNATINGPOSITIVENEGATIVE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void alternatePositiveNegativeNumbers(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	queue<int> negBucket,posBucket;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] < 0){
			negBucket.push(userInput[counter]);
		}else{
			posBucket.push(userInput[counter]);
		}
	}
	int fillCounter = -1;
	while(!negBucket.empty() && !posBucket.empty()){
		userInput[++fillCounter] = negBucket.front();
		userInput[++fillCounter] = posBucket.front();
		negBucket.pop();
		posBucket.pop();
	}
	while(!negBucket.empty()){
		userInput[++fillCounter] = negBucket.front();
		negBucket.pop();
	}
	while(!posBucket.empty()){
		userInput[++fillCounter] = posBucket.front();
		posBucket.pop();
	}
}

int alternatePositiveDivideStep(vector<int> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return INT_MIN;
	}
	while(startIndex < endIndex){
		while(startIndex < endIndex && userInput[startIndex] < 0){
			startIndex++;
		}
		while(startIndex < endIndex && userInput[endIndex] >= 0){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	return startIndex;
}

void alternatePositiveNegative(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	int pivotIndex = alternatePositiveDivideStep(userInput,0,userInput.size()-1);
	int counter = 0;
	while(counter < userInput.size() && pivotIndex < userInput.size()){
		if(userInput[counter] < 0){
			swap(userInput[counter],userInput[pivotIndex]);
			counter += 2;
			pivotIndex += 1;
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void posNegMergeStep(vector<int> &userInput,int startIndex,int middleIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int firstCrawler = startIndex,secondCrawler = middleIndex+1;
	vector<int> auxSpace;
	while(firstCrawler <= middleIndex && userInput[firstCrawler] < 0){
		auxSpace.push_back(userInput[firstCrawler]);
	}
	while(secondCrawler <= endIndex && userInput[secondCrawler] < 0){
		auxSpace.push_back(userInput[secondCrawler++]);
	}
	while(firstCrawler <= middleIndex && userInput[firstCrawler] > 0){
		auxSpace.push_back(userInput[firstCrawler]);
	}
	while(secondCrawler <= endIndex && userInput[secondCrawler] > 0){
		auxSpace.push_back(userInput[secondCrawler++]);
	}
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		userInput[startIndex + counter] = auxSpace[counter];
	}
}

void positiveNegativeMergeSortMain(vector<int> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	positiveNegativeMergeSortMain(userInput,startIndex,middleIndex);
	positiveNegativeMergeSortMain(userInput,middleIndex+1,endIndex);
	posNegMergeStep(userInput,startIndex,middleIndex,endIndex);
}

void alternatePositiveNegativeMerge(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	positiveNegativeMergeSortMain(userInput,0,userInput.size()-1);
	while(counter < userInput.size() && pivotIndex < userInput.size()){
		if(userInput[counter] < 0){
			swap(userInput[counter],userInput[pivotIndex]);
			counter += 2;
			pivotIndex += 1;
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void alternatePositiveNegativeON2(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	bool shouldBePositive = true;
	unsigned int innerCounter;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		if(shouldBePositive){
			if(userInput[outerCounter] < 0){
				for(innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
					if(userInput[innerCounter] > 0){
						break;
					}
				}
				if(innerCounter > userInput.size()){
					break;
				}
				swap(userInput[outerCounter],userInput[innerCounter]);
			}
		}else{
			if(userInput[outerCounter] > 0){
				for(innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
					if(userInput[innerCounter] < 0){
						break;
					}
				}
				if(innerCounter > userInput.size()){
					break;
				}
				swap(userInput[outerCounter],userInput[innerCounter]);
			}
		}
		shouldBePositive = !shouldBePositive;
	}
}

#endif /* ALTERNATINGPOSITIVENEGATIVE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
