/****************************************************************************************************************************************************
 *  File Name   		: checkifallleavesareatsamelevel.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page03\checkifallleavesareatsamelevel.h
 *  Created on			: Nov 14, 2014 :: 7:21:42 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/check-leaves-level/
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

#ifndef CHECKIFALLLEAVESAREATSAMELEVEL_H_
#define CHECKIFALLLEAVESAREATSAMELEVEL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool checkIfAllLeavesAreAtSameLevel(itNode *ptr,int level = 0){
	if(ptr == null){
		return true;
	}
	static int leafLevel = 0;
	if(ptr->left == null && ptr->right == null){
		if(leafLevel == 0){
			leafLevel = level;
		}
		return level == leafLevel;
	}
	return checkIfAllLeavesAreAtSameLevel(ptr->left,level+1) && checkIfAllLeavesAreAtSameLevel(ptr->right,level+1);
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool cIsLeafPresentInLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return false;
	}
	if(level == 0){
		return ptr->left == null && ptr->right == null;
	}
	return cIsLeafPresentInLevel(ptr->left,level-1) || cIsLeafPresentInLevel(ptr->right,level-1);
}

//Tested
bool areLeavesPresentInSameLevel(itNode *ptr){
	if(ptr == null){
		return false;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->getHeightOfTree(ptr);
	for(unsigned int counter = 0;counter < height-1;counter++){
		if(cIsLeafPresentInLevel(ptr,counter)){
			return false;
		}
	}
	return true;
}

#endif /* CHECKIFALLLEAVESAREATSAMELEVEL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
