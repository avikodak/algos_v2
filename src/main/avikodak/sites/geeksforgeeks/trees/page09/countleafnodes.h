/****************************************************************************************************************************************************
 *  File Name   		: countleafnodes.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\countleafnodes.h
 *  Created on			: Oct 15, 2014 :: 12:25:08 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/
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

#ifndef COUNTLEAFNODES_H_
#define COUNTLEAFNODES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int countLeafNodesPreOrderTraversal(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	if(ptr->left == null && ptr->right == null){
		return 1;
	}
	return countLeafNodesPreOrderTraversal(ptr->left) + countLeafNodesPreOrderTraversal(ptr->right);
}

//Tested
unsigned int countLeafNodesPreOrderIterative(itNode *ptr){
	if(ptr == 0){
		return 0;
	}
	stack<itNode *> auxSpace;
	auxSpace.push(ptr);
	itNode *currentNode;
	unsigned int leafCounter = 0;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(currentNode->left == null && currentNode->right == null){
			leafCounter++;
		}else{
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
		}
	}
	return leafCounter;
}

//Tested
unsigned int countLeafNodesMorrisTraversal(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	itNode *currentNode = ptr,*temp;
	unsigned int leafCounter = 0;
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
				if(temp->left == null && temp->right == null){
					leafCounter++;
				}
				currentNode = currentNode->right;
			}
		}else{
			if(currentNode->left == null && currentNode->right == null){
				leafCounter++;
			}
			currentNode = currentNode->right;
		}
	}
	return leafCounter;
}

//Tested
unsigned int countLeafNodesInOrderTraversal(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	unsigned int leafNodeCounter = 0;
	leafNodeCounter = countLeafNodesInOrderTraversal(ptr->left);
	if(ptr->left == null && ptr->right == null){
		leafNodeCounter++;
	}
	return leafNodeCounter + countLeafNodesInOrderTraversal(ptr->right);
}

//Tested
unsigned int countLeafNodesInorderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	unsigned int leafCounter = 0;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->left == 0 && currentNode->right == 0){
				leafCounter++;
			}
			currentNode = currentNode->right;
		}
	}
	return leafCounter;
}

//Tested
unsigned int countLeafNodesPostOrderTraversal(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	unsigned int leafNodeCounter = 0;
	leafNodeCounter = countLeafNodesPostOrderTraversal(ptr->left);
	leafNodeCounter += countLeafNodesPostOrderTraversal(ptr->right);
	return ptr->left == null && ptr->right == null?1+leafNodeCounter:leafNodeCounter;
}

//Tested
unsigned int countLeafPostOrderIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	unsigned int leafCounter = 0;
	itNode *currentNode = ptr;
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
		if(currentNode->left == null && currentNode->right == null){
			leafCounter++;
		}
	}
	return leafCounter;
}

//Tested
unsigned int countLeavesPostOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	unsigned int leafCounter = 0;
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
				if(currentNode->left == null && currentNode->right == null){
					leafCounter++;
				}
				currentNode = null;
			}
		}
	}
	return leafCounter;
}

//Tested
unsigned int countLeavesLevelOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	unsigned int leafCounter=0,levelCounter;
	while(!auxSpace.empty()){
		levelCounter = auxSpace.size();
		while(levelCounter--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(currentNode->left == null && currentNode->right == null){
				leafCounter++;
			}else{
				if(currentNode->left != null){
					auxSpace.push(currentNode->left);
				}
				if(currentNode->right != null){
					auxSpace.push(currentNode->right);
				}
			}
		}
	}
	return leafCounter;
}

//Tested
unsigned int countLeavesHashMap(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getTreeAsHashMap(ptr)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	unsigned int leafCounter = 0;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		ptr = itToIndexNodeMap->second;
		if(ptr->left == null && ptr->right == null){
			leafCounter++;
		}
	}
	return leafCounter;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int countLeavesLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return 0;
	}
	if(level == 0){
		return ptr->left == null && ptr->right == null?1:0;
	}
	return countLeavesLevel(ptr->left,level-1) + countLeavesLevel(ptr->right,level-1);
}

//Tested
unsigned int countLeavesLevelOrderTraversalON2(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	unsigned int leafCounter = 0;
	treeutils *utils = new treeutils();
	unsigned int height = utils->getHeightOfTree(ptr);
	for(unsigned int levelCounter = 0;levelCounter < height;levelCounter++){
		leafCounter += countLeavesLevel(ptr,levelCounter);
	}
	return leafCounter;
}

#endif /* COUNTLEAFNODES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
