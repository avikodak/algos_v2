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
