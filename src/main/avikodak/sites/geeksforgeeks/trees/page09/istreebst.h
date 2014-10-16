/****************************************************************************************************************************************************
 *  File Name   		: istreebst.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\istreebst.h
 *  Created on			: Oct 15, 2014 :: 12:25:15 PM
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

#ifndef ISTREEBST_H_
#define ISTREEBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isTreeBSTTopToBottom(itNode *ptr,int minValue = INT_MIN,int maxValue = INT_MAX){
	if(ptr == null){
		return true;
	}
	if(ptr->value < minValue || ptr->value > maxValue){
		return false;
	}
	return isTreeBSTTopToBottom(ptr->left,minValue,ptr->value) && isTreeBSTTopToBottom(ptr->right,ptr->value,maxValue);
}

bool isTreeBSTBottomToTop(itNode *ptr,int &minValue,int &maxValue){
	if(ptr == null){
		return true;
	}
	bool leftTruthValue = isTreeBSTBottomToTop(ptr->left,minValue,maxValue);
	if(!leftTruthValue){
		return false;
	}
	if(minValue != INT_MIN){
		minValue = min(minValue,ptr->value);
	}else{
		minValue = ptr->value;
	}
	bool rightTruthValue = isTreeBSTBottomToTop(ptr->right,minValue,maxValue);
	if(!rightTruthValue){
		return false;
	}
	if(ptr->value < minValue || ptr->value > maxValue){
		return false;
	}

	if(maxValue != INT_MAX){
		maxValue = max(maxValue,ptr->value); // Should be changed
	}else{
		maxValue = ptr->value;
	}
	return true;
}

//Tested
bool isTreeBSTInorderTraversal(itNode *ptr){
	if(ptr == null){
		return true;
	}
	static int prevValue = INT_MIN;
	bool leftSubtreeTruthValue = isTreeBSTInorderTraversal(ptr->left);
	if(!leftSubtreeTruthValue || ptr->value < prevValue){
		return false;
	}
	prevValue = ptr->value;
	return isTreeBSTInorderTraversal(ptr->right);
}

//Tested
bool isTreeBSTInorderTraversalV2(itNode *ptr){
	if(ptr == null){
		return null;
	}
	treeutils *utils = new treeutils();
	vector<int> inOrderValues = utils->getValuesInInorder(ptr);
	return isVectorSorted(inOrderValues);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getMinValueTree(itNode *ptr){
	if(ptr == null){
		return INT_MAX;
	}
	return min(min(ptr->value,getMinValueTree(ptr->left)),getMinValueTree(ptr->right));
}

//Tested
int getMaxValueTree(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	return max(max(ptr->value,getMaxValueTree(ptr->left)),getMaxValueTree(ptr->right));
}

//Tested
bool isTreeBSTON2(itNode *ptr){
	if(ptr == null){
		return true;
	}
	int minValue = ptr->left == null?INT_MIN:getMinValueTree(ptr->left),maxValue = ptr->right == null?INT_MAX:getMaxValueTree(ptr->right);
	if(ptr->value < minValue || ptr->value > maxValue || !isTreeBSTON2(ptr->left) || !isTreeBSTON2(ptr->right)){
		return false;
	}
	return true;
}

#endif /* ISTREEBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
