/****************************************************************************************************************************************************
 *  File Name   		: issillpalindrome.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\issillpalindrome.h
 *  Created on			: Oct 14, 2014 :: 12:58:42 PM
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

#include "reversesill.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef ISSILLPALINDROME_H_
#define ISSILLPALINDROME_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isSillPalindrome(sillNode *ptr,sillNode **frontCrawler){
	if(ptr == null){
		return true;
	}
	bool truthValue = isSillPalindrome(ptr->next,frontCrawler);
	truthValue = truthValue && (ptr->value == (*frontCrawler)->value);
	(*frontCrawler) = (*frontCrawler)->next;
	return truthValue;
}

bool isSillPalindromeAuxspace(sillNode *ptr){
	if(ptr == null){
		return true;
	}
	stack<sillNode *> auxSpace;
	sillNode *crawler = ptr;
	while(crawler != null){
		crawler = crawler->next;
	}
	crawler = ptr;
	while(!auxSpace.empty()){
		if(crawler->value != auxSpace.top()->value){
			return false;
		}
		auxSpace.pop();
		crawler = crawler->next;
	}
	return true;
}

bool isSillPalindromeByReverse(sillNode *ptr){
	if(ptr == null){
		return true;
	}
	sillNode *reversedSill = reverseSillNewSill(ptr);
	while(ptr != null && reversedSill != null){
		if(ptr->value != reversedSill->value){
			return false;
		}
		ptr = ptr->next;
		reversedSill = reversedSill->next;
	}
	return true;
}

bool isSillPalindromeHashmap(sillNode *ptr){
	if(ptr == null){
		return true;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> indexNodeMap = utils->getSillAsHashmap(ptr,1)->indexNodeMap;
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	unsigned int lengthOfSill = utils->lengthOfSill(ptr);
	for(unsigned int counter = lengthOfSill;counter > lengthOfSill/2;counter--){
		itToIndexNodeMap = indexNodeMap.find(counter);
		if(ptr->value != itToIndexNodeMap->second->value){
			return false;
		}
		ptr = ptr->next;
	}
	return true;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *getNodeForIndexSill(sillNode *ptr,unsigned int index){
	if(ptr == null){
		return null;
	}
	if(index == 0){
		return ptr;
	}
	return getNodeForIndexSill(ptr->next,index-1);
}

bool isSillPalindromeON2(sillNode *ptr){
	if(ptr == null){
		return true;
	}
	sillutils *utils = new sillutils();
	unsigned int lengthOfSill = utils->lengthOfSill(ptr);
	sillNode *crawler = ptr,*temp;
	for(unsigned int counter = 0;counter <= lengthOfSill/2;counter++){
		temp = getNodeForIndexSill(ptr,lengthOfSill-counter);
		if(temp->value != crawler->value){
			return false;
		}
		crawler = crawler->next;
	}
	return true;
}

#endif /* ISSILLPALINDROME_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
