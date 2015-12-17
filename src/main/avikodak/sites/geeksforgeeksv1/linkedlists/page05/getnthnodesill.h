/****************************************************************************************************************************************************
 *  File Name   		: getnthnodesill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page05\getnthnodesill.h
 *  Created on			: Oct 10, 2014 :: 3:41:31 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/
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

#ifndef GETNTHNODESILL_H_
#define GETNTHNODESILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
sillNode *getNthNodeSill(sillNode *ptr,unsigned int nValue){
	if(nValue == 0 || ptr == null){
		return null;
	}
	if(nValue == 1){
		return ptr;
	}
	return getNthNodeSill(ptr->next,nValue-1);
}

//Tested
sillNode *getNthNodeSillIterative(sillNode *ptr,unsigned int nValue){
	if(ptr == null || nValue == 0){
		return null;
	}
	nValue -= 1;
	while(nValue-- && ptr != null){
		ptr = ptr->next;
	}
	return ptr;
}

//Tested
sillNode *getNthNodeSillHashmap(sillNode *ptr,unsigned int nValue){
	if(ptr == null || nValue == 0){
		return null;
	}
	sillutils *utils = new sillutils();
	iSillHashmap *hashmapOfSill = utils->getSillAsHashmap(ptr,1);
	hash_map<unsigned int,sillNode *> indexNodeMap = hashmapOfSill->indexNodeMap;
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	if((itToIndexNodeMap = indexNodeMap.find(nValue)) != indexNodeMap.end()){
		return itToIndexNodeMap->second;
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
sillNode *getNthNodeSillON2(sillNode *ptr,unsigned int nValue){
	if(ptr == null || nValue == 0){
		return null;
	}
	sillNode *outerCrawler = ptr,*innerCrawler,*crawler;
	unsigned int counter;
	while(outerCrawler != null){
		innerCrawler = outerCrawler;
		crawler = ptr;
		counter = 1;
		while(crawler != innerCrawler){
			crawler = crawler->next;
			counter += 1;
		}
		if(counter == nValue){
			return innerCrawler;
		}
		outerCrawler = outerCrawler->next;
	}
	return null;
}

#endif /* GETNTHNODESILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
