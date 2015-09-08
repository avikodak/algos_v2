/****************************************************************************************************************************************************
 *  File Name   		: intersectionofsill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\intersectionofsill.h
 *  Created on			: Oct 15, 2014 :: 12:24:27 PM
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

#include "reversesill.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef INTERSECTIONOFSILL_H_
#define INTERSECTIONOFSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
sillNode *getIntersectionOfSillHashmapON(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return null;
	}
	hash_map<intptr_t,bool> visitFlags;
	hash_map<intptr_t,bool>::iterator itToVisitFlags;
	sillNode *crawler = firstPtr;
	while(crawler != null){
		visitFlags.insert(pair<intptr_t,bool>((intptr_t)crawler,true));
		crawler = crawler->next;
	}
	crawler = secondPtr;
	while(crawler != null){
		if((itToVisitFlags = visitFlags.find((intptr_t)crawler)) != visitFlags.end()){
			return crawler;
		}
		crawler = crawler->next;
	}
	return null;
}

//Tested
sillNode *getIntersectionOfSillLength(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return null;
	}
	sillutils *utils = new sillutils();
	unsigned int firstSillLength,secondSillLength;
	int difference;
	sillNode *firstSillCrawler = firstPtr,*secondSillCrawler = secondPtr;
	firstSillLength = utils->lengthOfSill(firstPtr);
	secondSillLength = utils->lengthOfSill(secondPtr);
	difference = firstSillLength - secondSillLength;
	difference = difference < 0?difference*-1:difference;
	while(difference--){
		if(firstSillLength > secondSillLength){
			firstSillCrawler = firstSillCrawler->next;
		}else{
			secondSillCrawler = secondSillCrawler->next;
		}
	}
	while(firstSillCrawler != null && secondSillCrawler != null){
		if(firstSillCrawler == secondSillCrawler){
			return firstSillCrawler;
		}
		firstSillCrawler = firstSillCrawler->next;
		secondSillCrawler = secondSillCrawler->next;
	}
	return null;
}

//Tested
sillNode *getIntersectionOfSillReversing(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return null;
	}
	sillutils *utils = new sillutils();
	unsigned int firstSillLength,secondSillLength,uncommonSillLength,commonSillLength,requiredSillLength;
	firstSillLength = utils->lengthOfSill(firstPtr);
	secondSillLength = utils->lengthOfSill(secondPtr);
	reverseSill(&firstPtr);
	reverseSill(&secondPtr);
	uncommonSillLength = utils->lengthOfSill(firstPtr);
	commonSillLength = (firstSillLength + secondSillLength - uncommonSillLength)/2;
	requiredSillLength = secondSillLength - commonSillLength;
	reverseSill(&firstPtr);
	reverseSill(&secondPtr);
	while(requiredSillLength--){
		secondPtr = secondPtr->next;
	}
	return secondPtr;
}

sillNode *getIntersectionOfSillByMakingLoop(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return null;
	}
	sillNode *firstCrawler = firstPtr;
	while(firstCrawler->next != null){
		firstCrawler = firstCrawler->next;
	}
	firstCrawler->next = firstPtr;
	//Loop formed
	//Find the loop starting point
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
sillNode *getIntersectionOfSillON2(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return null;
	}
	sillNode *outerCrawler = firstPtr,*innerCrawler = secondPtr;
	while(outerCrawler != null){
		innerCrawler = secondPtr;
		while(innerCrawler != null){
			if(innerCrawler == outerCrawler){
				return innerCrawler;
			}
			innerCrawler = innerCrawler->next;
		}
		outerCrawler = outerCrawler->next;
	}
	return null;
}

#endif /* INTERSECTIONOFSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
