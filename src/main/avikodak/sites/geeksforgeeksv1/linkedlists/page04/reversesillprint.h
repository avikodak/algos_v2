/****************************************************************************************************************************************************
 *  File Name   		: reversesillprint.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\reversesillprint.h
 *  Created on			: Oct 16, 2014 :: 10:31:12 AM
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

#include "../../../geeksforgeeksv1/linkedlists/page04/reversesill.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef REVERSESILLPRINT_H_
#define REVERSESILLPRINT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void reverseSillPrint(sillNode *ptr){
	if(ptr == null){
		return;
	}
	reverseSillPrint(ptr->next);
	printf("%d\t",ptr->value);
}

//Tested
void reverseSillPrintAuxspace(sillNode *ptr){
	if(ptr == null){
		return;
	}
	stack<sillNode *> auxSpace;
	while(ptr != null){
		auxSpace.push(ptr);
		ptr = ptr->next;
	}
	while(!auxSpace.empty()){
		printf("%d\t",auxSpace.top()->value);
		auxSpace.pop();
	}
}

//Tested
void reverseSillPrintByReversing(sillNode *ptr){
	if(ptr == null){
		return;
	}
	reverseSill(&ptr);
	while(ptr != null){
		printf("%d\t",ptr->value);
		ptr = ptr->next;
	}
}

//Tested
void reverseSillHashmap(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> indexNodeMap = utils->getSillAsHashmap(ptr,1)->indexNodeMap;
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	unsigned int lengthOfSill = utils->lengthOfSill(ptr);
	while(lengthOfSill > 0){
		itToIndexNodeMap = indexNodeMap.find(lengthOfSill);
		printf("%d\t",itToIndexNodeMap->second->value);
		lengthOfSill -= 1;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void reverseSillON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	unsigned int length = utils->lengthOfSill(ptr),difference;
	sillNode *crawler;
	for(unsigned int counter = 0;counter < length;counter++){
		difference = length - counter - 1;
		crawler = ptr;
		while(difference--){
			crawler = crawler->next;
		}
		printf("%d\t",crawler->value);
	}
}

#endif /* REVERSESILLPRINT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
