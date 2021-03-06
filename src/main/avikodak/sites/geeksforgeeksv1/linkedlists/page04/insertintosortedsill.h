/****************************************************************************************************************************************************
 *  File Name                   : insertintosortedsill.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\insertintosortedsill.h
 *  Created on                  : Oct 15, 2014 :: 12:23:50 PM
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
#include <lib/utils/trieutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef INSERTINTOSORTEDSILL_H_
#define INSERTINTOSORTEDSILL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void insertIntoSortedSill(sillNode **ptr,int value) {
    sillNode *newNode,*crawler = *ptr;
    newNode = new sillNode(value);
    if(*ptr == null || (*ptr)->value > value) {
        newNode->next = (*ptr);
        (*ptr) = newNode;
        return;
    }
    while(crawler->next != null && crawler->next->value < value) {
        crawler = crawler->next;
    }
    newNode->next = crawler->next;
    crawler->next = newNode;
}

#endif /* INSERTINTOSORTEDSILL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
