/****************************************************************************************************************************************************
 *  File Name   		: movelastelementtofirst.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page03\movelastelementtofirst.h
 *  Created on			: Oct 19, 2014 :: 1:01:44 PM
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef MOVELASTELEMENTTOFIRST_H_
#define MOVELASTELEMENTTOFIRST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void moveLastElementToFirst(sillNode *ptr,sillNode **head){
	if(ptr == null || ptr->next == null){
		return;
	}
	if(ptr->next->next == null){
		ptr->next->next = (*head);
		(*head) = ptr->next;
		ptr->next = null;
		return;
	}
	moveLastElementToFirst(ptr->next,head);
}

void moveLastElementToFirstIterative(sillNode **head){
	if(*head == null || (*head)->next == null){
		return;
	}
	sillNode *crawler = (*head);
	while(crawler->next->next != null){
		crawler = crawler->next;
	}
	crawler->next->next = (*head);
	(*head) = crawler->next;
	crawler->next = null;
}

void moveLastElementToFirstAuxspace(sillNode *head){
	if(head == null || head->next == null){
		return;
	}
	queue<int> auxSpace;
	sillNode *crawler = head;
	while(crawler->next != null){
		auxSpace.push(crawler->value);
	}
	head->value = crawler->value;
	crawler = head->next;
	while(!auxSpace.empty()){
		crawler->value = auxSpace.front();
		auxSpace.pop();
		crawler = crawler->next;
	}
}

void moveLastElementToFirstHashmap(sillNode *head){
	if(head == null || head->next == null){
		return;
	}
	hash_map<unsigned int,int> rankValueMap;
	hash_map<unsigned int,int>::iterator itToRankValueMap;
	unsigned int counter = 0;
	sillNode *crawler = head;
	while(crawler != null){
		rankValueMap.insert(pair<unsigned int,int>(counter,crawler->value));
		counter++;
		crawler = crawler->next;
	}
	crawler = head;
	crawler->value = rankValueMap.find(rankValueMap.size()-1)->second;
	crawler = crawler->next;
	for(itToRankValueMap = rankValueMap.begin();itToRankValueMap != rankValueMap.end()-1;itToRankValueMap++){
		crawler->value = itToRankValueMap->second;
		crawler = crawler->next;
	}
}

#endif /* MOVELASTELEMENTTOFIRST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
