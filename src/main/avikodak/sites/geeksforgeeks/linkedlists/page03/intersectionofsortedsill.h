/****************************************************************************************************************************************************
 *  File Name   		: intersectionofsortedsill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page03\intersectionofsortedsill.h
 *  Created on			: Oct 19, 2014 :: 4:37:34 PM
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

#ifndef INTERSECTIONOFSORTEDSILL_H_
#define INTERSECTIONOFSORTEDSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *intersectionOfSortedSill(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return null;
	}
	sillNode *intersectionOfSill = null,*intersectionCrawler = null;
	while(firstPtr != null && secondPtr != null){
		if(firstPtr->value == secondPtr->value){
			if(intersectionOfSill == null){
				intersectionOfSill = new sillNode(firstPtr->value);
				intersectionCrawler = intersectionOfSill;
			}else{
				intersectionCrawler->next = new sillNode(firstPtr->value);
			}
			firstPtr = firstPtr->next;
			secondPtr = secondPtr->next;
		}else{
			if(firstPtr->value > secondPtr->value){
				secondPtr = secondPtr->next;
			}else{
				firstPtr = firstPtr->next;
			}
		}
	}
	return intersectionOfSill;
}

sillNode *getIntersectionOfSortedSillHashmap(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return null;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	sillNode *crawler = firstPtr,*intersectionHead = null,*intersectionCrawler;
	while(crawler != null){
		if(frequencyMap.find(crawler->value) == frequencyMap.end()){
			frequencyMap[crawler->value] = 1;
		}else{
			frequencyMap[crawler->value] += 1;
		}
		crawler = crawler->next;
	}
	crawler = secondPtr;
	while(crawler != null){
		itToFrequencyMap = frequencyMap.find(crawler->value);
		if(itToFrequencyMap != frequencyMap.end()){
			if(itToFrequencyMap->second == 1){
				frequencyMap.erase(crawler->value);
			}else{
				itToFrequencyMap->second -= 1;
			}
			if(intersectionHead == null){
				intersectionHead = new sillNode(crawler->value);
				intersectionCrawler = intersectionHead;
			}else{
				intersectionCrawler->next = new sillNode(crawler->value);
			}
		}
	}
	return intersectionHead;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *intersectionOfSortedSillON2(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null || secondPtr == null){
		return null;
	}
	unsigned int prevElementFrequency = 0;
	sillNode *firstSillCrawler = firstPtr,*secondSillCrawler = secondPtr;
	sillNode *intersectionSill = null;
	while(firstSillCrawler != null){
		secondSillCrawler = secondPtr;
		while(secondSillCrawler != null){

		}
		firstSillCrawler = firstSillCrawler->next;
	}
}
#endif /* INTERSECTIONOFSORTEDSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

