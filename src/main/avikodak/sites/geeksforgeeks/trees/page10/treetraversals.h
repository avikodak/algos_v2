/****************************************************************************************************************************************************
 *  File Name   		: treetraversals.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page10\treetraversals.h
 *  Created on			: Oct 9, 2014 :: 1:49:46 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/618/
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

#ifndef TREETRAVERSALS_H_
#define TREETRAVERSALS_H_

/****************************************************************************************************************************************************/
/* 															PRE ORDER TRAVERSALS																    */
/****************************************************************************************************************************************************/
void preOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	printf("%d\t",ptr->value);
	preOrderTraversal(ptr->left);
	preOrderTraversal(ptr->right);
}

void preOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	while(currentNode != null && !auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}
	}
}

void morrisPreOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *currentNode = ptr,*temp;
	while(currentNode != null){
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = currentNode;
				printf("%d",currentNode->value);
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				currentNode = currentNode->right;
			}
		}else{
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

/****************************************************************************************************************************************************/
/* 															POST ORDER TRAVERSAL 																    */
/****************************************************************************************************************************************************/
void postOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	postOrderTraversal(ptr->left);
	postOrderTraversal(ptr->right);
	printf("%d\t",ptr->value);
}

void postOrderIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentNode;
	primaryAuxspace.push(ptr);
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		secondaryAuxspace.push(currentNode);
		primaryAuxspace.pop();
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
		printf("%d\t",currentNode->value);
	}
}

void postOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
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
				printf("%d\t",currentNode->value);
				currentNode = null;
			}
		}
	}
}

void postOrderIterativeV2(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			printf("%d\t",currentNode->value);
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				printf("%d\t",currentNode->value);
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?NULL:auxSpace.top()->right;
	}
}

/****************************************************************************************************************************************************/
/* 															IN ORDER TRAVERSAL																    	*/
/****************************************************************************************************************************************************/
void inOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	inOrderTraversal(ptr->left);
	printf("%d\t",ptr->value);
	inOrderTraversal(ptr->right);
}

void inOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(currentNode != null && !auxSpace.empty()){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

void morrisInOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *currentNode = ptr,*temp;
	while(currentNode != null){
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = currentNode;
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				printf("%d\t",currentNode->value);
				currentNode = currentNode->right;
			}
		}else{
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

void fixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevPtr = null;
	fixLeftPtr(ptr->left);
	ptr->left = prevPtr;
	prevPtr = ptr;
	fixLeftPtr(ptr->right);
}

void inOrderTraversalDllConversionMain(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevPtr = null;
	inOrderTraversalDllConversionMain(ptr->left);
	ptr->left = prevPtr;
	if(prevPtr != null){
		prevPtr->right = ptr;
	}
	prevPtr = ptr;
	inOrderTraversalDllConversionMain(ptr->right);
}

void inOrderTraversalDllConversion(itNode *ptr){
	if(ptr == null){
		return;
	}
	inOrderTraversalDllConversionMain(ptr);
	while(ptr->left != null){
		ptr = ptr->left;
	}
	while(ptr != null){
		printf("%d\t",ptr->value);
		ptr = ptr->right;
	}
}

void fixRightPtr(itNode **ptr){
	if((*ptr) == null){
		return;
	}
	itNode *currentNode = *ptr;
	itNode *prevPtr = null;
	while(currentNode->right != null){
		currentNode = currentNode->right;
	}
	while(currentNode != null){
		currentNode->right = prevPtr;
		prevPtr = currentNode;
		currentNode = currentNode->left;
	}
	(*ptr) = prevPtr;
}

void inOrderTraversalON(itNode *ptr){
	if(ptr == null){
		return;
	}
	fixLeftPtr(ptr);
	fixRightPtr(&ptr);
	while(ptr != null){
		printf("%d\t",ptr->value);
		ptr = ptr->right;
	}
}

itNode *inOrderTraversalON2Main(itNode *ptr){
	if(ptr == null){
		return null;
	}
	itNode *temp;
	if(ptr->left != null){
		temp = inOrderTraversalON2Main(ptr->left);
		while(temp->right != null){
			temp = temp->right;
		}
		temp->right = ptr;
	}
	if(ptr->right != null){
		temp = inOrderTraversalON2Main(ptr->right);
		while(temp->left != null){
			temp = temp->left;
		}
		temp->left = ptr;
	}
	return ptr;
}

void inOrderTraversalON2(itNode *ptr){
	if(ptr == null){
		return;
	}
	inOrderTraversalON2Main(ptr);
	while(ptr->left != null){
		ptr = ptr->left;
	}
	while(ptr != null){
		printf("%d\t",ptr->value);
		ptr = ptr->right;
	}
}

/****************************************************************************************************************************************************/
/* 															LEVEL ORDER TRAVERSAL																    */
/****************************************************************************************************************************************************/
//Tested
void levelOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	unsigned int levelCounter = 1;
	while(!auxSpace.empty()){
		levelCounter = auxSpace.size();
		while(levelCounter--){
			currentNode = auxSpace.front();
			printf("%d\t",currentNode->value);
			auxSpace.pop();
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
		PRINT_NEW_LINE;
	}
}

//Tested
void printLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return;
	}
	if(level == 0){
		printf("%d\t",ptr->value);
		return;
	}
	printLevel(ptr->left,level-1);
	printLevel(ptr->right,level-1);
}

//Tested
void levelOrderTraversalON2(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->getHeightOfTree(ptr);
	for(unsigned int levelCounter = 0;levelCounter < height;levelCounter++){
		printLevel(ptr,levelCounter);
		PRINT_NEW_LINE;
	}
}

#endif /* TREETRAVERSALS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
