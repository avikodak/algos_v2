/****************************************************************************************************************************************************
 *  File Name                   : issillpalindrome.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\issillpalindrome.h
 *  Created on                  : Oct 14, 2014 :: 12:58:42 PM
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

#include "../../../geeksforgeeksv1/linkedlists/page04/reversesill.h"
/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef ISSILLPALINDROME_H_
#define ISSILLPALINDROME_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool isSillPalindrome(sillNode *ptr,sillNode **frontCrawler) {
    if(ptr == null) {
        return true;
    }
    bool truthValue = isSillPalindrome(ptr->next,frontCrawler);
    truthValue = truthValue && (ptr->value == (*frontCrawler)->value);
    (*frontCrawler) = (*frontCrawler)->next;
    return truthValue;
}

//Tested
bool isSillPalindromeAuxspace(sillNode *ptr) {
    if(ptr == null) {
        return true;
    }
    stack<sillNode *> auxSpace;
    sillNode *crawler = ptr;
    while(crawler != null) {
        auxSpace.push(crawler);
        crawler = crawler->next;
    }
    crawler = ptr;
    while(!auxSpace.empty()) {
        if(crawler->value != auxSpace.top()->value) {
            return false;
        }
        auxSpace.pop();
        crawler = crawler->next;
    }
    return true;
}

//Tested
bool isSillPalindromeByReverse(sillNode *ptr) {
    if(ptr == null) {
        return true;
    }
    sillNode *reversedSill = reverseSillNewSill(ptr);
    while(ptr != null && reversedSill != null) {
        if(ptr->value != reversedSill->value) {
            return false;
        }
        ptr = ptr->next;
        reversedSill = reversedSill->next;
    }
    return true;
}

//Tested
bool isSillPalindromeHashmap(sillNode *ptr) {
    if(ptr == null) {
        return true;
    }
    sillutils *utils = new sillutils();
    hash_map<unsigned int,sillNode *> indexNodeMap = utils->getSillAsHashmap(ptr,1)->indexNodeMap;
    hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
    unsigned int lengthOfSill = utils->lengthOfSill(ptr);
    for(unsigned int counter = lengthOfSill; counter > lengthOfSill/2; counter--) {
        itToIndexNodeMap = indexNodeMap.find(counter);
        if(ptr->value != itToIndexNodeMap->second->value) {
            return false;
        }
        ptr = ptr->next;
    }
    return true;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
sillNode *getNodeForIndexSill(sillNode *ptr,unsigned int index) {
    if(ptr == null) {
        return null;
    }
    if(index == 0) {
        return ptr;
    }
    return getNodeForIndexSill(ptr->next,index-1);
}

//Tested
bool isSillPalindromeON2(sillNode *ptr) {
    if(ptr == null) {
        return true;
    }
    sillutils *utils = new sillutils();
    unsigned int lengthOfSill = utils->lengthOfSill(ptr);
    sillNode *crawler = ptr,*temp;
    for(unsigned int counter = 0; counter <= lengthOfSill/2; counter++) {
        temp = getNodeForIndexSill(ptr,lengthOfSill-counter-1);
        if(temp->value != crawler->value) {
            return false;
        }
        crawler = crawler->next;
    }
    return true;
}

#endif /* ISSILLPALINDROME_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
