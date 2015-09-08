/****************************************************************************************************************************************************
 *  File Name   		: converttreetosumtree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\converttreetosumtree.h
 *  Created on			: Oct 23, 2014 :: 5:11:35 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
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

#ifndef CONVERTTREETOSUMTREE_H_
#define CONVERTTREETOSUMTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int convertTreeToSumTreePostOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	int temp = ptr->value;
	if(ptr->left == null && ptr->right == null){
		ptr->value = 0;
		return temp;
	}
	ptr->value = convertTreeToSumTreePostOrder(ptr->left) + convertTreeToSumTreePostOrder(ptr->right);
	return temp + ptr->value;
}

//Tested
int getSumOfNodes(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return ptr->value + getSumOfNodes(ptr->left) + getSumOfNodes(ptr->right);
}

//Tested
void convertTreeToSumTreePreOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		ptr->value = 0;
		return;
	}
	ptr->value = getSumOfNodes(ptr->left) + getSumOfNodes(ptr->right);
	convertTreeToSumTreePreOrder(ptr->left);
	convertTreeToSumTreePreOrder(ptr->right);
}

//Tested
void convertTreeToSumTreeInOrderMain(itNode *ptr,hash_map<intptr_t,int> &nodeValueMap){
	if(ptr == null){
		return;
	}
	convertTreeToSumTreeInOrderMain(ptr->left,nodeValueMap);
	if(ptr->left == null && ptr->right == null){
		ptr->value = 0;
	}else{
		int sum = 0;
		if(ptr->left != null){
			sum += ptr->left->value + nodeValueMap.find((intptr_t)ptr->left)->second;
		}
		sum += getSumOfNodes(ptr->right);
		ptr->value = sum;
	}
	convertTreeToSumTreeInOrderMain(ptr->right,nodeValueMap);
}

//Tested
void setNodeValueIntoMap(itNode *ptr,hash_map<intptr_t,int> &nodeValueMap){
	if(ptr == null){
		return;
	}
	nodeValueMap.insert(pair<intptr_t,int>((intptr_t)ptr,ptr->value));
	setNodeValueIntoMap(ptr->left,nodeValueMap);
	setNodeValueIntoMap(ptr->right,nodeValueMap);
}

//Tested
void convertTreeToSumTreeInorder(itNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<intptr_t,int> nodeValueMap;
	setNodeValueIntoMap(ptr,nodeValueMap);
	convertTreeToSumTreeInOrderMain(ptr,nodeValueMap);
}

//Tested
void setNodeValueMap(itNode *ptr,hash_map<intptr_t,int> &nodeValueMap){
	if(ptr == null){
		return;
	}
	nodeValueMap.insert(pair<intptr_t,int>((intptr_t)ptr,ptr->value));
	setNodeValueMap(ptr->left,nodeValueMap);
	setNodeValueMap(ptr->right,nodeValueMap);
}

//Tested
void setValueInNode(itNode *currentNode, hash_map<intptr_t,int> nodeValueMap){
	if(currentNode->left == null && currentNode->right == null){
		currentNode->value = 0;
	}else{
		int sum = 0;
		if(currentNode->left != null){
			sum = currentNode->left->value + nodeValueMap.find((intptr_t)currentNode->left)->second;
		}
		if(currentNode->right != null){
			sum += currentNode->right->value + nodeValueMap.find((intptr_t)currentNode->right)->second;
		}
		currentNode->value = sum;
	}
}

//Tested
void convertTreeToSumTreePostOrderTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<intptr_t,int> nodeValueMap;
	setNodeValueMap(ptr,nodeValueMap);
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	primaryAuxspace.push(ptr);
	itNode *currentNode;
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
		setValueInNode(currentNode, nodeValueMap);
	}

}

//Tested
void convertTreeToSumTreePostOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<intptr_t,int> nodeValueMap;
	setNodeValueMap(ptr,nodeValueMap);
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
				setValueInNode(currentNode,nodeValueMap);
				currentNode = null;
			}
		}
	}
}

//Tested
void convertTreeToSumTreePostOrderIterativeV2(itNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<intptr_t,int> nodeValueMap;
	setNodeValueMap(ptr,nodeValueMap);
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
			setValueInNode(currentNode,nodeValueMap);
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				auxSpace.pop();
				setValueInNode(currentNode,nodeValueMap);
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* CONVERTTREETOSUMTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
