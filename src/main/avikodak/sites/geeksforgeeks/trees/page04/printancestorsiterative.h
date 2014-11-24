/****************************************************************************************************************************************************
 *  File Name   		: printancestorsiterative.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page04\printancestorsiterative.h
 *  Created on			: Nov 13, 2014 :: 11:15:16 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/print-ancestors-of-a-given-binary-tree-node-without-recursion/
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

#ifndef PRINTANCESTORSITERATIVE_H_
#define PRINTANCESTORSITERATIVE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void aPrintStack(stack<itNode *> auxSpace){
	while(!auxSpace.empty()){
		printf("%d\t",auxSpace.top()->value);
		auxSpace.pop();
	}
	PRINT_NEW_LINE;
}

//Tested
void printAncestors(itNode *ptr){
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
			aPrintStack(auxSpace);
			auxSpace.pop();
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				aPrintStack(auxSpace);
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
}

//Tested
void printAncestorsPreOrderIterative(iptNode *ptr){
	if(ptr == null){
		return;
	}
	stack<iptNode *> auxSpace;
	iptNode *currentNode,*temp;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		temp = currentNode;
		while(temp != null){
			printf("%d\t",temp->value);
			temp = temp->parent;
		}
		PRINT_NEW_LINE;
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printAncestorsOfNodeHashmap(hash_map<unsigned int,itNode *> &indexNodeMap,unsigned int index){
	while(index > 0){
		printf("%d\t",indexNodeMap.find(index)->second->value);
		index /= 2;
	}
	PRINT_NEW_LINE;
}

//Tested
void printAncestorsHashmap(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getTreeAsHashMap(ptr,1)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		printAncestorsOfNodeHashmap(indexNodeMap,itToIndexNodeMap->first);
	}
}

#endif /* PRINTANCESTORSITERATIVE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
