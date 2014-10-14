/****************************************************************************************************************************************************
 *  File Name   		: mirrortree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\mirrortree.h
 *  Created on			: Oct 12, 2014 :: 7:06:40 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
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

#ifndef MIRRORTREE_H_
#define MIRRORTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void getMirrorTreePreorder(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *temp = ptr->left;
	ptr->left = ptr->right;
	ptr->right = temp;
	getMirrorTreePreorder(ptr->left);
	getMirrorTreePreorder(ptr->right);
}

//Tested
void getMirrorTreePreOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	auxSpace.push(ptr);
	itNode *currentNode,*temp;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		temp = currentNode->left;
		currentNode->left = currentNode->right;
		currentNode->right = temp;
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}
	}
}

//Tested
void getMirrorTreeInOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	getMirrorTreeInOrder(ptr->left);
	itNode *temp = ptr->left;
	ptr->left = ptr->right;
	ptr->right = temp;
	getMirrorTreeInOrder(ptr->left); // Since the right changed to left
}

//Tested
void getMirrorTreeInorderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr,*temp;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			temp = currentNode->left;
			currentNode->left = currentNode->right;
			currentNode->right = temp;
			currentNode = currentNode->left; // Since the right is changed to left
		}
	}
}

//Tested
void getMirrorTreePostOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	getMirrorTreePostOrder(ptr->left);
	getMirrorTreePostOrder(ptr->right);
	itNode *temp = ptr->left;
	ptr->left = ptr->right;
	ptr->right = temp;
}

//Tested
void getMirrorPostOrderTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentNode,*temp;
	primaryAuxspace.push(ptr);
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentNode);
		if(currentNode->left != null){
			primaryAuxspace.push(currentNode->left);
		}
		if(currentNode->right != null){
			primaryAuxspace.push(currentNode->right);
		}
	}
	while(!secondaryAuxspace.empty()){
		currentNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		temp = currentNode->left;
		currentNode->left = currentNode->right;
		currentNode->right = temp;
	}
}

//Tested
void getMirrorPostOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr,*temp;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(!auxSpace.empty() && currentNode->right == auxSpace.top()){
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				temp = currentNode->left;
				currentNode->left = currentNode->right;
				currentNode->right = temp;
				currentNode = null;
			}
		}
	}
}

//Tested
void getMirrorPostOrderIterativeV2(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr,*temp;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			temp = currentNode->left;
			currentNode->left = currentNode->right;
			currentNode->right = temp;
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				auxSpace.pop();
				temp = currentNode->left;
				currentNode->left = currentNode->right;
				currentNode->right = temp;
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
}

//Tested
void getMirrorTreeLevelOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode,*temp;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		temp = currentNode->left;
		currentNode->left = currentNode->right;
		currentNode->right = temp;
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void swapChildrenInLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return;
	}
	if(level == 0){
		itNode *temp = ptr->left;
		ptr->left = ptr->right;
		ptr->right = temp;
		return;
	}
	swapChildrenInLevel(ptr->left,level-1);
	swapChildrenInLevel(ptr->right,level-1);
}

//Tested
void getMirrorTreeLevelOrderON2(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->getHeightOfTree(ptr);
	for(unsigned int levelCounter = 0;levelCounter < height;levelCounter++){
		swapChildrenInLevel(ptr,levelCounter);
	}
}

#endif /* MIRRORTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
