/****************************************************************************************************************************************************
 *  File Name   		: diagonalsum.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page01\diagonalsum.h
 *  Created on			: Jan 22, 2015 :: 7:39:44 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/diagonal-sum-binary-tree/
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

#ifndef DIAGONALSUM_H_
#define DIAGONALSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void diagonalSumMain(itNode *ptr,hash_map<int,int> &diagonalSum,int level) {
    if(ptr == null) {
        return;
    }
    hash_map<int,int>::iterator itToDiagonalSum;
    if((itToDiagonalSum = diagonalSum.find(level)) == diagonalSum.end()) {
        diagonalSum[level] = ptr->value;
    } else {
        diagonalSum[level] += ptr->value;
    }
    diagonalSumMain(ptr->left,diagonalSum,level-1);
    diagonalSumMain(ptr->right,diagonalSum,level);
}

//Tested
void printDiagonalSums(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    hash_map<int,int> diagonalSumMap;
    diagonalSumMain(ptr,diagonalSumMap,0);
    hash_map<int,int>::iterator itToDiagonalSumMap;
    for(itToDiagonalSumMap = diagonalSumMap.begin(); itToDiagonalSumMap != diagonalSumMap.end(); itToDiagonalSumMap++) {
        printf("%d\t",itToDiagonalSumMap->second);
    }
}

#endif /* DIAGONALSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
