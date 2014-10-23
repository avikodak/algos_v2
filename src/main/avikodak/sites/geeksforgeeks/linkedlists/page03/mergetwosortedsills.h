/****************************************************************************************************************************************************
 *  File Name   		: mergetwosortedsills.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page03\mergetwosortedsills.h
 *  Created on			: Oct 23, 2014 :: 10:16:30 AM
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

#ifndef MERGETWOSORTEDSILLS_H_
#define MERGETWOSORTEDSILLS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *mergeTwoSortedSillON(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null && secondPtr == null){
		return null;
	}
	if(firstPtr == null || secondPtr == null){
		return firstPtr == null?secondPtr:firstPtr;
	}
	sillNode *node = new sillNode();
	if(firstPtr->value == secondPtr->value){
		node->value = firstPtr->value;
		node->next = mergeTwoSortedSillON(firstPtr->next,secondPtr->next);
	}else if(firstPtr->value < secondPtr->value){
		node->value = firstPtr->value;
		node->next = mergeTwoSortedSillON(firstPtr->next,secondPtr);
	}else{
		node->value = secondPtr->value;
		node->next = mergeTwoSortedSillON(firstPtr,secondPtr->next);
	}
	return node;
}

sillNode *mergeTwoSortedSillsONIterative(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null && secondPtr == null){
		return null;
	}
	if(firstPtr == null || secondPtr == null){
		return firstPtr == null?secondPtr:firstPtr;
	}
	sillNode *mergedSill = null,*mergedSillCrawler;
	int temp;
	while(firstPtr != null && secondPtr != null){
		if(firstPtr->value == secondPtr->value){
			temp = firstPtr->value;
			firstPtr = firstPtr->next;
			secondPtr = secondPtr->next;
		}else if(firstPtr->value > secondPtr->value){
			temp = secondPtr->value;
			secondPtr = secondPtr->next;
		}else{
			temp =  firstPtr->value;
			firstPtr = firstPtr->next;
		}
		if(mergedSill == null){
			mergedSill = new sillNode(temp);
			mergedSillCrawler = mergedSill;
		}else{
			mergedSillCrawler->next = new sillNode(temp);
			mergedSillCrawler = mergedSillCrawler->next;
		}
	}
	return mergedSill;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Merge sort
/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* MERGETWOSORTEDSILLS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
