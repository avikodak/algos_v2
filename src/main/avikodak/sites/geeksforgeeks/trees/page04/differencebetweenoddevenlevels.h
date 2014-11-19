/****************************************************************************************************************************************************
 *  File Name   		: differencebetweenoddevenlevels.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page04\differencebetweenoddevenlevels.h
 *  Created on			: Nov 14, 2014 :: 5:26:34 PM
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

#ifndef DIFFERENCEBETWEENODDEVENLEVELS_H_
#define DIFFERENCEBETWEENODDEVENLEVELS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int differenceBetweenEvenOddLevels(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return ptr->value - differenceBetweenEvenOddLevels(ptr->left) - differenceBetweenEvenOddLevels(ptr->right);
}

int differenceBetweenEvenOddLevels(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	int difference = 0;
	queue<itNode *> auxSpace;
	itNode *currentNode = ptr;
	auxSpace.push(currentNode);
	unsigned int nodeCounter = 0;
	bool isOddLevel = true;
	while(!auxSpace.empty()){
		nodeCounter = auxSpace.size();
		while(nodeCounter--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			difference += isOddLevel?currentNode->value:-currentNode->value;
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
		isOddLevel = !isOddLevel;
	}
}

inrNode *dGetNextRightPtr(inrNode *ptr){
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

void connectNodesInSameLevel(inrNode *ptr){
	if(ptr == null){
		return;
	}
	connectNodesInSameLevel(ptr->nextRight);
	if(ptr->left != null){
		if(ptr->right != null){
			ptr->left->nextRight = ptr->right;
			ptr->right->nextRight = dGetNextRightPtr(ptr->nextRight);
		}else{
			ptr->left->nextRight = dGetNextRightPtr(ptr->nextRight);
		}
		connectNodesInSameLevel(ptr->left);
	}else if(ptr->right != null){
		ptr->right->nextRight = dGetNextRightPtr(ptr->nextRight);
		connectNodesInSameLevel(ptr->right);
	}else{
		connectNodesInSameLevel(ptr->nextRight);
	}
}

int sumOfNodesInLevel(inrNode *ptr){
	int sum = 0;
	while(ptr != null){
		sum += ptr->value;
		ptr = ptr->nextRight;
	}
	return sum;
}

int differenceOfNodes(inrNode *ptr){
	if(ptr == null){
		return 0;
	}
	connectNodesInSameLevel(ptr);
	inrNode *currentNode = ptr;
	int difference  = 0;
	bool isOddLevel = true;
	while(ptr != null){
		if(isOddLevel){
			difference += sumOfNodesInLevel(ptr);
		}else{
			difference -= sumOfNodesInLevel(ptr);
		}
		if(ptr->left !=  null){
			ptr = ptr->left;
		}else if(ptr->right != null){
			ptr = ptr->right;
		}else{
			ptr = getNextRight(ptr->nextRight);
		}
		isOddLevel = !isOddLevel;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int sumOfNodesInLevel(itNode *ptr,int level){
	if(ptr == null){
		return 0;
	}
	if(level == 0){
		return ptr->value;
	}
	return sumOfNodesInLevel(ptr->left,level-1) + sumOfNodesInLevel(ptr->right,level-1);
}

int differenceValueBetweenLevels(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->getHeightOfTree(ptr);
	bool isOddLevel = true;
	int difference = 0;
	for(unsigned int counter = 0;counter < height;counter++){
		if(isOddLevel){
			difference += sumOfNodesInLevel(ptr,level);
		}else{
			difference -= sumOfNodesInLevel(ptr,level);
		}
	}
	return difference;
}

#endif /* DIFFERENCEBETWEENODDEVENLEVELS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

