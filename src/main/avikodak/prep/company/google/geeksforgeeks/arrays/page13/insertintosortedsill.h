/****************************************************************************************************************************************************
 *  File Name                   : insertintosortedsill.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/arrays/page13/insertintosortedsill.h
 *  Created on                  : Mar 25, 2017 :: 6:52:50 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

#include <lib/ds/linkedlistds.h>

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <stdexcept>
#include <limits.h>
#include <stdint.h>
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_ARRAYS_PAGE13_INSERTINTOSORTEDSILL_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_ARRAYS_PAGE13_INSERTINTOSORTEDSILL_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
void insertIntoSortedSill(sillNode **head, int value) {
    if (*head == null) {
        *head = new sillNode(value);
        return;
    } else if ((*head)->value > value) {
        sillNode *newNode = new sillNode(value);
        newNode->next = *head;
        (*head) = newNode;
        return;
    } else {
        sillNode *crawler = *head;
        sillNode *prevPtr = null;
        while (crawler != null && crawler->value < value) {
            prevPtr = crawler;
            crawler = crawler->next;
        }
        sillNode *newNode = new sillNode(value);
        newNode->next = prevPtr->next;
        prevPtr->next = newNode;
    }
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_ARRAYS_PAGE13_INSERTINTOSORTEDSILL_H_ */
