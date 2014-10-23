/****************************************************************************************************************************************************
 *  File Name   		: deletealternatenodes.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page03\deletealternatenodes.h
 *  Created on			: Oct 21, 2014 :: 12:44:27 PM
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

#ifndef DELETEALTERNATENODES_H_
#define DELETEALTERNATENODES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void deleteAlternateNodes(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return;
	}
	sillNode *nodeToBeDeleted = ptr->next;
	ptr->next = ptr->next->next;
	free(nodeToBeDeleted);
	deleteAlternateNodes(ptr->next);
}

void deleteAlternateNodesIterative(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return;
	}
	sillNode *crawler = ptr,*nodeToBeDeleted;
	while(crawler != null && crawler->next != null){
		nodeToBeDeleted = crawler->next;
		crawler->next = crawler->next->next;
		free(nodeToBeDeleted);
	}
}

void deleteAlternateNodesHashmap(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return;
	}
	map<unsigned int,sillNode *> indexNodeMap;
	map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	sillNode *crawler = ptr;
	unsigned int counter = 0;
	while(crawler != null){
		indexNodeMap.insert(pair<unsigned int,sillNode *>(++counter,crawler));
		crawler = crawler->next;
	}
	bool evenNode = false;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		if(evenNode){
			free(itToIndexNodeMap->second);
			indexNodeMap.erase(itToIndexNodeMap->first);
		}
		evenNode = !evenNode;
	}
	sillNode *prevNode = indexNodeMap.begin()->second;
	for(itToIndexNodeMap = indexNodeMap.begin()+1;itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		prevNode->next = itToIndexNodeMap->second;
		if(itToIndexNodeMap+1 == indexNodeMap.end()){
			itToIndexNodeMap->second = null;
		}
	}
}

#endif /* DELETEALTERNATENODES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
