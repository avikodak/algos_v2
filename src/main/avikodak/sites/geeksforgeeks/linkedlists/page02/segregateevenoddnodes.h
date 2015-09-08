/****************************************************************************************************************************************************
 *  File Name   		: segregateevenoddnodes.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page02\segregateevenoddnodes.h
 *  Created on			: Oct 30, 2014 :: 10:58:43 AM
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
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SEGREGATEEVENODDNODES_H_
#define SEGREGATEEVENODDNODES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void swapValue(sillNode *firstPtr,sillNode *secondPtr){
	int temp = firstPtr->value;
	firstPtr->value = secondPtr->value;
	secondPtr->value = temp;
}

void segregateEvenOddNodes(sillNode **ptr){
	if(*ptr == null || (*ptr)->next == null){
		return;
	}
	sillNode *tail = (*ptr),*crawler = (*ptr),*ptrToFirstOddNode = null,*ptrToFirstEvenNode;
	while(tail->next != null){
		tail = tail->next;
	}
	while(crawler != ptrToFirstOddNode){
		if(crawler->value % 2 == 0){
			if(ptrToFirstEvenNode == null){
				ptrToFirstEvenNode = crawler;
			}
			crawler = crawler->next;
		}else{
			if(ptrToFirstOddNode == null){
				ptrToFirstOddNode = crawler;
			}
			if(crawler->next != null){
				swapValue(crawler,crawler->next);
				tail->next = crawler->next;
				crawler->next = crawler->next->next;
				tail = tail->next;
				tail->next = null;
			}
		}
	}
}

void segregateEventOddNodesTwoPtrs(sillNode **ptr){
	if(*ptr == null || (*ptr)->next == null){
		return;
	}
	sillNode *evenHead = null,*oddHead = null,*evenCrawler = null,*oddCrawler = null,*crawler = (*ptr);
	while(crawler != null){
		if(crawler->value % 2 == 0){
			if(evenHead == null){
				evenHead = crawler;
				evenCrawler = evenCrawler;
			}else{
				evenCrawler->next = crawler;
				evenCrawler = evenCrawler->next;
			}
		}else{
			if(oddHead == null){
				oddHead = crawler;
				oddCrawler = oddCrawler;
			}else{
				oddCrawler->next = crawler;
				oddCrawler = oddCrawler->next;
			}
		}
		crawler = crawler->next;
	}
	if(evenHead != null){
		(*ptr) = evenHead;
		evenCrawler->next = oddHead;
		oddCrawler->next = null;
	}else{
		oddCrawler->next = null;
		(*ptr) = oddHead;
	}
}

void segregateEvenOddNodesAuxspace(sillNode **ptr){
	if(*ptr == null || (*ptr)->next == null){
		return;
	}
	queue<sillNode *> evenAuxspace,oddAuxspace;
	sillNode *currentNode = *ptr,*prevNode = null;
	while(currentNode != null){
		if(currentNode->value % 2 == 0){
			evenAuxspace.push(currentNode);
		}else{
			oddAuxspace.push(currentNode);
		}
	}
	if(evenAuxspace.empty()){
		(*ptr) = oddAuxspace.front();
		prevNode = oddAuxspace.front();
		oddAuxspace.pop();
		while(!oddAuxspace.empty()){
			prevNode->next = oddAuxspace.front();
			oddAuxspace.pop();
			prevNode = prevNode->next;
		}
		prevNode->next = null;
	}else{
		(*ptr) = evenAuxspace.front();
		prevNode = evenAuxspace.front();
		evenAuxspace.pop();
		while(!evenAuxspace.empty()){
			prevNode->next = evenAuxspace.front();
			evenAuxspace.pop();
			prevNode = prevNode->next;
		}
		while(!oddAuxspace.empty()){
			prevNode->next = oddAuxspace.front();
			oddAuxspace.pop();
			prevNode = prevNode->next;
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* SEGREGATEEVENODDNODES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
