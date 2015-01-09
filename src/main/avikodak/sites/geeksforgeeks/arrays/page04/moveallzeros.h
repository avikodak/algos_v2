/****************************************************************************************************************************************************
 *  File Name   		: moveallzeros.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\moveallzeros.h
 *  Created on			: Dec 22, 2014 :: 3:39:11 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/move-zeroes-end-array/
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

#ifndef MOVEALLZEROS_H_
#define MOVEALLZEROS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void moveAllZerosToEnd(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int fillCounter = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] != 0){
			userInput[fillCounter++] = userInput[counter];
		}
	}
	while(fillCounter < userInput.size()){
		userInput[fillCounter++] = 0;
	}
}

//Tested
void moveAllZerosToEndBucketSort(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	queue<int> auxSpace;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] != 0){
			auxSpace.push(userInput[counter]);
		}
	}
	unsigned int fillCounter = 0;
	while(!auxSpace.empty()){
		userInput[fillCounter++] = auxSpace.front();
		auxSpace.pop();
	}
	while(fillCounter < userInput.size()){
		userInput[fillCounter++] = 0;
	}
}

#endif /* MOVEALLZEROS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/