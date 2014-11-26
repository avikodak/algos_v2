/****************************************************************************************************************************************************
 *  File Name   		: searchinsortedpivotedarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\searchinsortedpivotedarray.h
 *  Created on			: Oct 17, 2014 :: 6:49:44 PM
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
#include <algorithm/utils/trieutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SEARCHINSORTEDPIVOTEDARRAY_H_
#define SEARCHINSORTEDPIVOTEDARRAY_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int getPivotElementIndex(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MAX;
	}
	if(startIndex == endIndex){
		return startIndex;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] > userInput[middleIndex-1] && userInput[middleIndex] > userInput[middleIndex+1]){
		return middleIndex;
	}else if(userInput[middleIndex] > userInput[startIndex]){
		return getPivotElementIndex(userInput,middleIndex+1,endIndex);
	}else{
		return getPivotElementIndex(userInput,startIndex,middleIndex-1);
	}
}

bool binarySearchPivot(vector<int> userInput,int startIndex,int endIndex,int key){
	if(startIndex > endIndex){
		return false;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return true;
	}else if(userInput[middleIndex] > key){
		return binarySearchPivot(userInput,startIndex,middleIndex-1,key);
	}else{
		return binarySearchPivot(userInput,middleIndex+1,endIndex,key);
	}
}

bool searchInSortedPivotedArray(vector<int> userInput,int key){
	int pivotIndex = getPivotElementIndex(userInput,0,userInput.size()-1);
	if(pivotIndex == INT_MAX){
		return false;
	}
	if(userInput[0] >= key){
		return binarySearchPivot(userInput,0,pivotIndex,key);
	}else{
		return binarySearchPivot(userInput,pivotIndex+1,userInput.size()-1,key);
	}
}

bool searchInSortedPivotedArrayOLOGN(vector<int> userInput,int key,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return false;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return true;
	}else if(userInput[startIndex] < userInput[middleIndex]){
		if(key >= userInput[startIndex] && key <userInput[middleIndex]){
			return searchInSortedPivotedArrayOLOGN(userInput,key,startIndex,middleIndex-1);
		}else{
			return searchInSortedPivotedArrayOLOGN(userInput,key,middleIndex+1,endIndex);
		}
	}else{
		if(key > userInput[middleIndex] && key < userInput[startIndex]){
			return searchInSortedPivotedArrayOLOGN(userInput,key,middleIndex+1,endIndex);
		}else{
			return searchInSortedPivotedArrayOLOGN(userInput,key,startIndex,middleIndex-1);
		}
	}
}

bool searchInSortedPivotedArrayOLOGN(vector<int> userInput,int key){

}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool searchInRotatedArray(vector<int> userInput,int key){
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			return true;
		}
	}
	return false;
}


#endif /* SEARCHINSORTEDPIVOTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
