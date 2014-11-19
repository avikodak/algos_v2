/****************************************************************************************************************************************************
 *  File Name   		: printnodeswithnosibling.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\printnodeswithnosibling.h
 *  Created on			: Nov 15, 2014 :: 5:45:45 PM
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

#ifndef PRINTNODESWITHNOSIBLING_H_
#define PRINTNODESWITHNOSIBLING_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printNodesWithNoSiblingsPreOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		return;
	}
	if(ptr->left == null || ptr->right == null){
		if(ptr->left == null){
			printf("%d\t",ptr->right->value);
		}else{
			printf("%d\t",ptr->left->value);
		}
	}
	printNodesWithNoSiblingsPreOrder(ptr->left);
	printNodesWithNoSiblingsPreOrder(ptr->right);
}

void printNodesWithNoSiblingsPreOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(currentNode->left != null || currentNode->right != null){
			if(currentNode->left == null || currentNode->right == null){
				printf("%d\t",currentNode->value);
			}else{
				if(currentNode->right != null){
					auxSpace.push(currentNode->right);
				}
				if(currentNode->left != null){
					auxSpace.push(currentNode->left);
				}
			}
		}
	}
}

void printNodesWithNoSiblingsPostOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		return;
	}
	printNodesWithNoSiblingsPostOrder(ptr->left);
	printNodesWithNoSiblingsPostOrder(ptr->right);
	if(ptr->left == null || ptr->right == null){
		if(ptr->left == null){
			printf("%d\t",ptr->right->value);
		}else{
			printf("%d\t",ptr->left->value);
		}
	}
}

void printSiblingNode(itNode *currentNode){
	if(currentNode->left != null || currentNode->right != null){
		if(currentNode->left == null || currentNode->right == null){
			if(currentNode->left == null){
				printf("%d\t",currentNode->right->value);
			}else{
				printf("%d\t",currentNode->left->value);
			}
		}
	}
}

void printNodesWithNoSiblingsPostOrderTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentNode;
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
		printSiblingNode(currentNode);
	}
}

void printNodesWithNoSiblingsPostOrderIterative(itNode *ptr){
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
			if(!auxSpace.empty() || auxSpace.top() == currentNode->right){
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				printSiblingNode(currentNode);
				currentNode = null;
			}
		}
	}
}

void printNodesWithNoSiblingsPostOrderIterativeV2(itNode *ptr){
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
			printSiblingNode(currentNode);
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				auxSpace.pop();
				printSiblingNode(currentNode);
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
}

inrNode *psGetNextRightPtr(inrNode *ptr){
	inrNode *currentNode = ptr;
	while(currentNode != null){
		if(currentNode->left != null){
			return currentNode->left;
		}else if(currentNode->right != null){
			return currentNode->right;
		}
		currentNode = currentNode->nextRight;
	}
	return null;
}

void psConnectNodesInSameLevel(inrNode *ptr){
	if(ptr == null){
		return;
	}
	psConnectNodesInSameLevel(ptr->nextRight);
	if(ptr->left != null){
		if(ptr->right != null){
			ptr->left->nextRight = ptr->right;
			ptr->right->nextRight = psGetNextRightPtr(ptr->nextRight);
		}else{
			ptr->left->nextRight = psGetNextRightPtr(ptr->nextRight);
		}
		psConnectNodesInSameLevel(ptr->left);
	}else if(ptr->right != null){
		ptr->right->nextRight = psGetNextRightPtr(ptr->nextRight);
		psConnectNodesInSameLevel(ptr->right);
	}else{
		psConnectNodesInSameLevel(ptr->nextRight);
	}
}

void printSiblingsIfPresentInLevel(inrNode *ptr){
	while(ptr != null){
		if(ptr->left == null || ptr->right == null){
			if(ptr->left != null){
				printf("%d\t",ptr->left->value);
			}else if(ptr->right != null){
				printf("%d\t",ptr->right->value);
			}
		}
		ptr = ptr->nextRight;
	}
}

void printNodesWithoutSiblings(inrNode *ptr){
	if(ptr == null){
		return;
	}
	while(ptr != null){
		psConnectNodesInSameLevel(ptr);
		if(ptr->left != null){
			ptr = ptr->left;
		}else if(ptr->right != null){
			ptr = ptr->right;
		}else{
			ptr = psGetNextRightPtr(ptr->nextRight);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* PRINTNODESWITHNOSIBLING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
