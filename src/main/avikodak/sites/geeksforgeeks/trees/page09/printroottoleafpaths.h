/****************************************************************************************************************************************************
 *  File Name   		: printroottoleafpaths.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\printroottoleafpaths.h
 *  Created on			: Oct 14, 2014 :: 11:36:28 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/
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

#ifndef PRINTROOTTOLEAFPATHS_H_
#define PRINTROOTTOLEAFPATHS_H_

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printRootToLeafPath(itNode *ptr,queue<itNode *> ancestors){
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		while(!ancestors.empty()){
			printf("%d\t",ancestors.front()->value);
			ancestors.pop();
		}
		printf("%d\t",ptr->value);
		PRINT_NEW_LINE;
		return;
	}
	ancestors.push(ptr);
	printRootToLeafPath(ptr->left,ancestors);
	printRootToLeafPath(ptr->right,ancestors);
}

//Tested
void reverseStackPrint(stack<itNode *> auxSpace){
	if(auxSpace.size() == 0){
		PRINT_NEW_LINE;
		return;
	}
	itNode *node = auxSpace.top();
	auxSpace.pop();
	reverseStackPrint(auxSpace);
	printf("%d\t",node->value);
}

//Tested
void printRootToLeafPathPostorder(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(!auxSpace.empty()  || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			if(currentNode->left == null && currentNode->right == null){
				reverseStackPrint(auxSpace);
			}
			auxSpace.pop();
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				if(currentNode->left == null && currentNode->right == null){
					reverseStackPrint(auxSpace);
				}
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?NULL:auxSpace.top()->right;
	}
}

//Tested
void printRootToLeaf(iptNode *ptr){
	if(ptr == null){
		return;
	}
	stack<iptNode *> auxSpace;
	iptNode *currentNode = ptr;
	while(currentNode != null){
		auxSpace.push(currentNode);
		currentNode = currentNode->parent;
	}
	while(!auxSpace.empty()){
		printf("%d\t",auxSpace.top()->value);
		auxSpace.pop();
	}
	PRINT_NEW_LINE;
}

//Tested
void printRootToLeafPathsPreOrderIterative(iptNode *ptr){
	if(ptr == null){
		return;
	}
	stack<iptNode *> auxSpace;
	auxSpace.push(ptr);
	iptNode *currentNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(currentNode->left == null && currentNode->right == null){
			printRootToLeaf(currentNode);
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

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printRootToLeafPathON2(iptNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		iptNode *currentNode = ptr;
		stack<iptNode *> auxSpace;
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->parent;
		}
		while(!auxSpace.empty()){
			printf("%d\t",auxSpace.top()->value);
			auxSpace.pop();
		}
		PRINT_NEW_LINE;
		return;
	}
	printRootToLeafPathON2(ptr->left);
	printRootToLeafPathON2(ptr->right);
}

//Tested
void printRootToLeafHashmap(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getTreeAsHashMap(ptr,1)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap,itToTempIndexNodeMap;
	unsigned int currentNodeIndex;
	stack<itNode *> auxSpace;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		if(indexNodeMap.find(2*itToIndexNodeMap->first) == indexNodeMap.end() && indexNodeMap.find(2*itToIndexNodeMap->first + 1) == indexNodeMap.end()){
			currentNodeIndex = itToIndexNodeMap->first;
			while(currentNodeIndex > 0){
				itToTempIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				auxSpace.push(itToTempIndexNodeMap->second);
				currentNodeIndex /= 2;
			}
			while(!auxSpace.empty()){
				printf("%d\t",auxSpace.top()->value);
				auxSpace.pop();
			}
			PRINT_NEW_LINE;
		}
	}
}

#endif /* PRINTROOTTOLEAFPATHS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
