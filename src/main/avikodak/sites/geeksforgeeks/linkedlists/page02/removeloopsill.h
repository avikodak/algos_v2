/****************************************************************************************************************************************************
 *  File Name   		: removeloopsill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page02\removeloopsill.h
 *  Created on			: Oct 30, 2014 :: 11:23:05 AM
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

#ifndef REMOVELOOPSILL_H_
#define REMOVELOOPSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void removeLoop(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *fastPtr = ptr,*slowPtr = ptr;
	while(fastPtr != null && fastPtr->next != null){
		if(fastPtr == slowPtr){
			break;
		}
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next;
	}
	if(fastPtr != slowPtr){
		return;
	}
	unsigned int lengthOfLoop = 0;
	sillNode *crawler = slowPtr;
	while(crawler->next != slowPtr){
		lengthOfLoop++;
		crawler = crawler->next;
	}
	slowPtr = ptr;
	fastPtr = ptr;
	while(lengthOfLoop--){
		fastPtr = fastPtr->next;
	}
	while(fastPtr->next == slowPtr){
		fastPtr = fastPtr->next;
		slowPtr = slowPtr->next;
	}
	fastPtr->next = null;
}

void removeLoopHashmap(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *crawler = ptr;
	hash_map<uint32_t,bool> visitedNodeFlags;
	hash_map<uint32_t,bool>::iterator itToVisitedNodeFlags;
	while(crawler != null && crawler->next != null){
		if((itToVisitedNodeFlags = visitedNodeFlags.find((uint32_t)crawler->next)) != visitedNodeFlags.end()){
			crawler->next = null;
			return;
		}
		visitedNodeFlags.insert(pair<uint32_t,bool>((uint32_t)crawler,true));
		crawler = crawler->next;
	}
}

void removeLoop(svillNode *ptr){
	if(ptr == null){
		return;
	}
	svillNode *crawler;
	while(true){
		if(crawler->next->isVisited){
			crawler->next = null;
			return;
		}
		crawler = crawler->next;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void removeLoopON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *fastPtr = ptr,*slowPtr = ptr;
	while(fastPtr != null && fastPtr->next != null){
		if(fastPtr == slowPtr){
			break;
		}
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next;
	}
	if(fastPtr != slowPtr){
		return;
	}
	sillNode *crawler = ptr,*loopCrawler;
	while(true){
		loopCrawler = slowPtr;
		while(loopCrawler->next != slowPtr){
			if(loopCrawler->next == crawler){
				loopCrawler->next = null;
				return;
			}
			loopCrawler = loopCrawler->next;
		}
		crawler = crawler->next;
	}
}

#endif /* REMOVELOOPSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
