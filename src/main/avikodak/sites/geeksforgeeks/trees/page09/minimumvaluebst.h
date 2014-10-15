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
