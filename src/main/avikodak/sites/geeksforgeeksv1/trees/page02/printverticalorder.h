/****************************************************************************************************************************************************
 *  File Name   		: printverticalorder.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\printverticalorder.h
 *  Created on			: Nov 15, 2014 :: 11:38:42 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PRINTVERTICALORDER_H_
#define PRINTVERTICALORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void setNodesVerticalOrderMain(itNode *ptr,int verticalLevel,map<int,vector<itNode *> > &verticalLevelNodesMap) {
    if(ptr == null) {
        return;
    }
    map<int,vector<itNode *> >::iterator itToVerticalLevelNodeMap = verticalLevelNodesMap.find(verticalLevel);
    if(itToVerticalLevelNodeMap == verticalLevelNodesMap.end()) {
        vector<itNode *> nodesList;
        nodesList.push_back(ptr);
        verticalLevelNodesMap[verticalLevel] = nodesList;
    } else {
        itToVerticalLevelNodeMap->second.push_back(ptr);
    }
    setNodesVerticalOrderMain(ptr->left,verticalLevel-1,verticalLevelNodesMap);
    setNodesVerticalOrderMain(ptr->right,verticalLevel+1,verticalLevelNodesMap);
}

//Tested
void printVerticalOrder(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    map<int,vector<itNode *> > verticalLevelNodesMap;
    map<int,vector<itNode *> >::iterator itToVerticalLevelNodesMap;
    setNodesVerticalOrderMain(ptr,0,verticalLevelNodesMap);
    for(itToVerticalLevelNodesMap = verticalLevelNodesMap.begin(); itToVerticalLevelNodesMap != verticalLevelNodesMap.end(); itToVerticalLevelNodesMap++) {
        for(unsigned int counter = 0; counter < itToVerticalLevelNodesMap->second.size(); counter++) {
            printf("%d\t",itToVerticalLevelNodesMap->second[counter]->value);
        }
        PRINT_NEW_LINE;
    }
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void findMinMaxVerticalLevel(itNode *ptr,int currentVerticalLevel,int *minVerticalLevel,int *maxVerticalLevel) {
    if(ptr == null) {
        return;
    }
    *minVerticalLevel = min(*minVerticalLevel,currentVerticalLevel);
    *maxVerticalLevel = max(*maxVerticalLevel,currentVerticalLevel);
    findMinMaxVerticalLevel(ptr->left,currentVerticalLevel-1,minVerticalLevel,maxVerticalLevel);
    findMinMaxVerticalLevel(ptr->right,currentVerticalLevel+1,minVerticalLevel,maxVerticalLevel);
}

//Tested
void printVerticalLevel(itNode *ptr,int verticalLevel,int currentLevel) {
    if(ptr == null) {
        return;
    }
    if(currentLevel == verticalLevel) {
        printf("%d\t",ptr->value);
    }
    printVerticalLevel(ptr->left,verticalLevel,currentLevel-1);
    printVerticalLevel(ptr->right,verticalLevel,currentLevel+1);
}

//Tested
void printAllVerticalLevel(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    int minVerticalLevel = INT_MAX,maxVerticalLevel = INT_MIN;
    findMinMaxVerticalLevel(ptr,0,&minVerticalLevel,&maxVerticalLevel);
    for(int counter = minVerticalLevel; counter <= maxVerticalLevel; counter++) {
        printVerticalLevel(ptr,counter,0);
        PRINT_NEW_LINE;
    }
}

#endif /* PRINTVERTICALORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
