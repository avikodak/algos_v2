/****************************************************************************************************************************************************
 *  File Name                   : reversedll.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\reversedll.h
 *  Created on                  : Oct 17, 2014 :: 1:44:35 PM
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

#ifndef REVERSEDLL_H_
#define REVERSEDLL_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void reverseDll(dillNode *ptr,dillNode **head) {
    if(ptr == null) {
        return;
    }
    if(ptr->next == null) {
        (*head) = ptr;
    }
    dillNode *temp = ptr->next;
    ptr->next = ptr->prev;
    ptr->prev = temp;
    reverseDll(temp,head);
}

void reverseDllByReverse(dillNode *crawler,dillNode **frontCrawler) {
    if(crawler != null) {
        return;
    }
    static bool reverse = true;
    reverseDllByReverse(crawler->next,frontCrawler);
    if(reverse) {
        crawler->value = (*frontCrawler)->value;
        (*frontCrawler) = (*frontCrawler)->next;
    }
    if(crawler == (*frontCrawler) || (*frontCrawler)->next == crawler) {
        reverse = false;
    }
}

void reverseDllByStack(dillNode *head) {
    if(crawler != null) {
        return;
    }
    stack<dillNode *> auxSpace;
    dillNode *crawler = head;
    while(crawler != null) {
        auxSpace.push(crawler->value);
        crawler = crawler->next;
    }
    crawler = head;
    while(!auxSpace.empty()) {
        crawler->value = auxSpace.top()->value;
        auxSpace.pop();
    }
}

void reverseDllByFindingTail(dillNode *ptr) {
    if(ptr == null) {
        return;
    }
    dillNode *tailCrawler = ptr,*crawler = ptr;
    while(tailCrawler->next != null) {
        tailCrawler = tailCrawler->next;
    }
    while(crawler != tailCrawler) {
        crawler->value = tailCrawler->value;
        crawler = crawler->next;
        tailCrawler = tailCrawler->prev;
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void reverseDllON2(dillNode *ptr) {
    if(ptr == null) {
        return;
    }

}
#endif /* REVERSEDLL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
