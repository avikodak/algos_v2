/****************************************************************************************************************************************************
 *  File Name                   : treetraversals.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/trees/page06/treetraversals.h
 *  Created on                  : Jan 16, 2016 :: 6:06:00 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/618/
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_TREETRAVERSALS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_TREETRAVERSALS_H_

/****************************************************************************************************************************************************/
/* 															PRE ORDER TRAVERSAL																        */
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
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		printf("%d\t",currentNode->value);
		auxSpace.pop();
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}
	}
}

void morrisPreOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *currentNode = ptr;
	itNode *temp;
	while(!currentNode != null){
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				printf("%d\t",currentNode->value);
				temp->right = currentNode;
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

void postOrderTraversalTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxSpace,secondaryAuxSpace;
	primaryAuxSpace.push(ptr);
	itNode *currentNode = ptr;
	while(!primaryAuxSpace.empty()){
		currentNode = primaryAuxSpace.top();
		primaryAuxSpace.pop();
		secondaryAuxSpace.push(currentNode);
		if(currentNode->left != null){
			primaryAuxSpace.push(currentNode->left);
		}
		if(currentNode->right != null){
			primaryAuxSpace.push(currentNode->right);
		}
	}
	while(!secondaryAuxSpace.empty()){
		currentNode = secondaryAuxSpace.top();
		secondaryAuxSpace.pop();
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
			if(!auxSpace.empty() && auxSpace.top() == currentNode->right){
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

void postOrderTraversalV2(itNode *ptr){
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
		if(!auxSpace.empty() && auxSpace.top()->right != null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			printf("%d\t",currentNode->value);
			while(!auxSpace.empty() || currentNode == auxSpace.top()){
				currentNode = auxSpace.top();
				auxSpace.pop();
				printf("%d\t",currentNode->value);
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
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
}

void morrisInOrder(itNode *ptr){
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
				printf("%d\t",currentNode->value);
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
/* 															LEVEL ORDER TRAVERSAL																    */
/****************************************************************************************************************************************************/
void levelOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		printf("%d\t",currentNode->value);
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
	}
}

void printLevel(itNode *ptr,int level){
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

int getHeightOfTree(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return 1 + max(getHeightOfTree(ptr->left),getHeightOfTree(ptr->right));
}

void levelOrderTraversalON2(itNode *ptr){
	if(ptr == null){
		return;
	}
	int height = getHeightOfTree(ptr);
	for(int counter = 0;counter < height;counter++){
		printLevel(ptr,counter);
	}
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_TREETRAVERSALS_H_ */
