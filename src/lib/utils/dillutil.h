/****************************************************************************************************************************************************
 *  File Name   		: dillutil.h 
 *	File Location		: D:\algos\algos_v2\src\lib\utils\dillutil.h
 *  Created on			: Oct 9, 2014 :: 12:36:51 PM
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
#include <stdint.h>
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef DILLUTIL_H_
#define DILLUTIL_H_

class dillutils {
private:
public:
	dillNode *getDillFromVector(vector<int> userInput,unsigned int currentIndex = 0){
		if(currentIndex >= userInput.size()){
			return null;
		}
		dillNode *node = new dillNode(userInput[currentIndex]);
		node->next = getDillFromVector(userInput,currentIndex+1);
		if(node->next != null){
			node->next->prev = node;
		}
		return node;
	}

	unsigned int getLengthOfDill(dillNode *ptr){
		return ptr == null?0:1+getLengthOfDill(ptr->next);
	}

	iDillHashmap *getDillAsHashmap(dillNode *ptr,unsigned int startIndex = 0){
		if(ptr == null){
			return null;
		}
		hash_map<unsigned int,dillNode *> indexNodeMap;
		hash_map<intptr_t,unsigned int> nodeIndexMap;
		hash_map<unsigned int,dillNode *>::iterator itToIndexNodeMap;
		hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
		while(ptr != null){
			nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,startIndex));
			indexNodeMap.insert(pair<unsigned int,dillNode *>(startIndex,ptr));
			startIndex += 1;
			ptr = ptr->next;
		}
		iDillHashmap *hashmapOfDill = new iDillHashmap();
		hashmapOfDill->indexNodeMap = indexNodeMap;
		hashmapOfDill->nodeIndexMap = nodeIndexMap;
		return hashmapOfDill;
	}
};

#endif /* DILLUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
