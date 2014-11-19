/****************************************************************************************************************************************************
 *  File Name   		: istreecomplete.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\istreecomplete.h
 *  Created on			: Nov 1, 2014 :: 8:53:11 AM
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

#ifndef ISTREECOMPLETE_H_
#define ISTREECOMPLETE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isTreeCompleteLevelOrder(itNode *ptr){
	if(ptr == null){
		return true;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	unsigned int level = 0,nodeCounter = 0;
	while(!auxSpace.empty()){
		nodeCounter = auxSpace.size();
		if(pow(2,level) != nodeCounter){
			return false;
		}
		while(nodeCounter--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
		level++;
	}
	return true;
}

bool isTreeCompleteLevelOrderV2(itNode *ptr){
	if(ptr == null){
		return true;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}else{
			if(currentNode->right != null){
				return false;
			}
		}
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
	}
	return true;
}

void setNodesInHashmap(itNode *ptr,hash_map<unsigned int,itNode *> &indexNodeMap,unsigned int nodeIndex = 1){
	if(ptr == null){
		return;
	}
	indexNodeMap.insert(pair<unsigned int,itNode *>(nodeIndex,ptr));
	setNodesInHashmap(ptr->left,indexNodeMap,2*nodeIndex);
	setNodesInHashmap(ptr->right,indexNodeMap,2*nodeIndex+1);
}

bool isTreeComplete(itNode *ptr){
	if(ptr == null){
		return true;
	}
	hash_map<unsigned int,itNode *> indexNodeMap;
	setNodesInHashmap(ptr,indexNodeMap);
	treeutils *utils = new treeutils();
	unsigned int height = utils->getHeightOfTree(ptr);
	for(unsigned int indexCounter = 1;indexCounter < pow(2,height);indexCounter++){
		if(indexNodeMap.find(indexCounter) == indexNodeMap.end()){
			return false;
		}
	}
	return true;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int levelCounterLevelByLevel(itNode *ptr,unsigned int counter){
	if(ptr == null){
		return 0;
	}
	if(counter == 0){
		return 1;
	}
	return levelCounterLevelByLevel(ptr->left,counter-1) + levelCounterLevelByLevel(ptr->right,counter-1);
}

bool isTreeCompleteLevelOrderON2(itNode *ptr){
	if(ptr == null){
		return true;
	}
	treeutils *utils = new treeutils();
	unsigned int heightOfTree = utils->getHeightOfTree(ptr),levelNodes;
	for(unsigned int level = 0;level < heightOfTree;level++){
		levelNodes = levelCounterLevelByLevel(ptr,level);
		if(levelNodes != pow(2,level)){
			return false;
		}
	}
	return true;
}

inrNode *iGetNextRight(inrNode *ptr){
	while(ptr != null){
		if(ptr->left != null){
			return ptr->left;
		}
		if(ptr->right != null){
			return ptr->right;
		}
		ptr = ptr->nextRight;
	}
	return null;
}

void connectNodesAtLevel(inrNode *ptr){
	if(ptr == null){
		return;
	}
	connectNodesAtLevel(ptr->nextRight);
	if(ptr->left != null){
		if(ptr->right != null){
			ptr->left->nextRight = ptr->right;
			ptr->right->nextRight = iGetNextRight(ptr->nextRight);
		}else{
			ptr->left->nextRight = iGetNextRight(ptr->nextRight);
		}
		connectNodesAtLevel(ptr->left);
	}else if(ptr->right != null){
		ptr->right->nextRight = iGetNextRight(ptr->nextRight);
		connectNodesAtLevel(ptr->right);
	}else{
		connectNodesAtLevel(ptr->nextRight);
	}
}

unsigned int countNodesAtLevel(inrNode *ptr){
	if(ptr == null){
		return 0;
	}
	return 1 + countNodesAtLevel(ptr->nextRight);
}

bool istreecomplete(inrNode *ptr){
	if(ptr == null){
		return true;
	}
	connectNodesAtLevel(ptr);
	treeutils *utils = new treeutils();
	unsigned int height = utils->getHeightOfTree(ptr);
	inrNode *crawler = ptr;
	for(unsigned int counter = 0;counter < height;counter++){
		if(crawler == null){
			return false;
		}
		if(pow(2,counter) != countNodesAtLevel(crawler)){
			return false;
		}
		crawler = crawler->left;
	}
	return true;
}

#endif /* ISTREECOMPLETE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
