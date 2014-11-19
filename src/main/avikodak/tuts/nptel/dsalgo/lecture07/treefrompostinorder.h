/****************************************************************************************************************************************************
 *  File Name   		: treefrompostinorder.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture07\treefrompostinorder.h
 *  Created on			: Nov 18, 2014 :: 12:26:56 AM
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

#ifndef TREEFROMPOSTINORDER_H_
#define TREEFROMPOSTINORDER_H_

int getIndexOfValueFromInorder(vector<int> inOrder,int value,int startIndex,int endIndex){
	if(inOrder.size() == 0 || startIndex > endIndex){
		return INT_MAX;
	}
	for(int counter = startIndex;counter <= endIndex;counter++){
		if(inOrder[counter] == value){
			return counter;
		}
	}
	return INT_MAX;
}


itNode *constructTreeFromPostInorder(vector<int> postOrder,vector<int> inOrder,int startIndex,int endIndex,int &postOrderIndex){
	if(startIndex > endIndex || postOrder.size() == 0 || inOrder.size() == 0 || postOrderIndex < 0){
		return null;
	}
	int value = postOrderIndex--;
	itNode *node = new itNode(value);
	int index = getIndexOfValueFromInorder(inOrder,value,startIndex,endIndex);
	node->left = constructTreeFromPostInorder(postOrder,inOrder,startIndex,index-1,postOrderIndex);
	node->right = constructTreeFromPostInorder(postOrder,inOrder,index+1,endIndex,postOrderIndex);
	return node;
}

void setValueIndexMap(vector<int> inOrder,hash_map<int,unsigned int> &valueIndexMap){
	if(inOrder.size() == 0){
		return;
	}
	for(unsigned int counter = 0;counter < inOrder.size();counter++){
		valueIndexMap.insert(pair<int,unsigned int>(inOrder[counter],counter));
	}
}

itNode *constructTreeFromPostInOrderV2(vector<int> postOrder,vector<int> inOrder,int startIndex,int endIndex,int &postOrderIndex){
	if(startIndex > endIndex || postOrder.size() == 0 || inOrder.size() == 0 || postOrderIndex < 0){
		return null;
	}
	static hash_map<int,unsigned int> valueIndexMap;
	if(valueIndexMap.size() == 0){
		setValueIndexMap(inOrder,valueIndexMap);
	}
	int value = postOrderIndex--;
	itNode *node = new itNode(value);
	int index = valueIndexMap.find(value)->second;
	node->left = constructTreeFromPostInOrderV2(postOrder,inOrder,startIndex,index-1,postOrderIndex);
	node->right = constructTreeFromPostInOrderV2(postOrder,inOrder,index+1,endIndex,postOrderIndex);
	return node;
}

#endif /* TREEFROMPOSTINORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
