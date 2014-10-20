/****************************************************************************************************************************************************
 *  File Name   		: removeduplicatesunsortedsill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\removeduplicatesunsortedsill.h
 *  Created on			: Oct 17, 2014 :: 1:09:07 PM
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

#ifndef REMOVEDUPLICATESUNSORTEDSILL_H_
#define REMOVEDUPLICATESUNSORTEDSILL_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void removeDuplicatesON(sillNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	sillNode *crawler = ptr,*temp;
	while(crawler != null){
		if((itToFrequencyMap = frequencyMap.find(crawler->value)) != frequencyMap.end()){
			frequencyMap[crawler->value] += 1;
		}else{
			frequencyMap[crawler->value] = 1;
		}
		crawler = crawler->next;
	}
	crawler = ptr;
	while(crawler != null){
		itToFrequencyMap = frequencyMap.find(crawler->value);
		if(itToFrequencyMap->second > 1){
			crawler->value = crawler->next->value;
			temp = crawler->next;
			crawler->next = crawler->next->next;
			free(temp);
			frequencyMap[crawler->value] -= 1;
		}else{
			crawler = crawler->next;
		}
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
void removeDuplicatesON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *outerCrawler = ptr,*innerCrawler;
	bool isDuplicate;
	while(outerCrawler != null){
		innerCrawler = outerCrawler->next;
		isDuplicate = false;
		while(innerCrawler != null){
			if(innerCrawler->value == outerCrawler->value){
				isDuplicate = true;
				break;
			}
		}
		if(isDuplicate){
			outerCrawler->value = outerCrawler->next->value;
			innerCrawler = outerCrawler->next;
			outerCrawler->next = outerCrawler->next->next;
			free(innerCrawler);
		}else{
			outerCrawler = outerCrawler->next;
		}
	}
}

void removeDuplicatesBSTON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	iftNode *frequencyBST = utils->getFBSTFromSill(ptr);
	iftNode *temp;
	sillNode *crawler = ptr,*nodeToBeDeleted;
	while(crawler != null){
		temp = utils->searchForValueBST(frequencyBST,crawler->value);
		if(crawler->value > 1){
			temp->value -= 1;
			nodeToBeDeleted = crawler->next;
			crawler->value = crawler->next->value;
			crawler->next = crawler->next->next;
			free(nodeToBeDeleted);
		}else{
			crawler = crawler->next;
		}
	}
}

#endif /* REMOVEDUPLICATESUNSORTEDSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
