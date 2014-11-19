/****************************************************************************************************************************************************
 *  File Name   		: printallnodesatkdistance.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\printallnodesatkdistance.h
 *  Created on			: Nov 16, 2014 :: 9:10:07 PM
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

#ifndef PRINTALLNODESATKDISTANCE_H_
#define PRINTALLNODESATKDISTANCE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void setNodesForLevelInHashmap(itNode *ptr,unsigned int currentLevel,hash_map<unsigned int,vector<itNode *> > &levelNodeMap,int key,unsigned int &keyLevel){
	if(ptr == null){
		return;
	}
	hash_map<unsigned int,list<itNode *> >::iterator itToLevelNodeMap = levelNodeMap.find(currentLevel);
	if(itToLevelNodeMap == levelNodeMap.end()){
		list<itNode *> levelList;
		levelList.push_back(ptr);
		levelNodeMap[currentLevel] = levelList;
	}else{
		itToLevelNodeMap->second.push_back(ptr);
	}
	setNodesForLevelInHashmap(ptr->left,currentLevel+1,levelNodeMap);
	setNodesForLevelInHashmap(ptr->right,currentLevel+1,levelNodeMap);
}

void printNodesAtDistanceK(itNode *ptr,int value,unsigned int kValue){
	if(ptr == null){
		return;
	}
	unsigned int keyLevel;
	hash_map<unsigned int,vector<itNode *> > levelNodeMap;
	hash_map<unsigned int,vector<itNode *> >::iterator itToLevelNodeMap;
	setNodesForLevelInHashmap(ptr,1,levelNodeMap,value,keyLevel);
	int difference = kValue - keyLevel;
	while(difference){
		itToLevelNodeMap = levelNodeMap.find(difference);
		if(itToLevelNodeMap == levelNodeMap.end()){
			break;
		}
		difference -= 1;
		for(unsigned int counter = 0;counter < itToLevelNodeMap->second.size();counter++){
			printf("%d\t",itToLevelNodeMap->second[counter]->value);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void pSetAncestorsForNode(itNode *ptr,int value,queue<itNode *> &ancestors){
	if(ptr == null){
		return false;
	}
	if(ptr->value == value){
		ancestors.push(ptr);
		return true;
	}
	bool truthValue = pSetAncestorsForNode(ptr->left,value,ancestors) || pSetAncestorsForNode(ptr->right,value,ancestors);
	if(truthValue){
		ancestors.push(ptr);
	}
	return truthValue;
}

void pPrintAllNodesAtLevel(itNode *ptr,unsigned int kLevel){
	if(ptr == null){
		return;
	}
	if(level == 0){
		printf("%d\t",ptr->value);
		return;
	}
	pPrintAllNodesAtLevel(ptr->left,kLevel-1);
	pPrintAllNodesAtLevel(ptr->right,kLevel-1);
}

void printAllNodesAtKDistance(itNode *ptr,int value,unsigned int kDistance){
	if(ptr == null){
		return;
	}
	queue<itNode *> ancestors;
	pSetAncestorsForNode(ptr,value,ancestors);
	itNode *currentNode;
	while(kDistance > 0 && !ancestors.empty()){
		currentNode = ancestors.front();
		ancestors.pop();
		pPrintAllNodesAtLevel(currentNode,kDistance);
		kDistance -= 1;
	}
}

iptNode *searchForNodes(iptNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	if(ptr->value == value){
		return ptr;
	}
	iptNode *leftResult = searchForNodes(ptr->left,value);
	if(leftResult != null){
		return leftResult;
	}
	return searchForNodes(ptr->right,value);
}

void printAllNodesAtLevel(iptNode *ptr,unsigned int level){
	if(ptr == null){
		return;
	}
	if(level == 0){
		printf("%d\t",ptr->value);
		return;
	}
	printAllNodesAtLevel(ptr->left,level-1);
	printAllNodesAtLevel(ptr->right,level-1);
}

void printAllNodesAtKDistance(iptNode *ptr,unsigned int kDistance,int value){
	if(ptr == null){
		return;
	}
	iptNode *currentNode = searchForNodes(ptr,value);
	while(currentNode != null && kDistance > 0){
		printAllNodesAtLevel(currentNode,kDistance);
		kDistance -= 1;
		currentNode = currentNode->parent;
	}
}

#endif /* PRINTALLNODESATKDISTANCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
