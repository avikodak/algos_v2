/****************************************************************************************************************************************************
 *  File Name   		: checkformajorityelement.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\checkformajorityelement.h
 *  Created on			: Nov 26, 2014 :: 1:19:34 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array/
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
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

#ifndef CHECKFORMAJORITYELEMENT_H_
#define CHECKFORMAJORITYELEMENT_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getLowIndexSortedArray(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int middleIndex = (startIndex + endIndex) /2;
	if(userInput[middleIndex] == key){
		if(middleIndex-1 > startIndex){
			return getLowIndexSortedArray(userInput,key,startIndex,middleIndex-1);
		}else{
			return middleIndex;
		}
	}else if(userInput[middleIndex] > key){
		return getLowIndexSortedArray(userInput,key,startIndex,middleIndex-1);
	}else{
		return getLowIndexSortedArray(userInput,key,middleIndex+1,endIndex);
	}
}

//Tested
bool checkForMajorityElementOLOGN(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	int lowIndex = getLowIndexSortedArray(userInput,key,0,userInput.size()-1);
	if(lowIndex == INT_MIN || lowIndex + (userInput.size()/2) >= userInput.size()){
		return false;
	}
	return userInput[lowIndex] == userInput[lowIndex + userInput.size()/2];
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool checkForMajorityElementON(vector<int> userInput,int key){
	unsigned int frequency = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			frequency++;
		}
	}
	return frequency > userInput.size()/2;
}

#endif /* CHECKFORMAJORITYELEMENT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
