/****************************************************************************************************************************************************
 *  File Name   		: predecessor.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture08\predecessor.h
 *  Created on			: Nov 18, 2014 :: 8:40:33 PM
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

#ifndef PREDECESSOR_H_
#define PREDECESSOR_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *predecessor(itNode *ptr,int value){
	static bool keyFound = false;
	if(ptr == null){
		return null;
	}
	if(ptr->value == value){
		if(ptr->left != null){
			ptr = ptr->left;
			while(ptr->right != null){
				ptr = ptr->right;
			}
			return ptr;
		}
		keyFound = true;
		return null;
	}else if(ptr->value > value){
		return predecessor(ptr->left,value);
	}else{
		itNode *result = predecessor(ptr->right,value);
		if(result == null){
			return keyFound?ptr:null;
		}
		return result;
	}
}

itNode *predecessorIterative(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	itNode *probablePredecessor = null,*currentNode = ptr;
	while(currentNode != null){
		if(currentNode->value == value){
			if(currentNode->left == null){
				return probablePredecessor;
			}
			currentNode = currentNode->left;
			while(currentNode->right != null){
				currentNode = currentNode->right;
			}
			return currentNode;
		}else if(currentNode->value > value){
			currentNode = currentNode->left;
		}else{
			probablePredecessor = currentNode;
			currentNode = currentNode->right;
		}
	}
	return currentNode;
}

#endif /* PREDECESSOR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
