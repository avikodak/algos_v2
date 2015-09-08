/****************************************************************************************************************************************************
 *  File Name   		: maximumwidth.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\maximumwidth.h
 *  Created on			: Oct 18, 2014 :: 2:21:52 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/maximum-width-of-a-binary-tree/
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

#ifndef MAXIMUMWIDTH_H_
#define MAXIMUMWIDTH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void setLevelCountPreOrderMain(itNode *ptr,unsigned int level,hash_map<unsigned int,unsigned int> &levelFrequency){
	if(ptr == null){
		return;
	}
	if(levelFrequency.find(level) != levelFrequency.end()){
		levelFrequency[level] += 1;
	}else{
		levelFrequency[level] = 1;
	}
	setLevelCountPreOrderMain(ptr->left,level+1,levelFrequency);
	setLevelCountPreOrderMain(ptr->right,level+1,levelFrequency);
}

//Tested
unsigned int maximumWidthPreOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	hash_map<unsigned int,unsigned int> levelFrequency;
	setLevelCountPreOrderMain(ptr,0,levelFrequency);
	hash_map<unsigned int,unsigned int>::iterator itToLevelFrequency;
	unsigned int maxWidth = 0;
	for(itToLevelFrequency = levelFrequency.begin();itToLevelFrequency != levelFrequency.end();itToLevelFrequency++){
		maxWidth = max(maxWidth,itToLevelFrequency->second);
	}
	return maxWidth;
}

//Tested
unsigned int getMaxWidthPreOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	hash_map<intptr_t,unsigned int> nodeLevelMap;
	hash_map<intptr_t,unsigned int>::iterator itToNodeLevelMap;
	hash_map<unsigned int,unsigned int> levelFrequency;
	hash_map<unsigned int,unsigned int>::iterator itToLevelFrequency;
	stack<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	nodeLevelMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,1));
	levelFrequency.insert(pair<unsigned int,unsigned int>(1,1));
	unsigned int maxWidth = 0;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		itToNodeLevelMap = nodeLevelMap.find((intptr_t)currentNode);
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
			nodeLevelMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,itToNodeLevelMap->second+1));
			itToLevelFrequency = levelFrequency.find(itToNodeLevelMap->second + 1);
			if(itToLevelFrequency == levelFrequency.end()){
				levelFrequency.insert(pair<unsigned int,unsigned int>(itToNodeLevelMap->second + 1, 1));
				maxWidth = maxWidth > 1?maxWidth:1;
			}else{
				levelFrequency[itToNodeLevelMap->second + 1] += 1;
				maxWidth = max(maxWidth,levelFrequency[itToNodeLevelMap->second + 1]);
			}
		}
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
			nodeLevelMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->right,itToNodeLevelMap->second+1));
			itToLevelFrequency = levelFrequency.find(itToNodeLevelMap->second + 1);
			if(itToLevelFrequency == levelFrequency.end()){
				levelFrequency.insert(pair<unsigned int,unsigned int>(itToNodeLevelMap->second + 1, 1));
				maxWidth = maxWidth > 1?maxWidth:1;
			}else{
				levelFrequency[itToNodeLevelMap->second + 1] += 1;
				maxWidth = max(maxWidth,levelFrequency[itToNodeLevelMap->second + 1]);
			}
		}
	}
	return maxWidth;
}

//Tested
void setLevelCountInOrderMain(itNode *ptr,unsigned int level,hash_map<unsigned int,unsigned int> &levelFrequency){
	if(ptr == null){
		return;
	}
	setLevelCountInOrderMain(ptr->left,level+1,levelFrequency);
	if(levelFrequency.find(level) != levelFrequency.end()){
		levelFrequency[level] += 1;
	}else{
		levelFrequency[level] = 1;
	}
	setLevelCountInOrderMain(ptr->right,level+1,levelFrequency);
}

//Tested
unsigned int maximumWidthInOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	hash_map<unsigned int,unsigned int> levelFrequency;
	setLevelCountInOrderMain(ptr,0,levelFrequency);
	hash_map<unsigned int,unsigned int>::iterator itToLevelFrequency;
	unsigned int maxWidth = 0;
	for(itToLevelFrequency = levelFrequency.begin();itToLevelFrequency != levelFrequency.end();itToLevelFrequency++){
		maxWidth = max(maxWidth,itToLevelFrequency->second);
	}
	return maxWidth;
}

//Tested
void setLevelCountPostOrderMain(itNode *ptr,unsigned int level,hash_map<unsigned int,unsigned int> &levelFrequency){
	if(ptr == null){
		return;
	}
	setLevelCountPostOrderMain(ptr->left,level-1,levelFrequency);
	setLevelCountPostOrderMain(ptr->right,level-1,levelFrequency);
	if(levelFrequency.find(level) != levelFrequency.end()){
		levelFrequency[level] += 1;
	}else{
		levelFrequency[level] = 1;
	}
}

//Tested
unsigned int maximumWidthPostOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	hash_map<unsigned int,unsigned int> levelFrequency;
	setLevelCountPostOrderMain(ptr,0,levelFrequency);
	hash_map<unsigned int,unsigned int>::iterator itToLevelFrequency;
	unsigned int maxWidth = 0;
	for(itToLevelFrequency = levelFrequency.begin();itToLevelFrequency != levelFrequency.end();itToLevelFrequency++){
		maxWidth = max(maxWidth,itToLevelFrequency->second);
	}
	return maxWidth;
}

//Tested
unsigned int getMaxWidthLevelOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	unsigned int counter,maxWidth = 0;
	while(!auxSpace.empty()){
		counter = auxSpace.size();
		maxWidth = max(maxWidth,counter);
		while(counter--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
	}
	return maxWidth;
}

//Tested
inrNode *wGetNextRight(inrNode *ptr){
	if(ptr == null){
		return null;
	}
	while(ptr != null){
		if(ptr->left != null){
			return ptr->left;
		}else if(ptr->right != null){
			return ptr->right;
		}
		ptr = ptr->nextRight;
	}
	return null;
}

//Tested
void wConnectNodesInSameLevel(inrNode *ptr){
	if(ptr == null){
		return;
	}
	wConnectNodesInSameLevel(ptr->nextRight);
	if(ptr->left != null){
		if(ptr->right != null){
			ptr->left->nextRight = ptr->right;
			ptr->right->nextRight = wGetNextRight(ptr->nextRight);
		}else{
			ptr->left->nextRight = wGetNextRight(ptr->nextRight);
		}
		wConnectNodesInSameLevel(ptr->left);
	}else if(ptr->right != null){
		ptr->right->nextRight = wGetNextRight(ptr->nextRight);
		wConnectNodesInSameLevel(ptr->right);
	}else{
		wConnectNodesInSameLevel(wGetNextRight(ptr->nextRight));
	}
}

//Tested
unsigned int getLevelWidthAfterConnectingLevel(inrNode *ptr){
	if(ptr == null){
		return 0;
	}
	return 1 + getLevelWidthAfterConnectingLevel(ptr->nextRight);
}

//Tested
unsigned int getMaxWidthConnectingLevel(inrNode *ptr){
	if(ptr == null){
		return 0;
	}
	wConnectNodesInSameLevel(ptr);
	unsigned int maxWidth = 0;
	while(ptr != null){
		maxWidth = max(maxWidth,getLevelWidthAfterConnectingLevel(ptr));
		if(ptr->left != null){
			ptr = ptr->left;
		}else if(ptr->right != null){
			ptr = ptr->right;
		}else{
			ptr = wGetNextRight(ptr);
		}
	}
	return maxWidth;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int widthOfLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return 0;
	}
	if(level == 0){
		return 1;
	}
	return widthOfLevel(ptr->left,level-1) + widthOfLevel(ptr->right,level-1);
}

//Tested
unsigned int getMaxWidthLevelOrderON2(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->getHeightOfTree(ptr);
	unsigned int width = 0;
	for(unsigned int counter = 0;counter < height;counter++){
		width = max(width,widthOfLevel(ptr,counter));
	}
	return width;
}

#endif /* MAXIMUMWIDTH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
