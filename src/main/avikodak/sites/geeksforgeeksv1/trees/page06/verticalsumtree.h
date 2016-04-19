/****************************************************************************************************************************************************
 *  File Name                   : verticalsumtree.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\verticalsumtree.h
 *  Created on                  : Oct 23, 2014 :: 6:13:06 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/vertical-sum-in-a-given-binary-tree/
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef VERTICALSUMTREE_H_
#define VERTICALSUMTREE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void setVerticalSum(itNode *ptr,int currentVerticalLevel,hash_map<int,int> &verticalSumMap) {
    if(ptr == null) {
        return;
    }
    hash_map<int,int>::iterator itToVerticalSumMap;
    if((itToVerticalSumMap = verticalSumMap.find(currentVerticalLevel)) == verticalSumMap.end()) {
        verticalSumMap.insert(pair<int,int>(currentVerticalLevel,ptr->value));
    } else {
        verticalSumMap[currentVerticalLevel] += ptr->value;
    }
    setVerticalSum(ptr->left,currentVerticalLevel-1,verticalSumMap);
    setVerticalSum(ptr->right,currentVerticalLevel+1,verticalSumMap);
}

//Tested
void printVerticalSums(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    hash_map<int,int> verticalSums;
    setVerticalSum(ptr,0,verticalSums);
    hash_map<int,int>::iterator itToVerticalSums;
    for(itToVerticalSums = verticalSums.begin(); itToVerticalSums != verticalSums.end(); itToVerticalSums++) {
        printf("%d %d\n",itToVerticalSums->first,itToVerticalSums->second);
    }
}

#endif /* VERTICALSUMTREE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
