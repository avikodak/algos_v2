/****************************************************************************************************************************************************
 *  File Name   		: inordersuccessorbst.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\inordersuccessorbst.h
 *  Created on			: Oct 20, 2014 :: 3:24:20 PM
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

#ifndef INORDERSUCCESSORBST_H_
#define INORDERSUCCESSORBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *inOrderSuccessor(itNode *ptr,int value,bool &valueFound){
	if(ptr == null){
		return null;
	}
	itNode *auxNode;
	if(ptr->value == value){
		valueFound = true;
		if(ptr->right != null){
			auxNode = ptr->right;
			while(auxNode->left != null){
				auxNode = auxNode->left;
			}
			return auxNode;
		}
		return null;
	}
	if(ptr->value > value){
		auxNode = inOrderSuccessor(ptr->left,value,valueFound);
		if(auxNode != null){
			auxNode = ptr;
		}
	}else{
		auxNode = inOrderSuccessor(ptr->right,value,valueFound);
	}
	return auxNode;
}

itNode *inOrderSuccessorIterative(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	itNode *currentNode = ptr,*probableSuccessor = null;
	bool valFound = false;
	while(true){
		if(currentNode->value == value){
			valFound = true;
			if(currentNode->right == null){
				break;
			}
			currentNode = currentNode->right;
			while(currentNode->left != null){
				currentNode = currentNode->left;
			}
			return currentNode;
		}else{
			if(currentNode->value > value){
				probableSuccessor = currentNode;
				currentNode = currentNode->left;
			}else{
				currentNode = currentNode->right;
			}
		}
	}
	return valFound?probableSuccessor:null;
}

iptNode *inOrderSuccessorParentPtr(iptNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	iptNode *currentNode = ptr;
	while(currentNode != null){
		if(currentNode->value == value){
			if(currentNode->right == null){
				while(currentNode != null && currentNode->value < value){
					currentNode = currentNode->parent;
				}
				return currentNode;
			}else{
				currentNode = currentNode->right;
				while(currentNode->left != null){
					currentNode = currentNode->left;
				}
				return currentNode;
			}
		}else{
			if(currentNode->value > value){
				currentNode = currentNode->left;
			}else{
				currentNode = currentNode->right;
			}
		}
	}
	return null;
}

itNode *getInorderSuccessorPostOrderStack(stack<itNode *> auxSpace){
	itNode *keyNode = auxSpace.top();
	auxSpace.pop();
	if(keyNode->right == null){
		keyNode = keyNode->right;
		while(keyNode->left != null){
			keyNode = keyNode->left;
		}
		return keyNode;
	}
	while(!auxSpace.empty()){
		if(auxSpace.top()->value > keyNode->value){
			return auxSpace;
		}
	}
	return null;
}

itNode *getInorderSuccessorBSTPreorderIterativeV2(itNode *ptr,int value){
	if(ptr == null){
		return null;
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
			if(currentNode->value == value){
				return getInorderSuccessorPostOrderStack(auxSpace);
			}
			auxSpace.pop();
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				if(currentNode->value == value){
					return getInorderSuccessorPostOrderStack(auxSpace);
				}
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	return null;
}

#endif /* INORDERSUCCESSORBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
