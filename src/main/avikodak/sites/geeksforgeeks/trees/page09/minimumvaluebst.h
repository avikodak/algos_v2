/****************************************************************************************************************************************************
 *  File Name   		: minimumvaluebst.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\minimumvaluebst.h
 *  Created on			: Oct 14, 2014 :: 1:10:30 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-the-minimum-element-in-a-binary-search-tree/
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
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef MINIMUMVALUEBST_H_
#define MINIMUMVALUEBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getMinimumValueFromBST(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->left == null){
		return ptr->value;
	}else{
		return getMinimumValueFromBST(ptr->left);
	}
}

//Tested
int getMinimumValueFromBSTIterative(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	while(ptr->left != null){
		ptr = ptr->left;
	}
	return ptr->value;
}

//Tested
void setMinimumValue(itNode *ptr,int &minValue){
	if(ptr == null){
		return;
	}
	minValue = min(minValue,ptr->value);
	setMinimumValue(ptr->left,minValue);
	setMinimumValue(ptr->right,minValue);
}

//Tested
int getMinimumValueFromBSTON(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	int minValue = INT_MAX;
	setMinimumValue(ptr,minValue);
	return minValue;
}

#endif /* MINIMUMVALUEBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
