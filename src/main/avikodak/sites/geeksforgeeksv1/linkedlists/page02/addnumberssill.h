/****************************************************************************************************************************************************
 *  File Name                   : addnumberssill.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page02\addnumberssill.h
 *  Created on                  : Oct 30, 2014 :: 11:46:58 AM
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
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef ADDNUMBERSSILL_H_
#define ADDNUMBERSSILL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
sillNode *addNumbersSill(sillNode *firstPtr,sillNode *secondPtr) {
    if(firstPtr == null && secondPtr == null) {
        return null;
    }
    if(firstPtr == null || secondPtr == null) {
        return firstPtr == null?secondPtr:firstPtr;
    }
    sillNode *resultHead,*resultCrawler,*newNode;
    unsigned int carry = 0;
    unsigned int currentSum;
    while(firstPtr != null && secondPtr != null) {
        currentSum = firstPtr->value + secondPtr->value + carry;
        carry = currentSum/10;
        if(resultHead == null) {
            resultHead = new sillNode(currentSum%10);
            resultCrawler = resultHead;
        } else {
            resultCrawler->next = new sillNode(currentSum % 10);
            resultCrawler = resultCrawler->next;
        }
        firstPtr = firstPtr->next;
        secondPtr = secondPtr->next;
    }
    while(firstPtr != null) {
        currentSum = firstPtr->value + carry;
        carry = currentSum/10;
        if(resultHead == null) {
            resultHead = new sillNode(currentSum%10);
            resultCrawler = resultHead;
        } else {
            resultCrawler->next = new sillNode(currentSum % 10);
            resultCrawler = resultCrawler->next;
        }
        firstPtr = firstPtr->next;
    }
    while(secondPtr != null) {
        currentSum = secondPtr->value + carry;
        carry = currentSum/10;
        if(resultHead == null) {
            resultHead = new sillNode(currentSum%10);
            resultCrawler = resultHead;
        } else {
            resultCrawler->next = new sillNode(currentSum % 10);
            resultCrawler = resultCrawler->next;
        }
        secondPtr = secondPtr->next;
    }
    return resultCrawler;
}

#endif /* ADDNUMBERSSILL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
