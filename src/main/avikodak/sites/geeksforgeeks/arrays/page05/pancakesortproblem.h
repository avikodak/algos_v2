/****************************************************************************************************************************************************
 *  File Name   		: pancakesortproblem.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\pancakesortproblem.h
 *  Created on			: Jan 4, 2015 :: 3:54:04 PM
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

#ifndef PANCAKESORTPROBLEM_H_
#define PANCAKESORTPROBLEM_H_

int ceilSearch(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(key < userInput[startIndex]){
		return userInput[startIndex];
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return userInput[middleIndex];
	}
	if(userInput[middleIndex] < key){
		return ceilSearch(userInput,key,middleIndex+1,endIndex);
	}else{
		if(middleIndex - 1 >= startIndex && userInput[middleIndex-1] > startIndex){
			return ceilSearch(userInput,key,startIndex,middleIndex-1);
		}else{
			return middleIndex;
		}
	}
}



void pancakeSortingProblem(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	for(unsigned int counter = 1;counter < userInput.size();counter++){

	}
}

#endif /* PANCAKESORTPROBLEM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
