/****************************************************************************************************************************************************
 *  File Name   		: sortarraywaveform.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\sortarraywaveform.h
 *  Created on			: Jan 5, 2015 :: 10:24:38 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/sort-array-wave-form-2/
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

#ifndef SORTARRAYWAVEFORM_H_
#define SORTARRAYWAVEFORM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void sawfReorganizeArrayBitPosition(vector<int> &userInput,int bitPosition){
	if(userInput.size() == 0){
		return;
	}
	queue<int> zeroIndex,oneIndex;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(!(userInput[counter] & 1 << bitPosition)){
			zeroIndex.push(userInput[counter]);
		}else{
			oneIndex.push(userInput[counter]);
		}
	}
	int fillCounter = -1;
	while(!zeroIndex.empty()){
		userInput[++fillCounter] = zeroIndex.front();
		zeroIndex.pop();
	}
	while(!oneIndex.empty()){
		userInput[++fillCounter] = oneIndex.front();
		oneIndex.pop();
	}
}

void waveSortStraightRadixSort(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	int maxVal = *max_element(userInput.begin(),userInput.end());
	int totalBits = log2(maxVal)+1;
	for(unsigned int counter = 0;counter < totalBits;counter++){
		sawfReorganizeArrayBitPosition(userInput,counter);
	}
	for(unsigned int counter = 0;counter + 1 < userInput.size();counter+=2){
		swap(userInput[counter],userInput[counter+1]);
	}
}

int sawfDivideStepRadixSort(vector<int> &userInput,int bitPosition,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		return startIndex;
	}
	while(startIndex < endIndex){
		while(startIndex < endIndex && !(userInput[startIndex] & 1 << bitPosition)){
			startIndex++;
		}
		while(startIndex < endIndex && (userInput[endIndex] & 1 << bitPosition)){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	return endIndex;
}

void sawfRadixSortMain(vector<int> &userInput,int bitPosition,int startIndex,int endIndex){
	if(startIndex >= endIndex || bitPosition < 0){
		return;
	}
	int dividingIndex = sawfDivideStepRadixSort(userInput,bitPosition,startIndex,endIndex);
	sawfRadixSortMain(userInput,bitPosition-1,startIndex,dividingIndex);
	sawfRadixSortMain(userInput,bitPosition-1,dividingIndex+1,endIndex);
}

void waveSortRadixSort(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	int maxVal = *max_element(userInput.begin(),userInput.end());
	int bitPosition = log2(maxVal);
	sawfRadixSortMain(userInput,bitPosition,0,userInput.size()-1);
	for(unsigned int counter = 0;counter+1 < userInput.size();counter += 2){
		swap(userInput[counter],userInput[counter+1]);
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void sawfMergeStep(vector<int> &userInput,int startIndex,int middleIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	vector<int> auxSpace;
	int firstCrawler = startIndex,secondCrawler = middleIndex+1;
	while(firstCrawler <= middleIndex || secondCrawler <= endIndex){
		if(firstCrawler > middleIndex || secondCrawler > endIndex){
			if(firstCrawler <= middleIndex){
				auxSpace.push_back(userInput[firstCrawler++]);
			}else{
				auxSpace.push_back(userInput[secondCrawler++]);
			}
		}else{
			if(userInput[firstCrawler] < userInput[secondCrawler]){
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

void sawfMergeSort(vector<int> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	sawfMergeSort(userInput,startIndex,middleIndex);
	sawfMergeSort(userInput,middleIndex+1,endIndex);
	sawfMergeStep(userInput,startIndex,middleIndex,endIndex);
}

void sortWaveSortMergeSort(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	sawfMergeSort(userInput,0,userInput.size()-1);
	for(unsigned int counter = 0;counter + 1 < userInput.size();counter += 2){
		swap(userInput[counter],userInput[counter+1]);
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int sawfDivideStepQuickSort(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return INT_MIN;
	}
	int pivotIndex = endIndex;
	int key = userInput[pivotIndex];
	while(startIndex < endIndex){
		while(userInput[startIndex] < key){
			startIndex++;
		}
		while(startIndex < endIndex && userInput[endIndex] >= key){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(userInput[startIndex],userInput[endIndex]);
		}
	}
	swap(userInput[pivotIndex],userInput[endIndex]);
	return endIndex;
}

int sawfQuickSort(vector<int> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int dividingIndex = sawfDivideStepQuickSort(userInput,startIndex,endIndex);
	sawfQuickSort(userInput,startIndex,dividingIndex-1);
	sawfQuickSort(userInput,dividingIndex+1,endIndex);
}

void sortArrayWaveFormQuickSort(vector<int> &userInput){
	if(userInput.size() <  2){
		return;
	}
	sawfQuickSort(userInput,0,userInput.size()-1);
	for(unsigned int counter = 0;counter + 1 < userInput.size();counter += 2){
		swap(userInput[counter],userInput[counter+1]);
	}
}

#endif /* SORTARRAYWAVEFORM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
