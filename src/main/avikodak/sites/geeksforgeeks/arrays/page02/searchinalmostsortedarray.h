/****************************************************************************************************************************************************
 *  File Name   		: searchinalmostsortedarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\searchinalmostsortedarray.h
 *  Created on			: Jan 6, 2015 :: 10:20:47 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/search-almost-sorted-array/
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

#ifndef SEARCHINALMOSTSORTEDARRAY_H_
#define SEARCHINALMOSTSORTEDARRAY_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 															    	*/
/****************************************************************************************************************************************************/
//Tested
bool searchInAlmostSortedArrayONLOGN(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return false;
	}
	if(startIndex == endIndex){
		return userInput[startIndex] == key;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return true;
	}
	if(middleIndex - 1 >= startIndex && userInput[middleIndex-1] == key){
		return true;
	}
	if(middleIndex+1 <= endIndex && userInput[middleIndex+1] == key){
		return true;
	}
	if(userInput[middleIndex] > key){
		return searchInAlmostSortedArrayONLOGN(userInput,key,startIndex,middleIndex-2);
	}else{
		return searchInAlmostSortedArrayONLOGN(userInput,key,middleIndex+2,endIndex);
	}
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool searchInAlmostSortedArray(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			return true;
		}
	}
	return false;
}

#endif /* SEARCHINALMOSTSORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
