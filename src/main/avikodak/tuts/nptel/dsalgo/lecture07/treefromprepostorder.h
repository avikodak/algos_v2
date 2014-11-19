/****************************************************************************************************************************************************
 *  File Name   		: treefromprepostorder.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture07\treefromprepostorder.h
 *  Created on			: Nov 18, 2014 :: 12:39:25 AM
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

#ifndef TREEFROMPREPOSTORDER_H_
#define TREEFROMPREPOSTORDER_H_

int getIndexFromPostOrder(vector<int> postOrder,int startIndex,int endIndex,int value){
	if(postOrder.size() == 0 || startIndex > endIndex){
		return INT_MIN;
	}
	for(unsigned int counter = 0;counter < postOrder.size();counter++){
		if(postOrder[counter] == value){
			return (int)counter;
		}
	}
	return INT_MIN;
}

itNode *constructTreeFromPrePostOrder(vector<int> preOrder,vector<int> postOrder,int startIndex,int endIndex){
	static int preOrderIndex = 0;
	if(preOrderIndex >= preOrder.size() || startIndex > endIndex){
		return null;
	}
	int value = preOrder[preOrderIndex];
	itNode *node = new itNode(preOrder[preOrderIndex]);
	preOrderIndex++;
	if(abs(startIndex - endIndex) < 1 || preOrderIndex >= preOrder.size()){
		return node;
	}
	int index = getIndexFromPostOrder(postOrder,startIndex,endIndex,preOrder[preOrderIndex]);
	node->left = constructTreeFromPrePostOrder(preOrder,postOrder,startIndex,index);
	node->right = constructTreeFromPrePostOrder(preOrder,postOrder,index+1,endIndex-1);
	return node;
}

#endif /* TREEFROMPREPOSTORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
