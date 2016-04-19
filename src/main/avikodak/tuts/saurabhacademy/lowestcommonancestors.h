/****************************************************************************************************************************************************
 *  File Name                   : lowestcommonancestors.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\saurabhacademy\lowestcommonancestors.h
 *  Created on                  : Dec 19, 2014 :: 11:12:39 AM
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

#ifndef LOWESTCOMMONANCESTORS_H_
#define LOWESTCOMMONANCESTORS_H_

//Assuming all values are unique
int lowestCommonAncestors(itNode *root,int firstValue,int secondValue) {
    if(root == null) {
        return INT_MAX;
    }
    treeutils *utils = new treeutils();
    vector<int> inorder = utils->getValuesInInorder(root);
    vector<int> postorder = utils->getValuesInPostorder(root);
    hash_map<int,unsigned int> valueRankMap;
    hash_map<int,unsigned int>::iterator itToValueRankMap;
    int firstValIndex,secondValIndex;
    for(unsigned int counter = 0; counter < postorder.size(); counter++) {
        valueRankMap.insert(pair<int,unsigned int>(postorder[counter],counter));
    }
    for(unsigned int counter = 0; counter < inorder.size(); counter++) {
        if(inorder[counter] == firstValue) {
            firstValIndex = counter;
        } else if(inorder[counter] == secondValue) {
            secondValIndex = counter;
        }
    }
    unsigned int ancestorIndex = 0;
    for(unsigned int counter = firstValIndex < secondValIndex?firstValIndex:secondValIndex; counter <= firstValIndex > secondValIndex?firstValIndex:secondValIndex; counter++) {
        itToValueRankMap = valueRankMap.find(postorder[counter]);
        ancestorIndex = max(ancestorIndex,itToValueRankMap->second);
    }
    return postorder[ancestorIndex];
}

#endif /* LOWESTCOMMONANCESTORS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
