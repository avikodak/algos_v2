/****************************************************************************************************************************************************
 *  File Name   		: successor.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture08\successor.h
 *  Created on			: Nov 18, 2014 :: 8:40:26 PM
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

#ifndef SUCCESSOR_H_
#define SUCCESSOR_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *getSuccessor(itNode *ptr,int value){
	static bool keyFound = false;
	if(ptr == null){
		return null;
	}
	if(ptr->value == value){
		if(ptr->right != null){
			ptr = ptr->right;
			while(ptr->left != null){
				ptr = ptr->left;
			}
			return ptr;
		}
		keyFound = true;
		return null;
	}else if(ptr->value > value){
		itNode *result = getSuccessor(ptr->left,value);
		if(result == null){
			return keyFound?ptr:null;
		}
		return result;
	}else{
		return getSuccessor(ptr->right,value);
	}
}

itNode *getSuccessorIterative(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	itNode *probableSuccessor = null,*currentNode = ptr;
	while(currentNode != null){
		if(currentNode->value == value){
			if(currentNode->right == null){
				return probableSuccessor;
			}else{
				currentNode = currentNode->right;
				while(currentNode != null){
					currentNode = currentNode->left;
				}
				return currentNode;
			}
		}else if(currentNode->value > value){
			probableSuccessor = currentNode;
			currentNode = currentNode->left;
		}else{
			currentNode = currentNode->right;
		}
	}
}

#endif /* SUCCESSOR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
