/****************************************************************************************************************************************************
 *  File Name   		: constructtreefromprepostspecial.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\constructtreefromprepostspecial.h
 *  Created on			: Nov 1, 2014 :: 6:37:18 PM
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

#ifndef CONSTRUCTTREEFROMPREPOSTSPECIAL_H_
#define CONSTRUCTTREEFROMPREPOSTSPECIAL_H_

//Tested
int getIndexOfNodeInPostOrder(vector<int> postOrder,int startIndex,int endIndex,int value){
	for(int counter = startIndex;counter <= endIndex;counter++){
		if(postOrder[counter] == value){
			return counter;
		}
	}
	return INT_MAX;
}

//Tested
itNode *getTreeFromPrePostOrder(vector<int> preOrder,vector<int> postOrder,int startIndex,int endIndex){
	static int preOrderIndex = 0;
	if(preOrderIndex >= (int)preOrder.size() || startIndex > endIndex){
		return null;
	}
	itNode *root = new itNode(preOrder[preOrderIndex]);
	preOrderIndex++;
	if(startIndex == endIndex || preOrderIndex >= (int)preOrder.size()){
		return root;
	}
	int indexOfValueInPostOrder = getIndexOfNodeInPostOrder(postOrder,startIndex,endIndex,preOrder[preOrderIndex]);
	root->left = getTreeFromPrePostOrder(preOrder,postOrder,startIndex,indexOfValueInPostOrder);
	root->right = getTreeFromPrePostOrder(preOrder,postOrder,indexOfValueInPostOrder+1,endIndex-1);
	return root;
}

#endif /* CONSTRUCTTREEFROMPREPOSTSPECIAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

