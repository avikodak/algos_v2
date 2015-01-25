/****************************************************************************************************************************************************
 *  File Name   		: cousinstree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\cousinstree.h
 *  Created on			: Jan 24, 2015 :: 12:39:27 AM
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
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
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

#ifndef COUSINSTREE_H_
#define COUSINSTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool areNodesSibilings(itNode *ptr,int firstValue,int secondValue){
	if(ptr == null){
		return false;
	}
	if(ptr->left != null && ptr->right != null){
		return (ptr->left->value == firstValue && ptr->right->value == secondValue) || (ptr->left->value == secondValue && ptr->right->value == firstValue);
	}
	return areNodesSibilings(ptr->left,firstValue,secondValue) || areNodesSibilings(ptr->right,firstValue,secondValue);
}

int levelOfNode(itNode *ptr,int userInput,int level){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->value == userInput){
		return level;
	}
	int leftResult = levelOfNode(ptr->left,userInput,level+1);
	if(leftResult != null){
		return leftResult;
	}
	return levelOfNode(ptr->right,userInput,level+1);
}

bool areNodesCousins(itNode *ptr,int firstValue,int secondValue){
	if(levelOfNode(ptr,firstValue,0) && levelOfNode(ptr,secondValue,0) && !areNodesSibilings(ptr,firstValue,secondValue)){
		return true;
	}
	return false;
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(2^N) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* COUSINSTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
