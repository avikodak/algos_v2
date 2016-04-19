/****************************************************************************************************************************************************
 *  File Name   		: verticalorderhashmap.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\verticalorderhashmap.h
 *  Created on			: Nov 16, 2014 :: 8:40:06 AM
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

#ifndef VERTICALORDERHASHMAP_H_
#define VERTICALORDERHASHMAP_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void setNodesInVerticalLevel(itNode *ptr,int currentVerticalLevel,map<int,vector<itNode *> > &verticalNodesMap) {
    if(ptr == null) {
        return;
    }
    map<int,vector<itNode *> >::iterator itToVerticalNodeMap = verticalNodesMap.find(currentVerticalLevel);
    if(itToVerticalNodeMap == verticalNodesMap.end()) {
        vector<itNode *> nodesList;
        nodesList.push_back(ptr);
        verticalNodesMap[currentVerticalLevel] = nodesList;
    } else {
        itToVerticalNodeMap->second.push_back(ptr);
    }
    setNodesInVerticalLevel(ptr->left,currentVerticalLevel-1,verticalNodesMap);
    setNodesInVerticalLevel(ptr->right,currentVerticalLevel+1,verticalNodesMap);
}

//Tested
void printVerticalLevels(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    map<int,vector<itNode *> > verticalNodesMap;
    map<int,vector<itNode *> >::iterator itToVerticalNodeMap;
    setNodesInVerticalLevel(ptr,0,verticalNodesMap);
    for(itToVerticalNodeMap = verticalNodesMap.begin(); itToVerticalNodeMap != verticalNodesMap.end(); itToVerticalNodeMap++) {
        for(unsigned int counter = 0; counter < itToVerticalNodeMap->second.size(); counter++) {
            printf("%d\t",itToVerticalNodeMap->second[counter]->value);
        }
        PRINT_NEW_LINE;
    }
}

#endif /* VERTICALORDERHASHMAP_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
