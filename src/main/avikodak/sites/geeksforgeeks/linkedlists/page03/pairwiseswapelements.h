/****************************************************************************************************************************************************
 *  File Name   		: pairwiseswapelements.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page03\pairwiseswapelements.h
 *  Created on			: Oct 19, 2014 :: 1:01:58 PM
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

#ifndef PAIRWISESWAPELEMENTS_H_
#define PAIRWISESWAPELEMENTS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void pairwiseSwapElements(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return;
	}
	int temp = ptr->value;
	ptr->value = ptr->next->value;
	ptr->next->value = temp;
	pairwiseSwapElements(ptr->next->next);
}

void pairwiseSwapElementsIterative(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return;
	}
	sillNode *crawler = ptr;
	while(crawler != null && crawler->next != null){
		int temp = crawler->value;
		crawler->value = crawler->next->value;
		crawler->next->value = temp;
		crawler = crawler->next->next;
	}
}

void pairwiseSwapElementsHashmap(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return;
	}
	hash_map<unsigned int,int> rankValueMap;
	hash_map<unsigned int,int>::iterator itToRankValueMap;
	sillNode *crawler = ptr;
	unsigned int counter = 1;
	while(crawler != null){
		rankValueMap.insert(pair<unsigned int,int>(counter,crawler->value));
		crawler = crawler->next;
		counter++;
	}
	crawler = ptr;
	for(unsigned int counter = 1;counter+1 < rankValueMap.size();counter+=2){
		crawler->value = rankValueMap.find(counter+1)->second;
		crawler->next->value = rankValueMap.find(counter)->second;
		crawler = crawler->next->next;
	}
}

void pairwiseElementsSwapPtrExchange(sillNode **ptr){

}

void pairwiseElementsSwapPtrExchangeIterative(sillNode *ptr){

}
#endif /* PAIRWISESWAPELEMENTS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
