/****************************************************************************************************************************************************
 *  File Name   		: topview.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page01\topview.h
 *  Created on			: Jan 22, 2015 :: 7:40:14 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/
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

#ifndef TOPVIEW_H_
#define TOPVIEW_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void topViewMain(itNode *ptr,map<int,int> &levelValueMap,int verticalLevel) {
    if(ptr == null) {
        return;
    }
    topViewMain(ptr->left,levelValueMap,verticalLevel-1);
    topViewMain(ptr->right,levelValueMap,verticalLevel+1);
    levelValueMap[verticalLevel] = ptr->value;
}

//Tested
void topView(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    map<int,int> levelValueMap;
    map<int,int>::iterator itToLevelValueMap;
    topViewMain(ptr,levelValueMap,0);
    for(itToLevelValueMap = levelValueMap.begin(); itToLevelValueMap != levelValueMap.end(); itToLevelValueMap++) {
        printf("%d\t",itToLevelValueMap->second);
    }
}

#endif /* TOPVIEW_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
