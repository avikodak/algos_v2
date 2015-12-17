/****************************************************************************************************************************************************
 *  File Name   		: splitsillintohalves.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\splitsillintohalves.h
 *  Created on			: Oct 17, 2014 :: 1:45:01 PM
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SPLITSILLINTOHALVES_H_
#define SPLITSILLINTOHALVES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *splitSillIntoHalfPtrMain(sillNode *ptr){
	if(ptr == null){
		return;
	}

}

sillNode *splitSillIntoHalfPtr(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *result = (sillNode *)malloc(sizeof(sillNode)*2);
	result[0] = ptr;
	if(ptr->next == null){
		result[1] = null;
		return result;
	}
	sillNode *fastPtr = ptr->next->next,*slowPtr = ptr;
	while(slowPtr != null && fastPtr != null && fastPtr->next != null){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	result[1] = slowPtr->next;
	slowPtr->next = null;
	return result;
}

sillNode *splitSillIntoHalfHashmap(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *result = (sillNode *)malloc(sizeof(sillNode)*2);
	result[0] = ptr;
	if(ptr->next == null){
		result[1] = null;
		return result;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> indexNodeMap = utils->getSillAsHashmap(ptr,1);
	unsigned int middleIndex = indexNodeMap.size()/2;
	result[1] = indexNodeMap.find(middleIndex)->second->next;
	result[1]->next = null;
	return result;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* SPLITSILLINTOHALVES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
