/****************************************************************************************************************************************************
 *  File Name                   : xorsillutils.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\xorsillutils.h
 *  Created on                  : Oct 16, 2014 :: 10:59:59 AM
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

#ifndef XORSILLUTILS_H_
#define XORSILLUTILS_H_

void insertIntoXORSill(xorSillNode **head,int value) {
    if(*head == null) {
        (*head) = new xorSillNode(value);
        return;
    }
    xorSillNode *prevNode = null,*crawler = *head,*temp;
    while(crawler->addressesXor ^ (intptr_t)prevNode) {
        temp = crawler;
        crawler = crawler->addressesXor ^ (intptr_t)prevNode;
        prevNode = temp;
    }
    temp = new xorSillNode(value);
    crawler->addressesXor = (intptr_t)prevNode ^ (intptr_t)temp;
}

void printXorList(xorSillNode *head) {
    if(head == null) {
        return;
    }
    xorSillNode *prevNode = null,*crawler = head;
    while(crawler != null) {
        printf("%d",crawler->value);
        prevNode = crawler;
        crawler = (xorSillNode *)(crawler->addressesXor ^ (intptr_t)prevNode);
    }
}

#endif /* XORSILLUTILS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
