/****************************************************************************************************************************************************
 *  File Name   		: mergesort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture06\mergesort.h
 *  Created on			: Dec 12, 2014 :: 2:09:53 PM
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

#ifndef MERGESORTV2_H_
#define MERGESORTV2_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void msMerge(vector<int> &userInput,int startIndex,int middleIndex,int endIndex){
	if(startIndex > endIndex){
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

void msMergeSort(vector<int> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	msMergeSort(userInput,startIndex,middleIndex);
	msMergeSort(userInput,middleIndex+1,endIndex);
	msMerge(userInput,startIndex,middleIndex,endIndex);
}

void msMergeSortV2(vector<int> &userInput,int startIndex,int endIndex);

void msMergeV2(vector<int> &userInput,int startIndex,int middleIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int firstCrawler = startIndex,secondCrawler = middleIndex+1;
	while(firstCrawler <= middleIndex && secondCrawler <= endIndex){
		if(userInput[firstCrawler] > userInput[secondCrawler]){
			swap(userInput[firstCrawler],userInput[secondCrawler]);
		}
		firstCrawler++;
	}
	msMergeSortV2(userInput,middleIndex,endIndex);
}

void msMergeSortV2(vector<int> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	msMergeSortV2(userInput,startIndex,middleIndex);
	msMergeSortV2(userInput,middleIndex+1,endIndex);
	msMergeV2(userInput,startIndex,middleIndex,endIndex);
}

#endif /* MERGESORTV2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
