/****************************************************************************************************************************************************
 *  File Name   		: foldabletrees.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\foldabletrees.h
 *  Created on			: Oct 20, 2014 :: 3:14:39 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/foldable-binary-trees/
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

#include "../../../geeksforgeeksv1/trees/page09/mirrortree.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef FOLDABLETREES_H_
#define FOLDABLETREES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isTreeFoldableMain(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return isTreeFoldableMain(firstTreePtr->left,secondTreePtr->right) &&  isTreeFoldableMain(firstTreePtr->right,secondTreePtr->left);
}

//Tested
bool isTreeFoldable(itNode *ptr){
	if(ptr == null){
		return true;
	}
	return isTreeFoldableMain(ptr->left,ptr->right);
}

//Tested
bool areTreesIdenticalStructure(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return areTreesIdenticalStructure(firstTreePtr->left,secondTreePtr->left) && areTreesIdenticalStructure(firstTreePtr->right,secondTreePtr->right);
}

//Tested
bool isTreeFoldableV2(itNode *ptr){
	if(ptr == null){
		return true;
	}
	getMirrorTreePreorder(ptr->right);
	return areTreesIdenticalStructure(ptr->left,ptr->right);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* FOLDABLETREES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
