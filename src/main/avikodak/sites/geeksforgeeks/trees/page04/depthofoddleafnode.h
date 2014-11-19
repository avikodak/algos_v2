/****************************************************************************************************************************************************
 *  File Name   		: depthofoddleafnode.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page04\depthofoddleafnode.h
 *  Created on			: Nov 14, 2014 :: 12:04:40 AM
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

#ifndef DEPTHOFODDLEAFNODE_H_
#define DEPTHOFODDLEAFNODE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int depthOfOddLeafNode(itNode *ptr,unsigned int currentLevel = 1){
	if(ptr == null){
		return 0;
	}
	if(ptr->left == null && ptr->right == null){
		return currentLevel%2?0:currentLevel;
	}
	return max(depthOfOddLeafNode(ptr->left,currentLevel+1),depthOfOddLeafNode(ptr->right,currentLevel+1));
}

unsigned int depthOfOddLeafNode(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	queue<itNode *> auxSpace;
	unsigned int levelCounter = 0,nodeCounter,oddLevel = 0;
	auxSpace.push(ptr);
	itNode *currentNode = ptr;
	while(!auxSpace.empty()){
		nodeCounter = auxSpace.size();
		levelCounter++;
		while(nodeCounter--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(currentNode->left == null && currentNode->right == null){
				if(levelCounter%2){
					oddLevel = max(oddLevel,levelCounter);
				}
			}else{
				if(currentNode->left != null){
					auxSpace.push(currentNode->left);
				}
				if(currentNode->right != null){
					auxSpace.push(currentNode->right);
				}
			}
		}
	}
	return oddLevel;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isLeafPresentInLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return false;
	}
	if(level == 0){
		return ptr->left == null && ptr->right == null;
	}
	return isLeafPresentInLevel(ptr->left,level) || isLeafPresentInLevel(ptr->right,level);
}

unsigned int getDepthOfOddLeafNode(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->getHeightOfTree(ptr);
	unsigned int oddLevel = 0;
	for(unsigned int counter = 0;counter < height;counter += 2){
		if(isLeafPresentInLevel(ptr,counter)){
			oddLevel = max(oddLevel,counter) + 1;
		}
	}
	return oddLevel;
}

#endif /* DEPTHOFODDLEAFNODE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
