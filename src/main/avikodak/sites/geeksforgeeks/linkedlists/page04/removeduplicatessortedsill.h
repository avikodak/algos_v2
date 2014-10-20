/****************************************************************************************************************************************************
 *  File Name   		: removeduplicatessortedsill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\removeduplicatessortedsill.h
 *  Created on			: Oct 17, 2014 :: 1:08:55 PM
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

#ifndef REMOVEDUPLICATESSORTEDSILL_H_
#define REMOVEDUPLICATESSORTEDSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void removeDuplicatesSortedSillON(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *outerCrawler = ptr,*innerCrawler,*nodeToBeDeleted;
	while(outerCrawler != null){
		innerCrawler = outerCrawler->next;
		while(innerCrawler != null && innerCrawler->value == outerCrawler->value){
			nodeToBeDeleted = innerCrawler;
			outerCrawler->next = innerCrawler->next;
			innerCrawler = outerCrawler->next;
			free(nodeToBeDeleted);
		}
		outerCrawler = outerCrawler->next;
	}
}

void removeDuplicatesSortedSillHashmap(sillNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	sillNode *crawler = ptr;
	while(crawler != null){
		if((itToFrequencyMap = frequencyMap.find(crawler->value)) != frequencyMap.end()){
			frequencyMap[crawler->value] += 1;
		}else{
			frequencyMap[crawler->value] = 1;
		}
		crawler = crawler->next;
	}
	while(crawler != null){

	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Merge sort
//Avl Tree
/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* REMOVEDUPLICATESSORTEDSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
