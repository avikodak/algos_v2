/****************************************************************************************************************************************************
 *  File Name                   : palindromecheckforsill.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/linkedlist/page09/palindromecheckforsill.h
 *  Created on                  : Mar 25, 2017 :: 6:21:37 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

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

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_LINKEDLIST_PAGE09_PALINDROMECHECKFORSILL_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_LINKEDLIST_PAGE09_PALINDROMECHECKFORSILL_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
sillNode *reverseSill(sillNode *ptr, sillNode **head) {
    if (ptr == null) {
        return null;
    }
    if (ptr->next == null) {
        head = &ptr;
        return ptr;
    }
    sillNode *prevNode = reverseSill(ptr);
    prevNode->next = ptr;
    ptr->next = null;
    return ptr;
}

sillNode *cloneSill(sillNode *ptr) {
    if (ptr == null) {
        return null;
    }
    sillNode *clonedNextPtr = cloneSill(ptr->next);
    sillNode *clonedNewNode = new sillNode(ptr->value);
    clonedNewNode->next = clonedNextPtr;
    return clonedNewNode;
}

bool isIdentical(sillNode *fPtr, sillNode *sPtr) {
    if (fPtr == null && sPtr == null) {
        return true;
    }
    if (fPtr == null || sPtr == null) {
        return false;
    }
    return fPtr->value == sPtr->value && isIdentical(fPtr->next, sPtr->next);
}

bool isPalindrome(sillNode *ptr) {
    if (ptr == null || ptr->next == null) {
        return true;
    }
    sillNode *clonedHead = cloneSill(ptr);
    reverseSill(clonedHead, &clonedHead);
    return isIdentical(ptr, clonedHead);
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

#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_LINKEDLIST_PAGE09_PALINDROMECHECKFORSILL_H_ */
