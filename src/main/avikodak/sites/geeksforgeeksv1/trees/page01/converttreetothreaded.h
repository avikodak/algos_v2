/****************************************************************************************************************************************************
 *  File Name                   : converttreetothreaded.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page01\converttreetothreaded.h
 *  Created on                  : Jan 22, 2015 :: 7:40:53 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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

#ifndef CONVERTTREETOTHREADED_H_
#define CONVERTTREETOTHREADED_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void convertTreeToThreaded(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    itNode *currentNode = ptr,*temp;
    while(currentNode != null) {
        if(currentNode->left != null) {
            temp = currentNode->left;
            while(temp->right != null && temp->right != currentNode) {
                temp = temp->right;
            }
            if(temp->right == null) {
                temp->right = currentNode;
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        } else {
            currentNode = currentNode->right;
        }
    }
}

#endif /* CONVERTTREETOTHREADED_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
