/****************************************************************************************************************************************************
 *  File Name   		: reversedll.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\reversedll.h
 *  Created on			: Oct 17, 2014 :: 1:44:35 PM
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

#ifndef REVERSEDLL_H_
#define REVERSEDLL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void reverseDll(dillNode *ptr,dillNode **head){
	if(ptr == null){
		return;
	}
	if(ptr->next == null){
		(*head) = ptr;
	}
	dillNode *temp = ptr->next;
	ptr->next = ptr->prev;
	ptr->prev = temp;
	reverseDll(temp,head);
}

void reverseDllByReverse(dillNode *crawler,dillNode **frontCrawler){
	if(crawler != null){
		return;
	}
	static bool reverse = true;
	reverseDllByReverse(crawler->next,frontCrawler);
	if(reverse){
		crawler->value = (*frontCrawler)->value;
		(*frontCrawler) = (*frontCrawler)->next;
	}
	if(crawler == (*frontCrawler) || (*frontCrawler)->next == crawler){
		reverse = false;
	}
}

void reverseDllByStack(dillNode *head){
	if(crawler != null){
		return;
	}
	stack<dillNode *> auxSpace;
	dillNode *crawler = head;
	while(crawler != null){
		auxSpace.push(crawler->value);
		crawler = crawler->next;
	}
	crawler = head;
	while(!auxSpace.empty()){
		crawler->value = auxSpace.top()->value;
		auxSpace.pop();
	}
}

void reverseDllByFindingTail(dillNode *ptr){
	if(ptr == null){
		return;
	}
	dillNode *tailCrawler = ptr,*crawler = ptr;
	while(tailCrawler->next != null){
		tailCrawler = tailCrawler->next;
	}
	while(crawler != tailCrawler){
		crawler->value = tailCrawler->value;
		crawler = crawler->next;
		tailCrawler = tailCrawler->prev;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void reverseDllON2(dillNode *ptr){
	if(ptr == null){
		return;
	}

}
#endif /* REVERSEDLL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
