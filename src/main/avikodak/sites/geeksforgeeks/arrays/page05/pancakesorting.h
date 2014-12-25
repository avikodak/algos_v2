/****************************************************************************************************************************************************
 *  File Name   		: pancakesorting.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\pancakesorting.h
 *  Created on			: Dec 25, 2014 :: 2:42:19 AM
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

#ifndef PANCAKESORTING_H_
#define PANCAKESORTING_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void flip(vector<int> &userInput,unsigned int endIndex){
	if(endIndex == 0 || endIndex >= userInput.size()){
		return;
	}
	unsigned int startIndex = 0;
	while(startIndex < endIndex){
		swap(userInput[startIndex++],userInput[endIndex--]);
	}
}

//Tested
int getMaxValIndex(vector<int> userInput,int endIndex){
	if(endIndex < 0){
		return INT_MAX;
	}
	if(endIndex == 0){
		return 0;
	}
	int maxValIndex = 0;
	for(int counter = 1;counter <= endIndex;counter++){
		if(userInput[counter] > userInput[maxValIndex]){
			maxValIndex = counter;
		}
	}
	return maxValIndex;
}

//Tested
void pancakeSorting(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	int maxValIndex;
	for(int counter = userInput.size()-1;counter >= 0;counter--){
		maxValIndex = getMaxValIndex(userInput,counter);
		flip(userInput,maxValIndex);
		flip(userInput,counter);
	}
}

#endif /* PANCAKESORTING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
