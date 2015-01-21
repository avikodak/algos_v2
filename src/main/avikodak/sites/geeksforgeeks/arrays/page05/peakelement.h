/****************************************************************************************************************************************************
 *  File Name   		: peakelement.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\peakelement.h
 *  Created on			: Jan 18, 2015 :: 6:00:53 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
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

#ifndef PEAKELEMENT_H_
#define PEAKELEMENT_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 															    	*/
/****************************************************************************************************************************************************/
//Tested
int findPeakElementBinarySearch(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		return userInput[startIndex];
	}
	if(endIndex - startIndex == 1){
		return max(userInput[startIndex],userInput[endIndex]);
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] > userInput[middleIndex-1] && userInput[middleIndex] > userInput[middleIndex+1]){
		return userInput[middleIndex];
	}
	if(userInput[middleIndex-1] > userInput[middleIndex]){
		return findPeakElementBinarySearch(userInput,startIndex,middleIndex-1);
	}else{
		return findPeakElementBinarySearch(userInput,middleIndex+1,endIndex);
	}
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int findPeakElementON(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	if(userInput.size() == 1){
		return userInput[0];
	}
	if(userInput[0] > userInput[1]){
		return userInput[0];
	}
	if(userInput[userInput.size()-1] > userInput[userInput.size()-2]){
		return userInput[userInput.size()-1];
	}
	for(unsigned int counter = 1;counter < userInput.size()-1;counter++){
		if(userInput[counter] > userInput[counter-1] && userInput[counter] > userInput[counter+1]){
			return userInput[counter];
		}
	}
	return INT_MIN;
}

#endif /* PEAKELEMENT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
