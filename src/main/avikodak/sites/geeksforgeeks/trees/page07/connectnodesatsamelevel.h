/****************************************************************************************************************************************************
 *  File Name   		: connectnodesatsamelevel.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\connectnodesatsamelevel.h
 *  Created on			: Oct 23, 2014 :: 12:06:51 PM
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

#ifndef CONNECTNODESATSAMELEVEL_H_
#define CONNECTNODESATSAMELEVEL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void cConnectNodesAtSameLevelOrder(inrNode *ptr){
	if(ptr == null){
		return;
	}
	queue<inrNode *> auxSpace;
	inrNode *currentNode;
	auxSpace.push(ptr);
	unsigned int levelCounter;
	inrNode *prevNode;
	while(!auxSpace.empty()){
		levelCounter = auxSpace.size();
		prevNode = null;
		while(levelCounter--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(prevNode != null){
				prevNode->nextRight = currentNode;
			}
			prevNode = currentNode;
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
		prevNode->nextRight = null;
	}
}

//Tested
void connectNodesAtSameLevelPreOrder(inrNode *ptr,unsigned int level = 0){
	if(ptr == null){
		return;
	}
	static hash_map<unsigned int,inrNode *> prevNodesLevelMap;
	hash_map<unsigned int,inrNode *>::iterator itToPrevNodesLevelMap;
	if((itToPrevNodesLevelMap = prevNodesLevelMap.find(level)) == prevNodesLevelMap.end()){
		ptr->nextRight = null;
		prevNodesLevelMap.insert(pair<unsigned int,inrNode *>(level,ptr));
	}else{
		ptr->nextRight = itToPrevNodesLevelMap->second;
		prevNodesLevelMap[level] = ptr;
	}
	connectNodesAtSameLevelPreOrder(ptr->right,level+1);
	connectNodesAtSameLevelPreOrder(ptr->left,level+1);
}

//Tested
inrNode *cGetNextRight(inrNode *ptr){
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
void connectNodesAtSameLevelNextRightPreorderMain(inrNode *ptr){
	if(ptr == null){
		return;
	}
	connectNodesAtSameLevelNextRightPreorderMain(ptr->nextRight);
	if(ptr->left != null){
		if(ptr->right != null){
			ptr->left->nextRight = ptr->right;
			ptr->right->nextRight = cGetNextRight(ptr->nextRight);
		}else{
			ptr->left->nextRight = cGetNextRight(ptr->nextRight);
		}
		connectNodesAtSameLevelNextRightPreorderMain(ptr->left);
	}else if(ptr->right != null){
		ptr->right->nextRight = cGetNextRight(ptr->nextRight);
		connectNodesAtSameLevelNextRightPreorderMain(ptr->right);
	}else{
		connectNodesAtSameLevelNextRightPreorderMain(getNextRight(ptr->nextRight));
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void connectNodesAtLevel(inrNode *ptr,unsigned int level,inrNode **prevNode){
	if(ptr == null){
		return;
	}
	if(level == 0){
		if(*prevNode != null){
			(*prevNode)->nextRight = ptr;
		}
		*prevNode = ptr;
		return;
	}
	connectNodesAtLevel(ptr->left,level-1,prevNode);
	connectNodesAtLevel(ptr->right,level-1,prevNode);
}

//Tested
void rConnectNodesAtSameLevel(inrNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->getHeightOfTree(ptr);
	inrNode *prevNode = null;
	for(unsigned int counter = 0;counter < height;counter++){
		connectNodesAtLevel(ptr,counter,&prevNode);
		prevNode = null;
	}
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//These solutions only work when nodes are at same level
void rConnectNodesAtSameLevelPreOrderFullTree(inrNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->left != null){
		ptr->left->nextRight = ptr->right;
	}
	if(ptr->right != null){
		ptr->right->nextRight = ptr->nextRight == null?null:ptr->nextRight->left;
	}
	rConnectNodesAtSameLevelPreOrderFullTree(ptr->left);
	rConnectNodesAtSameLevelPreOrderFullTree(ptr->right);
}

void connectNodesAtSameLevelPreOrderFullTree(inrNode *ptr){
	if(ptr == null){
		return;
	}
	inrNode *crawler = ptr;
	while(crawler != null){
		crawler = crawler->nextRight;
	}
}

#endif /* CONNECTNODESATSAMELEVEL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
