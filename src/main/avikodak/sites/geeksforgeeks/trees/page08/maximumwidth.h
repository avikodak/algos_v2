/****************************************************************************************************************************************************
 *  File Name   		: maximumwidth.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\maximumwidth.h
 *  Created on			: Oct 18, 2014 :: 2:21:52 PM
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

#ifndef MAXIMUMWIDTH_H_
#define MAXIMUMWIDTH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void setLevelCountPreOrder(itNode *ptr,unsigned int level,hash_map<unsigned int,unsigned int> &levelFrequency){
	if(ptr == null){
		return;
	}
	if(levelFrequency.find(level) != levelFrequency.end()){
		levelFrequency[level] += 1;
	}else{
		levelFrequency[level] = 1;
	}
	setLevelCountPreOrder(ptr->left,level+1,levelFrequency);
	setLevelCountPreOrder(ptr->right,level+1,levelFrequency);
}

unsigned int getMaxWidthPreOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	hash_map<uint32_t,unsigned int> nodeLevelMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeLevelMap;
	hash_map<unsigned int,unsigned int> levelFrequency;
	hash_map<unsigned int,unsigned int>::iterator itToLevelFrequency;
	stack<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	levelFrequency.insert(pair<unsigned int,unsigned int>(1,1));
	unsigned int maxWidth = 0;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
		itToLevelFrequency = levelFrequency.find(itToNodeLevelMap->second + 1);
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
			if(itToLevelFrequency == levelFrequency.end()){
				levelFrequency[itToLevelFrequency->second + 1] = 1;
				maxWidth = max(maxWidth,1);
			}else{
				levelFrequency[itToLevelFrequency->second + 1] += 1;
				maxWidth = max(maxWidth,levelFrequency[itToLevelFrequency->second + 1]);
			}
		}
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
			if(itToLevelFrequency == levelFrequency.end()){
				levelFrequency[itToLevelFrequency->second + 1] = 1;
				maxWidth = max(maxWidth,1);
			}else{
				levelFrequency[itToLevelFrequency->second + 1] += 1;
				maxWidth = max(maxWidth,levelFrequency[itToLevelFrequency->second + 1]);
			}
		}
	}
	return maxWidth;
}

void setLevelCountInOrder(itNode *ptr,unsigned int level,hash_map<unsigned int,unsigned int> &levelFrequency){
	if(ptr == null){
		return;
	}
	setLevelCountInOrder(ptr->left,level+1,levelFrequency);
	if(levelFrequency.find(level) != levelFrequency.end()){
		levelFrequency[level] += 1;
	}else{
		levelFrequency[level] = 1;
	}
	setLevelCountInOrder(ptr->right,level+1,levelFrequency);
}

void setLevelCountPostOrder(itNode *ptr,unsigned int level,hash_map<unsigned int,unsigned int> &levelFrequency){
	if(ptr == null){
		return;
	}
	setLevelCountPostOrder(ptr->left,level-1,levelFrequency);
	setLevelCountPostOrder(ptr->right,level-1,levelFrequency);
	if(levelFrequency.find(level) != levelFrequency.end()){
		levelFrequency[level] += 1;
	}else{
		levelFrequency[level] = 1;
	}
}

void getMaxWidthLevelOrder(itNode *ptr){
	if(ptr == null){
		return;
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

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int widthOfLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return 0;
	}
	if(level == 0){
		return 1;
	}
	return widthOfLevel(ptr->left,level-1) + widthOfLevel(ptr->right,level-1);
}

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
