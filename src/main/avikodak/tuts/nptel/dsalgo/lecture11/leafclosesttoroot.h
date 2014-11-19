/****************************************************************************************************************************************************
 *  File Name   		: leafclosesttoroot.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture11\leafclosesttoroot.h
 *  Created on			: Nov 18, 2014 :: 5:28:27 PM
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

#ifndef LEAFCLOSESTTOROOT_H_
#define LEAFCLOSESTTOROOT_H_

void leafClosestToRootMain(itNode *ptr,itNode **ptrToLeaf,unsigned int currentLevel = 1){
	static unsigned int minLevel = UINT_MAX;
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		if(currentLevel < minLevel){
			minLevel = currentLevel;
			*ptrToLeaf = ptr;
		}
		return;
	}
	leafClosestToRootMain(ptr->left,ptrToLeaf,currentLevel+1);
	leafClosestToRootMain(ptr->right,ptrToLeaf,currentLevel+1);
}

itNode *getLeafClosestToRoot(itNode *ptr){
	if(ptr == null){
		return null;
	}
	itNode *leaf = null;
	leafClosestToRootMain(ptr,&leaf);
	return leaf;
}

#endif /* LEAFCLOSESTTOROOT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
