/****************************************************************************************************************************************************
 *  File Name   		: printancestors.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\printancestors.h
 *  Created on			: Oct 20, 2014 :: 8:38:49 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/
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

#ifndef PRINTANCESTORS_H_
#define PRINTANCESTORS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printAncestorsForValue(itNode *ptr,int value,stack<itNode *> auxSpace){
	if(ptr == null){
		return;
	}
	if(ptr->value == value){
		itNode *currentNode;
		while(!auxSpace.empty()){
			currentNode = auxSpace.top();
			auxSpace.pop();
			printf("%d\t",currentNode->value);
		}
		return;
	}
	auxSpace.push(ptr);
	printAncestorsForValue(ptr->left,value,auxSpace);
	printAncestorsForValue(ptr->right,value,auxSpace);
}

//Tested
bool printAncestors(itNode *ptr,int value){
	if(ptr == null){
		return false;
	}
	if(ptr->value == value){
		return true;
	}
	if(printAncestors(ptr->left,value) || printAncestors(ptr->right,value)){
		printf("%d\t",ptr->value);
		return true;
	}
	return false;
}

//Tested
void printStack(stack<itNode *> auxSpace){
	itNode *currentNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		printf("%d\t",currentNode->value);
	}
}

//Tested
void printAncestorsPostOrderTraversalV2(itNode *ptr,int value){
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
			if(currentNode->value == value){
				printStack(auxSpace);
			}
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				auxSpace.pop();
				if(currentNode->value == value){
					printStack(auxSpace);
				}
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isValuePresentInTree(itNode *ptr,int value){
	if(ptr == null){
		return false;
	}
	if(ptr->value == value){
		return true;
	}
	return isValuePresentInTree(ptr->left,value) || isValuePresentInTree(ptr->right,value);
}

//Tested
void printAncestorsInTree(itNode *ptr,int value){
	if(ptr == null){
		return;
	}
	if(isValuePresentInTree(ptr->left,value) || isValuePresentInTree(ptr->right,value)){
		printf("%d\t",ptr->value);
	}
	printAncestorsInTree(ptr->left,value);
	printAncestorsInTree(ptr->right,value);
}

#endif /* PRINTANCESTORS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
