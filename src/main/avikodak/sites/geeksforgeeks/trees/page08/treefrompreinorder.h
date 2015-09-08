/****************************************************************************************************************************************************
 *  File Name   		: treefrompreinorder.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\treefrompreinorder.h
 *  Created on			: Oct 18, 2014 :: 2:10:25 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
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

#ifndef TREEFROMPREINORDER_H_
#define TREEFROMPREINORDER_H_

//Tested
itNode *getTreeFromPreInorderMain(vector<int> preOrder,vector<int> inOrder,int startInOrderIndex,int endInOrderIndex){
	static unsigned int preOrderIndex = 0;
	if(preOrderIndex >= preOrder.size() || startInOrderIndex > endInOrderIndex){
		return null;
	}
	itNode *node = new itNode(preOrder[preOrderIndex]);
	int counter = startInOrderIndex;
	while(counter <= endInOrderIndex && inOrder[counter] != preOrder[preOrderIndex]){
		counter++;
	}
	if(counter > endInOrderIndex){
		throw "Invalid sequence";
	}
	preOrderIndex++;
	int difference = counter - startInOrderIndex;
	node->left =  getTreeFromPreInorderMain(preOrder,inOrder,startInOrderIndex,startInOrderIndex+difference-1);
	node->right =  getTreeFromPreInorderMain(preOrder,inOrder,startInOrderIndex+difference+1,endInOrderIndex);
	return node;
}

//Tested
itNode *getTreeFromPreInorder(vector<int> preOrder,vector<int> inOrder){
	if(preOrder.size() != inOrder.size()){
		throw "Invalid inputs";
	}
	return getTreeFromPreInorderMain(preOrder,inOrder,0,inOrder.size()-1);
}

#endif /* TREEFROMPREINORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
