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
