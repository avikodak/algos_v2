/****************************************************************************************************************************************************
 *  File Name                   : maxsumtwoleaves.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\maxsumtwoleaves.h
 *  Created on                  : Jan 24, 2015 :: 10:30:04 AM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef MAXSUMTWOLEAVES_H_
#define MAXSUMTWOLEAVES_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int maxPathSumUtilTwoLeaves(itNode *ptr,int &maxSum) {
    if(ptr == null) {
        return 0;
    }
    int leftValue = maxPathSumUtilTwoLeaves(ptr->left,maxSum);
    int rightValue = maxPathSumUtilTwoLeaves(ptr->right,maxSum);
    maxSum = max(maxSum,max(max(leftValue,rightValue),ptr->value + leftValue + rightValue));
    return max(leftValue,rightValue) + ptr->value;
}

#endif /* MAXSUMTWOLEAVES_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
