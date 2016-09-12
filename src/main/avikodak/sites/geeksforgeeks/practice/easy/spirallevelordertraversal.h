/****************************************************************************************************************************************************
 *  File Name                   : spirallevelordertraversal.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/spirallevelordertraversal.h
 *  Created on                  : Sep 6, 2016 :: 9:14:44 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=700201
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SPIRALLEVELORDERTRAVERSAL_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SPIRALLEVELORDERTRAVERSAL_H_

struct node {
    int data;
    struct node* left;
    struct node* right;
};

//Tested
void printSpiral(struct node *root) {
    stack<node *> levelAuxspace;
    stack<node *> reversedLevelAuxspace;
    levelAuxspace.push(root);
    node *currentNode;
    while (!levelAuxspace.empty() || !reversedLevelAuxspace.empty()) {
        while (!levelAuxspace.empty()) {
            currentNode = levelAuxspace.top();
            levelAuxspace.pop();
            printf("%d ", currentNode->data);
            if (currentNode->right != null) {
                reversedLevelAuxspace.push(currentNode->right);
            }
            if (currentNode->left != null) {
                reversedLevelAuxspace.push(currentNode->left);
            }
        }
        while (!reversedLevelAuxspace.empty()) {
            currentNode = reversedLevelAuxspace.top();
            reversedLevelAuxspace.pop();
            printf("%d ", currentNode->data);
            if (currentNode->left != null) {
                levelAuxspace.push(currentNode->left);
            }
            if (currentNode->right != null) {
                levelAuxspace.push(currentNode->right);
            }
        }
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SPIRALLEVELORDERTRAVERSAL_H_ */
