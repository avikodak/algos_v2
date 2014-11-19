/****************************************************************************************************************************************************
 *  File Name   		: detectloopsill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\detectloopsill.h
 *  Created on			: Oct 14, 2014 :: 12:13:04 PM
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

#ifndef DETECTLOOPSILL_H_
#define DETECTLOOPSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool detectLoopHashMap(sillNode *ptr){
	if(ptr == null){
		return false;
	}
	hash_map<uint32_t,bool> visitedNodes;
	hash_map<uint32_t,bool>::iterator itToVisitedNodes;
	sillNode *crawler = ptr;
	while(crawler != null && crawler->next != null){
		if((itToVisitedNodes = visitedNodes.find((uint32_t)crawler->next)) != visitedNodes.end()){
			return true;
		}
		visitedNodes.insert(pair<uint32_t,bool>((uint32_t)crawler,true));
		crawler = crawler->next;
	}
	return false;
}

bool detectLoopFlags(svillNode *ptr){
	if(ptr == null){
		return false;
	}
	while(ptr != null && ptr->next != null){
		if(!ptr->next->isVisited){
			return true;
		}
		ptr->isVisited = true;
		ptr = ptr->next;
	}
	return false;
}

//Tested
bool detectLoopTwoPtrs(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return false;
	}
	sillNode *slowCrawler = ptr,*fastCrawler = ptr->next->next;
	while(slowCrawler != null && fastCrawler != null && fastCrawler->next != null){
		if(slowCrawler == fastCrawler){
			return true;
		}
		slowCrawler = slowCrawler->next;
		fastCrawler = fastCrawler->next->next;
	}
	return false;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool detectLoopON2(sillNode *ptr){
	if(ptr == null){
		return false;
	}
	sillNode *outerCrawler = ptr,*innerCrawler;
	while(outerCrawler != null){
		innerCrawler = ptr;
		while(innerCrawler != null && innerCrawler != outerCrawler){
			if(outerCrawler->next == innerCrawler){
				return true;
			}
			innerCrawler = innerCrawler->next;
		}
		if(innerCrawler == null){
			return false;
		}
		outerCrawler = outerCrawler->next;
	}
	return false;
}

#endif /* DETECTLOOPSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
