/****************************************************************************************************************************************************
 *  File Name                   : pairwiseswapelements.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page03\pairwiseswapelements.h
 *  Created on                  : Oct 19, 2014 :: 1:01:58 PM
 *  Author                      : AVINASH
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

#ifndef PAIRWISESWAPELEMENTS_H_
#define PAIRWISESWAPELEMENTS_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void pairwiseSwapElements(sillNode *ptr) {
    if(ptr == null || ptr->next == null) {
        return;
    }
    int temp = ptr->value;
    ptr->value = ptr->next->value;
    ptr->next->value = temp;
    pairwiseSwapElements(ptr->next->next);
}

void pairwiseSwapElementsIterative(sillNode *ptr) {
    if(ptr == null || ptr->next == null) {
        return;
    }
    sillNode *crawler = ptr;
    while(crawler != null && crawler->next != null) {
        int temp = crawler->value;
        crawler->value = crawler->next->value;
        crawler->next->value = temp;
        crawler = crawler->next->next;
    }
}

void pairwiseSwapElementsHashmap(sillNode *ptr) {
    if(ptr == null || ptr->next == null) {
        return;
    }
    hash_map<unsigned int,int> rankValueMap;
    hash_map<unsigned int,int>::iterator itToRankValueMap;
    sillNode *crawler = ptr;
    unsigned int counter = 1;
    while(crawler != null) {
        rankValueMap.insert(pair<unsigned int,int>(counter,crawler->value));
        crawler = crawler->next;
        counter++;
    }
    crawler = ptr;
    for(unsigned int counter = 1; counter+1 < rankValueMap.size(); counter+=2) {
        crawler->value = rankValueMap.find(counter+1)->second;
        crawler->next->value = rankValueMap.find(counter)->second;
        crawler = crawler->next->next;
    }
}

void pairwiseElementsSwapPtrExchange(sillNode **ptr) {

}

void pairwiseElementsSwapPtrExchangeIterative(sillNode *ptr) {

}
#endif /* PAIRWISESWAPELEMENTS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
