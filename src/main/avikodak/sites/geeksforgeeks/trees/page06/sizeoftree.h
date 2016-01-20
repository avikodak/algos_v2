/****************************************************************************************************************************************************
 *  File Name                   : sizeoftree.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/trees/page06/sizeoftree.h
 *  Created on                  : Jan 16, 2016 :: 8:03:41 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_SIZEOFTREE_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_SIZEOFTREE_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
int getSizeOfTreePreOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return 1 + getSizeOfTreePreOrder(ptr->left) + getSizeOfTreePreOrder(ptr->right);
}

int getSizeOfTreePreOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	int totalNodes = 0;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		totalNodes++;
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}
	}
	return totalNodes;
}

int getSizeOfTreeMorrisPreOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	itNode *currentNode = ptr,*temp;
	int totalNodes = 0;
	while(currentNode != null){
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				totalNodes++;
				temp->right = currentNode;
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				currentNode = currentNode->right;
			}
		}else{
			totalNodes++;
			currentNode = currentNode->right;
		}
	}
	return totalNodes;
}

int getSizeOfTreeInOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return getSizeOfTreeInOrder(ptr->left) + 1 + getSizeOfTreeInOrder(ptr->right);
}

int getSizeOfTreeInOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	int totalNodes = 0;
	while(!auxSpace.empty() || currentNode != null){
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
	return totalNodes;
}

int getSizeOfTreeMorrisInOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	int totalNodes = 0;
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
				totalNodes++;
				temp->right = null;
				currentNode = currentNode->right;
			}
		}else{
			totalNodes++;
			currentNode = currentNode->right;
		}
	}
	return totalNodes;
}

void fixLeftPtrs(itNode *ptr){
	static itNode *prevNode = null;
	if(ptr == null){
		return;
	}
	fixLeftPtrs(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	fixLeftPtrs(ptr->right);
}

void fixRightPtrs(itNode **ptr){
	if(*ptr == null){
		return;
	}
	itNode *currentNode = *ptr,*prevNode = null;
	while(currentNode->right != null){
		currentNode = currentNode->right;
	}
	while(currentNode != null){
		currentNode->right = prevNode;
		prevNode = currentNode;
		currentNode = currentNode->left;
	}
	(*ptr) = prevNode;
}

int getSizeByFixingPtrs(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	fixLeftPtrs(ptr);
	fixRightPtrs(&ptr);
	int totalNodes = 0;
	while(ptr != null){
		totalNodes++;
		ptr = ptr->right;
	}
	return totalNodes;
}

void convertTreeToDll(itNode *ptr){
	static itNode *prevNode = null;
	if(ptr == null){
		return;
	}
	convertTreeToDll(ptr->left);
	if(prevNode != null){
		prevNode->right = ptr;
	}
	ptr->left = prevNode;
	prevNode = ptr;
	convertTreeToDll(ptr->right);
}

int getSizeOfTreeInorderConversion(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	convertTreeToDll(ptr);
	while(ptr->left != null){
		ptr = ptr->left;
	}
	int totalNodes = 0;
	while(ptr!= null){
		totalNodes++;
		ptr = ptr->right;
	}
	return totalNodes;
}

int getSizeOfTreePostOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return getSizeOfTreePostOrder(ptr->left) + getSizeOfTreePostOrder(ptr->right) + 1;
}

int getSizeOfTreePostOrderIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> primary,secondary;
	itNode *currentNode;
	primary.push(ptr);
	while(!primary.empty()){
		currentNode = primary.top();
		primary.pop();
		secondary.push(currentNode);
		if(currentNode->left != null){
			primary.push(currentNode->left);
		}
		if(currentNode->right != null){
			primary.push(currentNode->right);
		}
	}
	int totalNodes = 0;
	while(!secondary.empty()){
		currentNode = secondary.top();
		secondary.pop();
		totalNodes++;
	}
	return totalNodes;
}

int getSizeOfTreePostOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	int totalNodes = 0;
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
			if(!auxSpace.empty() && auxSpace.top() == currentNode->right){
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				totalNodes++;
				currentNode = null;
			}
		}
	}
	return totalNodes;
}

int getSizeOfTreePostOrderItervativeV2(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	int totalNodes = 0;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			totalNodes++;
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				totalNodes++;
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	return totalNodes;
}

int getSizeOfTreeLevelOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	int totalNodes = 0;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		totalNodes++;
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
	}
	return totalNodes;
}

itnrNode *getNextRightNode(itnrNode *ptr){
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

void connectNodesWithNextRight(itnrNode *ptr){
	if(ptr == null){
		return;
	}
	connectNodesWithNextRight(ptr->nextRight);
	if(ptr->left != null){
		if(ptr->right != null){
			ptr->left->nextRight = ptr->right;
			ptr->right->nextRight = getNextRight(ptr->nextRight);
		}else{
			ptr->left->nextRight = getNextRight(ptr->nextRight);
		}
		connectNodesWithNextRight(ptr->left);
	}else if(ptr->right != null){
		ptr->right->nextRight = getNextRight(ptr->nextRight);
		connectNodesWithNextRight(ptr->right);
	}else{
		connectNodesWithNextRight(getNextRight(ptr->nextRight));
	}
}

unsigned int getNodesAtLevelPostConnectingNextRight(itnrNode *ptr){
	if(ptr == null){
		return 0;
	}
	unsigned int totalNodes = 0;
	while(ptr != null){
		totalNodes++;
		ptr = ptr->nextRight;
	}
	return totalNodes;
}

unsigned int getSizeOfTreeByConnectingWithNextRight(itnrNode *ptr){
	if(ptr == null){
		return 0;
	}
	connectNodesWithNextRight(ptr);
	unsigned int totalNodes = 0;
	while(ptr != null){
		totalNodes += getNodesAtLevelPostConnectingNextRight(ptr);
		if(ptr->left != null){
			ptr = ptr->left;
		}else if(ptr->right != null){
			ptr = ptr->right;
		}else{
			ptr = getNextRight(ptr->nextRight);
		}
	}
	return totalNodes;
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int getSizeOfLevel(itNode *ptr,int level){
	if(ptr == null){
		return 0;
	}
	if(level == 0){
		return 1;
	}
	return 1 + getSizeOfLevel(ptr->left,level-1) + getSizeOfLevel(ptr->right,level-1);
}

int getHeightOfTree(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return 1 + max(getHeightOfTree(ptr->left),getHeightOfTree(ptr->right));
}

int getSizeOfTreeON2(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	int height = getHeightOfTree(ptr);
	int totalNodes = 0;
	for(int counter = 0;counter < height;counter++){
		totalNodes += getSizeOfLevel(ptr,counter);
	}
	return totalNodes;
}


itNode *convertTreeToDllON2(itNode *ptr){
	if(ptr == null){
		return null;
	}
	itNode *temp = null;
	if(ptr->left != null){
		temp = convertTreeToDllON2(ptr->left);
		while(temp->right != null){
			temp = temp->right;
		}
		temp->right = ptr;
		ptr->left = temp;
	}
	if(ptr->right != null){
		temp = convertTreeToDllON2(ptr->right);
		while(temp->left != null){
			temp = temp->left;
		}
		temp->left = ptr;
		ptr->right = temp;
	}
	return ptr;
}

int getSizeDllConversionON2(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	convertTreeToDllON2(ptr);
	while(ptr->left != null){
		ptr = ptr->left;
	}
	int totalNodes = 0;
	while(ptr != null){
		totalNodes++;
		ptr = ptr->right;
	}
	return totalNodes;
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_SIZEOFTREE_H_ */
