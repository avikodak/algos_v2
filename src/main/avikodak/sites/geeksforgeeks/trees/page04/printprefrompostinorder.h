/****************************************************************************************************************************************************
 *  File Name   		: printprefrompostinorder.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page04\printprefrompostinorder.h
 *  Created on			: Nov 13, 2014 :: 11:55:39 PM
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

#ifndef PRINTPREFROMPOSTINORDER_H_
#define PRINTPREFROMPOSTINORDER_H_

int findIndexInInorder(vector<int> inOrder,int startIndex,int endIndex,int key){
	for(int counter = startIndex;counter <= endIndex;counter++){
		if(inOrder[counter] == key){
			return counter;
		}
	}
	return INT_MIN;
}

itNode *constructFromPostInorder(vector<int> postOrder,vector<int> inOrder,int startIndex,int endIndex){
	static int currentPostOrderIndex = postOrder.size()-1;
	if(currentPostOrderIndex < 0 || startIndex > endIndex){
		return null;
	}
	itNode *node = new itNode(postOrder[currentPostOrderIndex]);
	int index = findIndexInInorder(inOrder,startIndex,endIndex,postOrder[currentPostOrderIndex]);
	currentPostOrderIndex++;
	node->left = constructFromPostInorder(postOrder,inOrder,startIndex,index-1);
	node->right = constructFromPostInorder(postOrder,inOrder,inOrder+1,endIndex);
	return node;
}

void printPreOrderFromPostAndInorder(vector<int> postOrder,vector<int> inOrder){
	if(postOrder.size() == 0){
		return;
	}
	itNode *root = constructFromPostInorder(postOrder,inOrder,0,inOrder.size()-1);
	treeutils *utils = new treeutils();
	utils->preOrderTraversal(root);
}

#endif /* PRINTPREFROMPOSTINORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
