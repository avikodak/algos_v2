/****************************************************************************************************************************************************
 *  File Name   		: printleftview.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page03\printleftview.h
 *  Created on			: Nov 14, 2014 :: 7:43:54 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/print-left-view-binary-tree/
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

#ifndef PRINTLEFTVIEW_H_
#define PRINTLEFTVIEW_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printLeftView(itNode *ptr,int level,int *maxLevel){
	if(ptr == null){
		return;
	}
	if(level > *maxLevel){
		printf("%d\t",ptr->value);
		*maxLevel = level;
	}
	printLeftView(ptr->left,level+1,maxLevel);
	printLeftView(ptr->right,level+1,maxLevel);
}

//Tested
void printLeftViewLevelOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	unsigned int nodeCounter;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		nodeCounter = auxSpace.size();
		printf("%d\t",auxSpace.front()->value);
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
	}
}

//Tested
inrNode *plGetNextRight(inrNode *ptr){
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
void plConnectNodesAtSameLevel(inrNode *ptr){
	if(ptr == null){
		return;
	}
	plConnectNodesAtSameLevel(ptr->nextRight);
	if(ptr->left != null){
		if(ptr->right != null){
			ptr->left->nextRight = ptr->right;
			ptr->right->nextRight = plGetNextRight(ptr->nextRight);
		}else{
			ptr->left->nextRight = plGetNextRight(ptr->nextRight);
		}
		plConnectNodesAtSameLevel(ptr->left);
	}else if(ptr->right != null){
		ptr->right->nextRight = plGetNextRight(ptr->nextRight);
		plConnectNodesAtSameLevel(ptr->right);
	}else{
		plConnectNodesAtSameLevel(ptr->nextRight);
	}
}

//Tested
void printLeftViewByConnectingNodesAtLevel(inrNode *ptr){
	if(ptr == null){
		return;
	}
	plConnectNodesAtSameLevel(ptr);
	inrNode *currentNode = ptr;
	while(currentNode != null){
		printf("%d\t",currentNode->value);
		if(currentNode->left != null){
			currentNode = currentNode->left;
		}else if(currentNode->right != null){
			currentNode = currentNode->right;
		}else{
			currentNode = plGetNextRight(currentNode->nextRight);
		}

	}
}

#endif /* PRINTLEFTVIEW_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
