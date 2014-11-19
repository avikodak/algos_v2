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
