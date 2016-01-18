/****************************************************************************************************************************************************
 *  File Name                   : identicaltrees.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/trees/page06/identicaltrees.h
 *  Created on                  : Jan 16, 2016 :: 10:56:21 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_IDENTICALTREES_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_IDENTICALTREES_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
bool areTreesIdenticalPreOrder(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	if(firstTreePtr->value != secondTreePtr->value){
		return false;
	}
	return areTreesIdenticalPreOrder(firstTreePtr->left,secondTreePtr->left) && areTreesIdenticalPreOrder(firstTreePtr->right,secondTreePtr->right);
}

bool areTreesIdenticalPreOrderIterative(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	stack<itNode *> firstAuxSpace,secondAuxSpace;
	itNode *firstCurrentNode,*secondCurrentNode;
	firstAuxSpace.push(firstTreePtr);
	secondAuxSpace.push(secondTreePtr);
	while(!firstAuxSpace.empty() && !secondAuxSpace.empty()){
		firstCurrentNode = firstAuxSpace.top();
		firstAuxSpace.pop();
		secondCurrentNode = secondAuxSpace.top();
		secondAuxSpace.pop();
		if(firstCurrentNode->value != secondCurrentNode->value){
			return false;
		}
		if(firstCurrentNode->left != null && secondCurrentNode->left != null){
			firstAuxSpace.push(firstCurrentNode->left);
			secondAuxSpace.push(secondCurrentNode->left);
		}else if(firstCurrentNode->left != null || secondCurrentNode->left != null){
			return false;
		}
		if(firstCurrentNode->right != null && secondCurrentNode->right != null){
			firstAuxSpace.push(firstCurrentNode->right);
			secondAuxSpace.push(secondCurrentNode->right);
		}else if(firstCurrentNode->right != null || secondCurrentNode->right != null){
			return false;
		}
	}
	return firstAuxSpace.empty() && secondAuxSpace.empty();
}

bool areTreesIdenticalInOrder(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return areTreesIdenticalInOrder(firstTreePtr->left,secondTreePtr->left) && firstTreePtr->value != secondTreePtr->value && areTreesIdenticalInOrder(firstTreePtr->right,secondTreePtr->right);
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_IDENTICALTREES_H_ */
