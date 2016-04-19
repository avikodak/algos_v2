/****************************************************************************************************************************************************
 *  File Name                   : bottomview.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page01\bottomview.h
 *  Created on                  : Jan 22, 2015 :: 7:39:58 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/bottom-view-binary-tree/
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
#include <stdint.h>
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef BOTTOMVIEW_H_
#define BOTTOMVIEW_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void bottomView(itNode *ptr) {
    if(ptr == null) {
        return;
    }
    hash_map<intptr_t,int> nodeHIndexMap;
    hash_map<intptr_t,int>::iterator itToNodeHIndexMap;
    hash_map<int,int> indexValueMap;
    hash_map<int,int>::iterator itToIndexValueMap;
    queue<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    int currentNodeHIndex;
    nodeHIndexMap.insert(pair<intptr_t,int>((intptr_t)ptr,0));
    while(!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        currentNodeHIndex = nodeHIndexMap.find((intptr_t)currentNode)->second;
        indexValueMap[currentNodeHIndex] = currentNode->value;
        if(currentNode->left != null) {
            auxSpace.push(currentNode->left);
            nodeHIndexMap.insert(pair<intptr_t,int>((intptr_t)currentNode->left,currentNodeHIndex-1));
        }
        if(currentNode->right != null) {
            auxSpace.push(currentNode->right);
            nodeHIndexMap.insert(pair<intptr_t,int>((intptr_t)currentNode->right,currentNodeHIndex+1));
        }
    }
    for(itToIndexValueMap = indexValueMap.begin(); itToIndexValueMap != indexValueMap.end(); itToIndexValueMap++) {
        printf("%d\t",itToIndexValueMap->second);
    }
}

#endif /* BOTTOMVIEW_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
