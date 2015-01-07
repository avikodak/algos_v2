/****************************************************************************************************************************************************
 *  File Name   		: sortusingdifferentarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\sortusingdifferentarray.h
 *  Created on			: Jan 6, 2015 :: 10:19:29 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/
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

#ifndef SORTUSINGDIFFERENTARRAY_H_
#define SORTUSINGDIFFERENTARRAY_H_

//Tested
void mergeStepSortingDifferrentArray(vector<int> &userInput,hash_map<int,unsigned int> valueRankMap,int startIndex,int middleIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int firstCrawler = startIndex,secondCrawler = middleIndex+1;
	hash_map<int,unsigned int>::iterator itToFirstValRankMap,itToSecondValRankMap;
	vector<int> auxSpace;
	while(firstCrawler <= middleIndex || secondCrawler <= endIndex){
		if(firstCrawler > middleIndex || secondCrawler > endIndex){
			if(firstCrawler <= middleIndex){
				auxSpace.push_back(userInput[firstCrawler++]);
			}else{
				auxSpace.push_back(userInput[secondCrawler++]);
			}
		}else{
			itToFirstValRankMap = valueRankMap.find(userInput[firstCrawler]);
			itToSecondValRankMap = valueRankMap.find(userInput[secondCrawler]);
			if(itToFirstValRankMap == valueRankMap.end() || itToSecondValRankMap == valueRankMap.end()){
				if(itToFirstValRankMap != valueRankMap.end()){
					auxSpace.push_back(userInput[firstCrawler++]);
				}else{
					auxSpace.push_back(userInput[secondCrawler++]);
				}
			}else{
				if(itToFirstValRankMap->second < itToSecondValRankMap->second){
					auxSpace.push_back(userInput[firstCrawler++]);
				}else{
					auxSpace.push_back(userInput[secondCrawler++]);
				}
			}
 		}
	}
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		userInput[startIndex + counter] = auxSpace[counter];
	}
}

//Tested
void mergeSortDifferentArrayMain(vector<int> &userInput,hash_map<int,unsigned int> valRankMap,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	mergeSortDifferentArrayMain(userInput,valRankMap,startIndex,middleIndex);
	mergeSortDifferentArrayMain(userInput,valRankMap,middleIndex+1,endIndex);
	mergeStepSortingDifferrentArray(userInput,valRankMap,startIndex,middleIndex,endIndex);
}

//Tested
void mergeSortDifferentArray(vector<int> &userInput,vector<int> rankInput){
	if(userInput.size() < 2){
		return;
	}
	hash_map<int,unsigned int> valRankMap;
	for(unsigned int counter = 0;counter < rankInput.size();counter++){
		valRankMap.insert(pair<int,unsigned int>(rankInput[counter],counter));
	}
	mergeSortDifferentArrayMain(userInput,valRankMap,0,userInput.size()-1);
}

//Tested
int lowerBoundForKeyBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MAX;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex-1 >= startIndex && userInput[middleIndex-1] == key){
			return lowerBoundForKeyBinarySearch(userInput,key,startIndex,middleIndex-1);
		}else{
			return middleIndex;
		}
	}else if(userInput[middleIndex] > key){
		return lowerBoundForKeyBinarySearch(userInput,key,startIndex,middleIndex-1);
	}else{
		return lowerBoundForKeyBinarySearch(userInput,key,middleIndex+1,endIndex);
	}
}

//Tested
int higherBoundForKeyBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MAX;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex + 1 <= endIndex && userInput[middleIndex+1] == key){
			return higherBoundForKeyBinarySearch(userInput,key,middleIndex+1,endIndex);
		}else{
			return middleIndex;
		}
	}else if(userInput[middleIndex] > key){
		return higherBoundForKeyBinarySearch(userInput,key,startIndex,middleIndex-1);
	}else{
		return higherBoundForKeyBinarySearch(userInput,key,middleIndex+1,endIndex);
	}
}

//Tested
void sortUsingDifferentArray(vector<int> &userInput,vector<int> rankArray){
	if(userInput.size() < 2){
		return;
	}
	vector<int> auxSpace(userInput.size());
	vector<int> visitedArray(userInput.size(),false);
	copy(userInput.begin(),userInput.end(),auxSpace.begin());
	sort(auxSpace.begin(),auxSpace.end());
	int lowerIndex,frequency;
	int fillCounter = -1;
	for(unsigned int counter = 0;counter < rankArray.size();counter++){
		lowerIndex = lowerBoundForKeyBinarySearch(auxSpace,rankArray[counter],0,auxSpace.size());
		if(lowerIndex != INT_MAX){
			frequency = higherBoundForKeyBinarySearch(auxSpace,rankArray[counter],0,auxSpace.size()) - lowerIndex + 1;
			while(frequency--){
				userInput[++fillCounter] = rankArray[counter];
				visitedArray[lowerIndex + frequency] = true;
			}
		}
	}
	for(unsigned int counter = 0;counter < visitedArray.size();counter++){
		if(!visitedArray[counter]){
			userInput[++fillCounter] = auxSpace[counter];
		}
	}
}

#endif /* SORTUSINGDIFFERENTARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
