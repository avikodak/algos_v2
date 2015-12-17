/****************************************************************************************************************************************************
 *  File Name   		: closestleaf.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page01\closestleaf.h
 *  Created on			: Jan 23, 2015 :: 8:49:43 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-closest-leaf-binary-tree/
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef CLOSESTLEAF_H_
#define CLOSESTLEAF_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void closestLeafMain(itNode *ptr,itNode **leaf,int &minHeight,int level){
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		if(minHeight > level){
			minHeight = level;
			(*leaf) = ptr;
		}
		return;
	}
	closestLeafMain(ptr->left,leaf,minHeight,level+1);
	closestLeafMain(ptr->right,leaf,minHeight,level+1);
}

//Tested
void ancestorsMain(itNode *ptr,itNode **leaf,stack<itNode *> auxSpace,int value){
	if(ptr == null){
		return;
	}
	auxSpace.push(ptr);
	if(ptr->value == value){
		int minLevel = INT_MAX,counter = 0;
		while(!auxSpace.empty()){
			closestLeafMain(auxSpace.top(),leaf,minLevel,counter);
			auxSpace.pop();
			counter++;
		}
		return;
	}
	ancestorsMain(ptr->left,leaf,auxSpace,value);
	ancestorsMain(ptr->right,leaf,auxSpace,value);
}

//Tested
itNode *getClosestLeaf(itNode *ptr,int key){
	if(ptr == null){
		return null;
	}
	stack<itNode *> auxSpace;
	itNode *leaf = null;
	ancestorsMain(ptr,&leaf,auxSpace,key);
	return leaf;
}

#endif /* CLOSESTLEAF_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
