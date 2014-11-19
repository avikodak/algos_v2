/****************************************************************************************************************************************************
 *  File Name   		: largestbstsubtree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\largestbstsubtree.h
 *  Created on			: Oct 23, 2014 :: 6:12:08 PM
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

#ifndef LARGESTBSTSUBTREE_H_
#define LARGESTBSTSUBTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isTreeBST(itNode *ptr,int minValue = INT_MIN,int maxValue = INT_MAX){
	if(ptr == null){
		return true;
	}
	if(ptr->value < minValue || ptr->value > maxValue){
		return false;
	}
	return isTreeBST(ptr->left,minValue,ptr->value) && isTreeBST(ptr->right,ptr->value,maxValue);
}

unsigned int getLargestBSTSubtreeSize(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	if(isTreeBST(ptr)){
		treeutils *utils = new treeutils();
		return utils->getSizeOfTree(ptr);
	}
	return max(getLargestBSTSubtreeSize(ptr->left),getLargestBSTSubtreeSize(ptr->right));
}

int getLargestBSTSubTreeSize(itNode *ptr,int *minVal,int *maxVal,bool *isBst,int *maxSize){
	if(ptr == null){
		*isBst = true;
		return 0;
	}
	bool isLeftSubtreeBST = false,isRightSubtreeBST = false;
	int minLeftValue;
	*maxVal = INT_MIN;
	int leftSubTreeSize = getLargestBSTSubTreeSize(ptr->left,minVal,maxVal,isBst,maxSize);
	if(isBst && ptr->value >= *maxVal){
		isLeftSubtreeBST = true;
	}
	minLeftValue = *minVal;
	*minVal = INT_MAX;
	int rightSubTreeSize = getLargestBSTSubTreeSize(ptr->right,minVal,maxVal,isBst,maxSize);
	if(*isBst && ptr->value <=  *minVal){
		isRightSubtreeBST = true;
	}
	if(minLeftValue < *minVal){
		*minVal = minLeftValue;
	}
	if(ptr->value < *minVal){
		*minVal = ptr->value;
	}
	if(ptr->value > *maxVal){
		*maxVal = ptr->value;
	}
	if(isLeftSubtreeBST && isRightSubtreeBST){
		*isBst = true;
		*maxSize = max(*maxSize,1+leftSubTreeSize+rightSubTreeSize);
		return 1 + leftSubTreeSize + rightSubTreeSize;
	}else{
		isBst = false;
		return 0;
	}
}

int *largestContinousIncreasingSequenceIndexes(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	return 0;
}

unsigned int getLargestBSTSubtreeSizeInorder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	//Have to check whether the inorder traversal is in the same subtree;
	treeutils *utils = new treeutils();
 	vector<int> inorder = utils->getValuesInInorder(ptr);
 	return 0;
}
#endif /* LARGESTBSTSUBTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
