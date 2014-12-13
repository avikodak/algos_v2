/****************************************************************************************************************************************************
 *  File Name   		: mergesortsill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture06\mergesortsill.h
 *  Created on			: Dec 12, 2014 :: 2:10:04 PM
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
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
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

#ifndef MERGESORTSILLV1_H_
#define MERGESORTSILLV1_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/


sillNode *mergeSortedSillV2(sillNode *firstCrawler,sillNode *secondCrawler){
	if(firstCrawler == null && secondCrawler == null){
		return null;
	}
	if(firstCrawler == null || secondCrawler == null){
		return firstCrawler == null?secondCrawler:firstCrawler;
	}
	sillNode *result = null,*resultCrawler;
	if(firstCrawler->value < secondCrawler->value){
		result = new sillNode(firstCrawler->value);
		firstCrawler = firstCrawler->next;
	}else{
		result = new sillNode(secondCrawler->value);
		secondCrawler = secondCrawler->next;
	}
	resultCrawler = result;
	while(firstCrawler != null || secondCrawler != null){
		if(firstCrawler == null || secondCrawler == null){
			if(firstCrawler != null){
				resultCrawler->next = new sillNode(firstCrawler->value);
				firstCrawler = firstCrawler->next;
			}else{
				resultCrawler->next = new sillNode(secondCrawler->value);
				secondCrawler = secondCrawler->next;
			}
		}else{
			if(firstCrawler->value < secondCrawler->value){
				resultCrawler->next = new sillNode(firstCrawler->value);
				firstCrawler = firstCrawler->next;
			}else{
				resultCrawler->next = new sillNode(secondCrawler->value);
				secondCrawler = secondCrawler->next;
			}
		}
	}
	return result;
}

void getMiddleSillV2(sillNode *ptr,sillNode **firstSill,sillNode **secondSill){
	if(ptr == null){
		return;
	}
	sillNode *fastPtr = ptr,*slowPtr = ptr;
	(*firstSill) = ptr;
	while(fastPtr != null){
		fastPtr = fastPtr->next;
		if(fastPtr->next != null){
			fastPtr = fastPtr->next;
			slowPtr = slowPtr->next;
		}
	}
	(*secondSill) = slowPtr->next;
	slowPtr->next = null;
	return;
}

void mergeSortSillV2(sillNode **head){
	if(*head == null){
		return;
	}
	sillNode *firstSill = null,*secondSill = null;
	getMiddleSillV2(*head,&firstSill,&secondSill);
	mergeSortSillV2(&firstSill);
	mergeSortSillV2(&secondSill);
	(*head) = mergeSortedSillV2(firstSill,secondSill);
}

#endif /* MERGESORTSILLV1_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
