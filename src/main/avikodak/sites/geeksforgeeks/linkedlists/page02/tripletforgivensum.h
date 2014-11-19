/****************************************************************************************************************************************************
 *  File Name   		: tripletforgivensum.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page02\tripletforgivensum.h
 *  Created on			: Oct 31, 2014 :: 12:08:14 PM
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
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TRIPLETFORGIVENSUM_H_
#define TRIPLETFORGIVENSUM_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

void frontBackSplit(sillNode *ptr,sillNode **firstPtr,sillNode **secondPtr){
	if(ptr == null || ptr->next == null){
		(*firstPtr) = ptr;
		(*secondPtr) = null;
		return;
	}
	sillNode *fastPtr = ptr->next,*slowPtr = ptr;
	while(fastPtr != null){
		fastPtr = fastPtr->next;
		if(fastPtr != null){
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next;
		}
	}
	(*secondPtr) = slowPtr->next;
	slowPtr->next = null;
	(*firstPtr) = ptr;
}

sillNode *merge(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return firstPtr == null?secondPtr:firstPtr;
	}
	sillNode *result = null;
	if(firstPtr->value < secondPtr->value){
		result = a;
		result->next = merge(firstPtr->next,secondPtr);
	}else{
		result = b;
		result->next = merge(firstPtr,secondPtr->next);
	}
	return result;
}

void mergeSort(sillNode **ptr){
	if(*ptr == null || (*ptr)->next == null){
		return;
	}
	sillNode *firstPtr = null,*secondPtr = null;
	frontBackSplit(*ptr,&firstPtr,&secondPtr);
	mergeSort(&firstPtr);
	mergeSort(&secondPtr);
	(*ptr) = merge(firstPtr,secondPtr);
}

iTriplet *getTripletForGivenSum(sillNode *firstPtr,sillNode *secondPtr,sillNode *thirdPtr,int value){
	if(firstPtr == null || secondPtr == null || thirdPtr == null){
		return null;
	}
	mergeSort(&firstPtr);
	mergeSort(&secondPtr);
	mergeSort(&thirdPtr);
	reverseSill(&thirdPtr);
	sillNode *firstCrawler = firstPtr,*secondCrawler,*thirdCrawler;
	int sum;
	while(firstCrawler != null){
		secondCrawler = secondPtr;
		thirdCrawler = thirdPtr;
		while(secondCrawler != null && thirdCrawler != null){
			sum = firstCrawler->value + secondCrawler->value + thirdCrawler->value;
			if(sum == value){
				iTriplet *result = new iTriplet(firstCrawler->value,secondCrawler->value,thirdCrawler->value);
				return result;
			}
			if(sum > value){
				thirdCrawler = thirdCrawler->next;
			}else{
				secondCrawler = secondCrawler->next;
			}
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
iTriplet *getTripletForGivenSum(sillNode *firstPtr,sillNode *secondPtr,sillNode *thirdPtr,int value){
	if(firstPtr == null || secondPtr == null || thirdPtr == null){
		return null;
	}
	sillNode *firstCrawler = firstPtr,*secondCrawler = null,*thirdCrawler = null;
	while(firstCrawler != null){
		secondCrawler = secondPtr;
		while(secondCrawler != null){
			thirdCrawler = thirdPtr;
			while(thirdCrawler != null){
				if(firstCrawler->value + secondCrawler->value + thirdCrawler->value == value){
					iTriplet *result = new iTriplet(firstCrawler->value,secondCrawler->value,thirdCrawler->value);
					return result;
				}
				thirdCrawler = thirdCrawler->next;
			}
			secondCrawler = secondCrawler->next;
		}
		firstCrawler = firstCrawler->next;
	}
	return null;
}

#endif /* TRIPLETFORGIVENSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
