/****************************************************************************************************************************************************
 *  File Name   		: treeisomorphism.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page04\treeisomorphism.h
 *  Created on			: Nov 14, 2014 :: 12:07:06 AM
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TREEISOMORPHISM_H_
#define TREEISOMORPHISM_H_

//Tested
bool areTreesIsomorphs(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	if(firstTreePtr->value != secondTreePtr->value){
		return false;
	}
	return (areTreesIsomorphs(firstTreePtr->left,secondTreePtr->left)&&areTreesIsomorphs(firstTreePtr->right,secondTreePtr->right)) || (areTreesIsomorphs(firstTreePtr->left,secondTreePtr->right)&&areTreesIsomorphs(firstTreePtr->right,secondTreePtr->left));
}

#endif /* TREEISOMORPHISM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
