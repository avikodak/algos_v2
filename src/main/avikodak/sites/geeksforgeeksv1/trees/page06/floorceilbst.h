/****************************************************************************************************************************************************
 *  File Name                   : floorceilbst.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\floorceilbst.h
 *  Created on                  : Nov 13, 2014 :: 12:20:17 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/floor-and-ceil-from-a-bst/
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

#ifndef FLOORCEILBST_H_
#define FLOORCEILBST_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int ceilBST(itNode *ptr,int value) {
    if(ptr == null) {
        return INT_MIN;
    }
    if(ptr->value == value) {
        return ptr->value;
    }
    if(ptr->value < value) {
        return ceilBST(ptr->right,value);
    } else {
        int result = ceilBST(ptr->left,value);
        return result >= value?result:ptr->value;
    }
}

int floorBST(itNode *ptr,int value) {
    if(ptr == null) {
        return INT_MAX;
    }
    if(ptr->value == value) {
        return ptr->value;
    }
    if(ptr->value > value) {
        return floorBST(ptr->left,value);
    } else {
        int result = floorBST(ptr->right,value);
        return result < value?result:ptr->value;
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/


#endif /* FLOORCEILBST_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
