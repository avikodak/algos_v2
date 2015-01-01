/****************************************************************************************************************************************************
 *  File Name   		: floorceiling.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\floorceiling.h
 *  Created on			: Nov 26, 2014 :: 4:07:02 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/search-floor-and-ceil-in-a-sorted-array/
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

#ifndef FLOORCEILING_H_
#define FLOORCEILING_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
floorceiling *floorCeilingBinarySearch(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return null;
	}
	if(key <= userInput[startIndex]){
		return new floorceiling(INT_MIN,userInput[startIndex]);
	}
	if(key >= userInput[endIndex]){
		return new floorceiling(userInput[endIndex],INT_MAX);
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return new floorceiling(userInput[middleIndex],userInput[middleIndex]);
	}
	if(userInput[middleIndex] > key){
		if(startIndex <= middleIndex-1 && userInput[middleIndex-1] < key){
			return new floorceiling(userInput[middleIndex-1],userInput[middleIndex+1]);
		}else{
			return floorCeilingBinarySearch(userInput,key,startIndex,middleIndex-1);
		}
	}else{
		if(endIndex >= middleIndex + 1 && userInput[middleIndex+1] > key){
			return new floorceiling(userInput[middleIndex],userInput[middleIndex+1]);
		}else{
			return floorCeilingBinarySearch(userInput,key,middleIndex+1,endIndex);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
floorceiling *floorCeilingON2(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return null;
	}
	unsigned int counter;
	for(counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] >= key){
			break;
		}
	}
	floorceiling *result = new floorceiling();
	if(counter == 0){
		result->floor = INT_MIN;
	}else{
		result->floor = userInput[counter-1];
	}
	if(counter >= userInput.size()){
		result->ceiling = INT_MAX;
	}else{
		result->ceiling = userInput[counter];
	}
	return result;
}

#endif /* FLOORCEILING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
