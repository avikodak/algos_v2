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
