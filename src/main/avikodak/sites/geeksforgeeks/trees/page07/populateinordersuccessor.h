/****************************************************************************************************************************************************
 *  File Name   		: populateinordersuccessor.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\populateinordersuccessor.h
 *  Created on			: Oct 23, 2014 :: 11:25:24 AM
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

#ifndef POPULATEINORDERSUCCESSOR_H_
#define POPULATEINORDERSUCCESSOR_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void populateInorderSuccessorMain(isuccesssorNode *ptr,isuccesssorNode **prevNode){
	if(ptr == null){
		return;
	}
	populateInorderSuccessorMain(ptr->left,prevNode);
	if(*prevNode != null){
		(*prevNode)->successor = ptr;
	}
	(*prevNode) = ptr;
	populateInorderSuccessorMain(ptr->right,prevNode);
}

void populateInorderSuccessor(isuccesssorNode *ptr){
	if(ptr == null){
		return;
	}
	isuccesssorNode *prevNode = null;
	populateInorderSuccessorMain(ptr,&prevNode);
	prevNode->successor = null;
}

void populateSuccessorReverseInorder(isuccesssorNode *ptr){
	if(ptr == null){
		return;
	}
	static isuccesssorNode *prevNode = null;
	populateSuccessorReverseInorder(ptr->right);
	ptr->successor = prevNode;
	prevNode = ptr;
	populateSuccessorReverseInorder(ptr->left);
}

void populateSuccessorReverseInorderIterative(isuccesssorNode *ptr){
	if(ptr == null){
		return;
	}
	stack<isuccesssorNode *> auxSpace;
	isuccesssorNode *currentNode = ptr;
	isuccesssorNode *prevNode = null;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->right;
		}
		if(!auxSpace.empty() && auxSpace.top()->left == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			currentNode->successor = prevNode;
			prevNode = currentNode;
			while(!auxSpace.empty() && auxSpace.top()->left == currentNode){
				currentNode = auxSpace.top();
				auxSpace.pop();
				currentNode->successor = prevNode;
				prevNode = currentNode;
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->left;
	}
}

void populateSuccessorInorderIterative(isuccesssorNode *ptr){
	if(ptr == null){
		return;
	}
	stack<isuccesssorNode *> auxSpace;
	isuccesssorNode *currentNode = ptr,*prevNode;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(prevNode != null){
				prevNode->successor = currentNode;
			}
			prevNode = currentNode;
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				auxSpace.pop();
				if(prevNode != null){
					prevNode->successor = currentNode;
				}
				prevNode = currentNode;
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	prevNode->successor = null;
}

void populateSuccessorInorderRetrieve(isuccesssorNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	vector<isuccesssorNode *> inorderNodes = utils->getNodesInInorder(ptr);
	isuccesssorNode *prevNode = null;
	for(int counter = inorderNodes.size()-1;counter >= 0;counter--){
		inorderNodes[counter]->successor = prevNode;
		prevNode = inorderNodes[counter];
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* POPULATEINORDERSUCCESSOR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
