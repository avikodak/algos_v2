/****************************************************************************************************************************************************
 *  File Name   		: quicksort1partition.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\sorting\quicksort1partition.h
 *  Created on			: Feb 12, 2015 :: 1:45:39 PM
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

#ifndef QUICKSORT1PARTITION_H_
#define QUICKSORT1PARTITION_H_

//Tested
void printVector(vector<int> userInput){
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		printf("%d ",userInput[counter]);
	}
}

//Tested
void partitionArray(){
	vector<int> userInput;
	int size,input;
	scanf("%d",&size);
	while(size--){
		scanf("%d",&input);
		userInput.push_back(input);
	}
	queue<int> firstBucket,secondBucket;
	int key = userInput[0];
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] < key){
			firstBucket.push(userInput[counter]);
		}else if(userInput[counter] > key){
			secondBucket.push(userInput[counter]);
		}
	}
	int fillCounter = 0;
	while(!firstBucket.empty()){
		userInput[fillCounter++] = firstBucket.front();
		firstBucket.pop();
	}
	userInput[fillCounter++] = key;
	while(!secondBucket.empty()){
		userInput[fillCounter++] = secondBucket.front();
		secondBucket.pop();
	}
	printVector(userInput);
}

#endif /* QUICKSORT1PARTITION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
