/****************************************************************************************************************************************************
 *  File Name                   : checkiftreesubtree.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page07\checkiftreesubtree.h
 *  Created on                  : Oct 23, 2014 :: 10:15:35 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/
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

#ifndef CHECKIFTREESUBTREE_H_
#define CHECKIFTREESUBTREE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool isContinousSubset(vector<int> firstUserinput,vector<int> secondUserinput) {
    if(firstUserinput.size() == 0 || secondUserinput.size() == 0) {
        return true;
    }
    unsigned int outerCrawler,firstCrawler,secondCrawler;
    if(secondUserinput.size() > firstUserinput.size()) {
        firstUserinput.swap(secondUserinput);
    }
    printIVector(firstUserinput);
    PRINT_NEW_LINE;
    printIVector(secondUserinput);
    PRINT_NEW_LINE;
    for(outerCrawler = 0; outerCrawler < firstUserinput.size(); outerCrawler++) {
        firstCrawler = outerCrawler;
        secondCrawler = 0;
        while(secondCrawler < secondUserinput.size() && firstCrawler < firstUserinput.size()) {
            if(firstUserinput[firstCrawler] != secondUserinput[secondCrawler]) {
                break;
            }
            secondCrawler++;
            firstCrawler++;
        }
        if(secondCrawler == secondUserinput.size()) {
            return true;
        }
    }
    return false;
}

//Tested
bool isTreeSubTree(itNode *firstPtr,itNode *secondPtr) {
    if(firstPtr == null || secondPtr == null) {
        return true;
    }
    treeutils *utils = new treeutils();
    vector<int> preOrderValuesFirstTree = utils->getValuesInPreorder(firstPtr);
    vector<int> preOrderValuesSecondTree = utils->getValuesInPreorder(secondPtr);
    vector<int> inOrderValuesFirstTree = utils->getValuesInInorder(firstPtr);
    vector<int> inOrderValuesSecondTree = utils->getValuesInInorder(secondPtr);
    return isContinousSubset(preOrderValuesFirstTree,preOrderValuesSecondTree) && isContinousSubset(inOrderValuesFirstTree,inOrderValuesSecondTree);
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool areTreesIdentical(itNode *firstPtr,itNode *secondPtr) {
    if(firstPtr == null && secondPtr == null) {
        return true;
    }
    if(firstPtr == null || secondPtr == null) {
        return false;
    }
    return firstPtr->value == secondPtr->value && areTreesIdentical(firstPtr->left,secondPtr->left) && areTreesIdentical(firstPtr->right,secondPtr->right);
}

//Tested
bool isTreeSubTreeON2(itNode *firstPtr,itNode *secondPtr) {
    if(firstPtr == null || secondPtr == null) {
        return true;
    }
    return areTreesIdentical(firstPtr,secondPtr) || isTreeSubTreeON2(firstPtr->left,secondPtr) || isTreeSubTreeON2(firstPtr->right,secondPtr);
}

#endif /* CHECKIFTREESUBTREE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
