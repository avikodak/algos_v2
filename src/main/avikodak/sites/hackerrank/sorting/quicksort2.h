/****************************************************************************************************************************************************
 *  File Name   		: quicksort2.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\sorting\quicksort2.h
 *  Created on			: Feb 12, 2015 :: 2:08:25 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef QUICKSORT2_H_
#define QUICKSORT2_H_

//Tested
void printVector(vector<int> userInput,int startIndex,int endIndex){
	for(int counter = startIndex;counter <= endIndex;counter++){
		printf("%d ",userInput[counter]);
	}
	printf("\n");
}

//Tested
int partitionArray(vector<int> &userInput,int start,int end){
	queue<int> firstBucket,secondBucket;
	int key = userInput[start];
	for(int counter = start;counter <= end;counter++){
		if(userInput[counter] < key){
			firstBucket.push(userInput[counter]);
		}else if(userInput[counter] > key){
			secondBucket.push(userInput[counter]);
		}
	}
	int fillCounter = start,pivotIndex;
	while(!firstBucket.empty()){
		userInput[fillCounter++] = firstBucket.front();
		firstBucket.pop();
	}
	userInput[fillCounter++] = key;
	pivotIndex = fillCounter-1;
	while(!secondBucket.empty()){
		userInput[fillCounter++] = secondBucket.front();
		secondBucket.pop();
	}
	return pivotIndex;
}

//Tested
void quickSort(vector<int> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int dividingIndex = partitionArray(userInput,startIndex,endIndex);
	quickSort(userInput,startIndex,dividingIndex-1);
	quickSort(userInput,dividingIndex+1,endIndex);
	printVector(userInput,startIndex,endIndex);
}

#endif /* QUICKSORT2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
