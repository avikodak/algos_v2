/****************************************************************************************************************************************************
 *  File Name   		: treefromlevelinorder.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\treefromlevelinorder.h
 *  Created on			: Nov 16, 2014 :: 10:37:08 AM
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

#ifndef TREEFROMLEVELINORDER_H_
#define TREEFROMLEVELINORDER_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getIndexFromInorder(vector<int> inorder,int value,int startIndex,int endIndex){
	for(int counter = startIndex;counter <= endIndex;counter++){
		if(inorder[counter] == value){
			return counter;
		}
	}
	return -1;
}

//Tested
void setLevelOrderNodes(vector<int> inorder,vector<int> levelOrder,int leftStartIndex,int leftEndIndex,vector<int> &leftLevelOrder,vector<int> &rightLevelOrder){
	if(inorder.size() == 0 || levelOrder.size() == 0){
		return;
	}
	bool flag;
	for(unsigned int outerCounter = 1;outerCounter < levelOrder.size();outerCounter++){
		flag = false;
		for(int index = leftStartIndex;index <= leftEndIndex;index++){
			if(levelOrder[outerCounter] == inorder[index]){
				leftLevelOrder.push_back(levelOrder[outerCounter]);
				flag = true;
				break;
			}
		}
		if(!flag){
			rightLevelOrder.push_back(levelOrder[outerCounter]);
		}
	}
}

//Tested
itNode *treeFromLevelInOrder(vector<int> inorder,vector<int> levelOrder,int startInorderIndex,int endInorderIndex){
	if(levelOrder.size() == 0 || inorder.size() == 0 || startInorderIndex > endInorderIndex){
		return null;
	}
	itNode *root = new itNode(levelOrder[0]);
	if(levelOrder.size() == 1){
		return root;
	}
	int index = getIndexFromInorder(inorder,levelOrder[0],startInorderIndex,endInorderIndex);
	vector<int> leftLevelOrder,rightLevelOrder;
	setLevelOrderNodes(inorder,levelOrder,startInorderIndex,index,leftLevelOrder,rightLevelOrder);
	root->left = treeFromLevelInOrder(inorder,leftLevelOrder,startInorderIndex,index-1);
	root->right = treeFromLevelInOrder(inorder,rightLevelOrder,index+1,endInorderIndex);
	return root;
}

#endif /* TREEFROMLEVELINORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
