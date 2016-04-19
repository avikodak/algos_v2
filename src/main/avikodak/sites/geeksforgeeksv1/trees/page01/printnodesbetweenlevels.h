/****************************************************************************************************************************************************
 *  File Name   		: printnodesbetweenlevels.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page01\printnodesbetweenlevels.h
 *  Created on			: Jan 22, 2015 :: 7:41:06 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/given-binary-tree-print-nodes-two-given-level-numbers/
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PRINTNODESBETWEENLEVELS_H_
#define PRINTNODESBETWEENLEVELS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printLevelUsingQueue(itNode *ptr,int firstLevel,int secondLevel) {
    if(ptr == null) {
        return;
    }
    queue<itNode *> auxSpace;
    int levelCounter = 1,nodeLevelCounter;
    auxSpace.push(ptr);
    itNode *currentNode;
    while(!auxSpace.empty()) {
        nodeLevelCounter = auxSpace.size();
        while(nodeLevelCounter--) {
            currentNode = auxSpace.front();
            auxSpace.pop();
            if(levelCounter >= firstLevel && levelCounter <= secondLevel) {
                printf("%d\t",currentNode->value);
            }
            if(currentNode->left != null) {
                auxSpace.push(currentNode->left);
            }
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
        }
        levelCounter++;
        if(levelCounter > secondLevel) {
            break;
        }
        PRINT_NEW_LINE;
    }
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printLevel(itNode *ptr,int level) {
    if(ptr == null) {
        return;
    }
    if(level == 0) {
        printf("%d\t",ptr->value);
        return;
    }
    printLevel(ptr->left,level-1);
    printLevel(ptr->right,level-1);
}

//Tested
void printNodesBetweenLevels(itNode *ptr,int firstLevel,int secondLevel) {
    if(ptr == null) {
        return;
    }
    for(int counter = firstLevel; counter <= secondLevel; counter++) {
        printLevel(ptr,counter-1);
        PRINT_NEW_LINE;
    }
}

#endif /* PRINTNODESBETWEENLEVELS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
