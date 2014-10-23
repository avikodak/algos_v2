/****************************************************************************************************************************************************
 *  File Name   		: foldabletrees.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\foldabletrees.h
 *  Created on			: Oct 20, 2014 :: 3:14:39 PM
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

#include "../page09/mirrortree.h"
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
bool isTreeFoldableMain(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return isTreeFoldableMain(firstTreePtr->left,secondTreePtr->right) &&  isTreeFoldableMain(firstTreePtr->right,secondTreePtr->left);
}

bool isTreeFoldable(itNode *ptr){
	if(ptr == null){
		return true;
	}
	return isTreeFoldableMain(ptr->left,ptr->right);
}

bool areTreesIdenticalStructure(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return areTreesIdenticalStructure(firstTreePtr->left,secondTreePtr->left) && areTreesIdenticalStructure(firstTreePtr->right,secondTreePtr->right);
}

bool isTreeFoldable(itNode *ptr){
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
