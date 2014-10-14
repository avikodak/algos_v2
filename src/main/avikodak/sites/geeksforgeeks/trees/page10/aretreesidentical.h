/****************************************************************************************************************************************************
 *  File Name   		: aretreesidentical.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page10\aretreesidentical.h
 *  Created on			: Oct 11, 2014 :: 12:20:22 AM
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

#ifndef ARETREESIDENTICAL_H_
#define ARETREESIDENTICAL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool areTreesIdenticalPreOrder(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return firstTreePtr->value == secondTreePtr->value && areTreesIdenticalPreOrder(firstTreePtr->left,secondTreePtr->left) && areTreesIdenticalPreOrder(firstTreePtr->right,secondTreePtr->right);
}

//Tested
bool areTreesIdenticalPreOrderIterative(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	stack<itNode *> firstTreeAuxSpace,secondTreeAuxSpace;
	itNode *currentNodeFirstTree,*currentNodeSecondTree;
	firstTreeAuxSpace.push(firstTreePtr);
	secondTreeAuxSpace.push(secondTreePtr);
	while(!firstTreeAuxSpace.empty() && !secondTreeAuxSpace.empty()){
		currentNodeFirstTree = firstTreeAuxSpace.top();
		currentNodeSecondTree = secondTreeAuxSpace.top();
		firstTreeAuxSpace.pop();
		secondTreeAuxSpace.pop();
		if(currentNodeFirstTree->value != currentNodeSecondTree->value){
			return false;
		}
		if(currentNodeFirstTree->left != null && currentNodeSecondTree->left != null){
			firstTreeAuxSpace.push(currentNodeFirstTree->left);
			secondTreeAuxSpace.push(currentNodeSecondTree->left);
		}else if(currentNodeFirstTree->left != null || currentNodeSecondTree->left != null){
			return false;
		}
		if(currentNodeFirstTree->right != null && currentNodeSecondTree->right != null){
			firstTreeAuxSpace.push(currentNodeFirstTree->right);
			secondTreeAuxSpace.push(currentNodeSecondTree->right);
		}else if(currentNodeFirstTree->right != null || currentNodeSecondTree->right != null){
			return false;
		}
	}
	return firstTreeAuxSpace.empty() && secondTreeAuxSpace.empty();
}

//Tested
bool areTreesIdenticalInOrder(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return areTreesIdenticalInOrder(firstTreePtr->left,secondTreePtr->left) && firstTreePtr->value == secondTreePtr->value && areTreesIdenticalInOrder(firstTreePtr->right,secondTreePtr->right);
}

//Tested
bool areTreesIdenticalInorderIterative(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	stack<itNode *> firstTreeAuxspace,secondTreeAuxspace;
	itNode *currentNodeFirstTree = firstTreePtr,*currentNodeSecondTree = secondTreePtr;
	while(!firstTreeAuxspace.empty() || !secondTreeAuxspace.empty() || currentNodeFirstTree != null || currentNodeSecondTree != null){
		if(currentNodeFirstTree != null){
			if(currentNodeSecondTree == null){
				return false;
			}
			firstTreeAuxspace.push(currentNodeFirstTree);
			secondTreeAuxspace.push(currentNodeSecondTree);
			currentNodeFirstTree = currentNodeFirstTree->left;
			currentNodeSecondTree = currentNodeSecondTree->left;
		}else{
			if(currentNodeSecondTree != null){
				return false;
			}
			currentNodeFirstTree = firstTreeAuxspace.top();
			currentNodeSecondTree = secondTreeAuxspace.top();
			firstTreeAuxspace.pop();
			secondTreeAuxspace.pop();
			if(currentNodeFirstTree->value != currentNodeSecondTree->value){
				return false;
			}
			currentNodeFirstTree = currentNodeFirstTree->right;
			currentNodeSecondTree = currentNodeSecondTree->right;
		}
	}
	return firstTreeAuxspace.empty() && secondTreeAuxspace.empty() && currentNodeFirstTree == null && currentNodeSecondTree == null;
}

//Tested
bool areTreesIdenticalPostOrder(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return areTreesIdenticalPostOrder(firstTreePtr->left,secondTreePtr->left) && areTreesIdenticalPostOrder(firstTreePtr->right,secondTreePtr->right) && firstTreePtr->value == secondTreePtr->value;
}

bool areTreesIdenticalPostOrderIterativeTwoStacks(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	stack<itNode *> firstTreePrimaryAuxspace,firstTreeSecondaryAuxspace,secondTreePrimaryAuxspace,secondTreeSecondaryAuxspace;
	//itNode *firstTreeCurrentNode,*secondTreeCurrentNode;
	return false;
}

bool areTreesIdenticalPostOrderIterative(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return false;
}

bool areTreesIdenticalPostOrderIterativeV2(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return false;
}

//Tested
bool areTreesIdenticalHashmap(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	treeutils *utils = new treeutils();
	itHashmap *firstTreeHashmap = utils->getTreeAsHashMap(firstTreePtr);
	itHashmap *secondTreeHashmap = utils->getTreeAsHashMap(secondTreePtr);
	hash_map<unsigned int,itNode *> firstTreeIndexNodeMap = firstTreeHashmap->indexNodeMap;
	hash_map<unsigned int,itNode *> secondTreeIndexNodeMap = secondTreeHashmap->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToFirstTreeIndexNodeMap,itToSecondTreeIndexNodeMap;
	if(firstTreeIndexNodeMap.size() != secondTreeIndexNodeMap.size()){
		return false;
	}
	for(itToFirstTreeIndexNodeMap = firstTreeIndexNodeMap.begin();itToFirstTreeIndexNodeMap != firstTreeIndexNodeMap.end();itToFirstTreeIndexNodeMap++){
		itToSecondTreeIndexNodeMap = secondTreeIndexNodeMap.find(itToFirstTreeIndexNodeMap->first);
		if(itToSecondTreeIndexNodeMap == secondTreeIndexNodeMap.end()){
			return false;
		}
		if(itToSecondTreeIndexNodeMap->second->value != itToFirstTreeIndexNodeMap->second->value){
			return false;
		}
	}
	return true;
}

//Tested
bool areTreesIdenticalPreInOrderValues(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	vector<int> firstTreeAuxspace,secondTreeAuxspace;
	treeutils *utils = new treeutils();
	firstTreeAuxspace = utils->getValuesInPreorder(firstTreePtr);
	secondTreeAuxspace = utils->getValuesInPreorder(secondTreePtr);
	if(!areIVectorsEquivalent(firstTreeAuxspace,secondTreeAuxspace)){
		return false;
	}
	firstTreeAuxspace = utils->getValuesInInorder(firstTreePtr);
	secondTreeAuxspace = utils->getValuesInInorder(secondTreePtr);
	return areIVectorsEquivalent(firstTreeAuxspace,secondTreeAuxspace);
}

//Tested
bool areTreesIdenticalPostInOrderValues(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	vector<int> firstTreeAuxspace,secondTreeAuxspace;
	treeutils *utils = new treeutils();
	firstTreeAuxspace = utils->getValuesInPostorder(firstTreePtr);
	secondTreeAuxspace = utils->getValuesInPostorder(secondTreePtr);
	if(!areIVectorsEquivalent(firstTreeAuxspace,secondTreeAuxspace)){
		return false;
	}
	firstTreeAuxspace = utils->getValuesInInorder(firstTreePtr);
	secondTreeAuxspace = utils->getValuesInInorder(secondTreePtr);
	return areIVectorsEquivalent(firstTreeAuxspace,secondTreeAuxspace);
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* ARETREESIDENTICAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
