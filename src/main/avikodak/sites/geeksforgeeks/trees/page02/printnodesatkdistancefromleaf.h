/****************************************************************************************************************************************************
 *  File Name   		: printnodesatkdistancefromleaf.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\printnodesatkdistancefromleaf.h
 *  Created on			: Nov 15, 2014 :: 7:44:59 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/print-nodes-distance-k-leaf-node/
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

#ifndef PRINTNODESATKDISTANCEFROMLEAF_H_
#define PRINTNODESATKDISTANCEFROMLEAF_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int printNodesAtKDistanceFromLeaf(itNode *ptr,unsigned int kDistance){
	if(ptr == null){
		return 0;
	}
	unsigned int leftHeight = printNodesAtKDistanceFromLeaf(ptr->left,kDistance);
	unsigned int rightHeight = printNodesAtKDistanceFromLeaf(ptr->right,kDistance);
	if(leftHeight == kDistance || rightHeight == kDistance){
		printf("%d\t",ptr->value);
	}
	return 1 + max(leftHeight,rightHeight);
}

//Tested
void printNodesAtKDistanceFromLeafAuxspace(itNode *ptr,stack<itNode *> auxSpace,unsigned int kDistance){
	if(ptr == null){
		return;
	}
	static hash_map<int,bool> flags;
	auxSpace.push(ptr);
	if(ptr->left == null && ptr->right == null){
		while(!auxSpace.empty() && kDistance--){
			auxSpace.pop();
		}
		if(!auxSpace.empty()){
			if(flags.find(auxSpace.top()->value) == flags.end()){
				printf("%d\t",auxSpace.top()->value);
				flags[auxSpace.top()->value] = true;
			}
		}
		return;
	}
	printNodesAtKDistanceFromLeafAuxspace(ptr->left,auxSpace,kDistance);
	printNodesAtKDistanceFromLeafAuxspace(ptr->right,auxSpace,kDistance);
}

//Tested
void checkAndPrintIfNodeAtKdistance(itNode *ptr,hash_map<intptr_t,int> &nodeHeightMap,int kDistance){
	hash_map<intptr_t,int>::iterator itToLeftNodeHeightMap,itToRightNodeHeight;
	int maxHeight = 0;
	bool flag = false;
	if(ptr->left != null || ptr->right != null){
		if(ptr->left != null){
			itToLeftNodeHeightMap = nodeHeightMap.find((intptr_t)ptr->left);
			maxHeight = maxHeight > itToLeftNodeHeightMap->second ?maxHeight:itToLeftNodeHeightMap->second;
			if(itToLeftNodeHeightMap->second == kDistance){
				printf("%d\t",ptr->value);
				flag = true;
			}
		}
		if(ptr->right != null){
			itToRightNodeHeight = nodeHeightMap.find((intptr_t)ptr->right);
			maxHeight = maxHeight > itToRightNodeHeight->second ?maxHeight:itToRightNodeHeight->second;
			if(!flag && itToRightNodeHeight->second == kDistance){
				printf("%d\t",ptr->value);
			}
		}
		nodeHeightMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,1+maxHeight));
	}else{
		nodeHeightMap.insert(pair<intptr_t,unsigned int>((intptr_t)ptr,1));
	}
}

//Tested
void printNodesAtKDistancePostorderTraversalIterative(itNode *ptr,int kDistance){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<intptr_t,int> nodeHeightMap;
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
				checkAndPrintIfNodeAtKdistance(currentNode,nodeHeightMap,kDistance);
				currentNode = null;
			}
		}
	}
}

//Tested
void printNodesAtKDistancePostorderTraversalIterativeV2(itNode *ptr,int kDistance){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<intptr_t,int> nodeHeightMap;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			checkAndPrintIfNodeAtKdistance(currentNode,nodeHeightMap,kDistance);
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				checkAndPrintIfNodeAtKdistance(currentNode,nodeHeightMap,kDistance);
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int heightOfTree(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return 1 + max(heightOfTree(ptr->left),heightOfTree(ptr->right));
}

//Tested
void printNodesAtKDistanceON2(itNode *ptr,unsigned int kDistance){
	if(ptr == null){
		return;
	}
	if(heightOfTree(ptr->left) == kDistance || heightOfTree(ptr->right) == kDistance){
		printf("%d\t",ptr->value);
	}
	printNodesAtKDistanceON2(ptr->left,kDistance);
	printNodesAtKDistanceON2(ptr->right,kDistance);
}

#endif /* PRINTNODESATKDISTANCEFROMLEAF_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
