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
