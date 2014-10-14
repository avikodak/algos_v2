/****************************************************************************************************************************************************
 *  File Name   		: deletesill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page05\deletesill.h
 *  Created on			: Oct 12, 2014 :: 5:58:52 PM
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

#ifndef DELETESILL_H_
#define DELETESILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void deleteSillMainTailRecursion(sillNode *ptr){
	if(ptr == null){
		return;
	}
	deleteSillMainTailRecursion(ptr->next);
	free(ptr);
}

//Tested
void deleteSillTailRecusion(sillNode **ptr){
	if(*ptr == null){
		return;
	}
	deleteSillMainTailRecursion(*ptr);
	(*ptr) = null;
}

//Tested
void deleteSillMain(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *temp = ptr->next;
	free(ptr);
	deleteSillMain(temp);
}

//Tested
void deleteSill(sillNode **ptr){
	if(*ptr == null){
		return;
	}
	deleteSillMain(*ptr);
	(*ptr) = null;
}

//Tested
void deleteSillIterative(sillNode **ptr){
	if(*ptr == null){
		return;
	}
	stack<sillNode *> auxSpace;
	sillNode *crawler = *ptr;
	while(crawler != null){
		auxSpace.push(crawler);
		crawler = crawler->next;
	}
	while(!auxSpace.empty()){
		crawler = auxSpace.top();
		auxSpace.pop();
		free(crawler);
	}
	(*ptr) = null;
}

//Tested
void deleteSillIterativeV2(sillNode **ptr){
	if(*ptr == null){
		return;
	}
	sillNode *temp,*nodeToBeDeleted = *ptr;
	do{
		temp = nodeToBeDeleted->next;
		free(nodeToBeDeleted);
		nodeToBeDeleted = temp;
	}while(temp != null);
	(*ptr) = null;
}

//Tested
void deleteSillHashmap(sillNode **ptr){
	if(*ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> indexNodeMap = utils->getSillAsHashmap(*ptr)->indexNodeMap;
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		free(itToIndexNodeMap->second);
	}
	(*ptr) = null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* DELETESILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
