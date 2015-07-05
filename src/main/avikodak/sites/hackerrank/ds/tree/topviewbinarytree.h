/****************************************************************************************************************************************************
 *  File Name                   : topviewbinarytree.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\tree\topviewbinarytree.h
 *  Created on                  : Jul 5, 2015 :: 6:16:23 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/tree-top-view
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef TOPVIEWBINARYTREE_H_
#define TOPVIEWBINARYTREE_H_

//Tested
void top_view(node *root,bool isLeftChild){
	if(root == NULL){
		return;
	}
	if(isLeftChild){
		top_view(root->left,true);
        printf("%d ",root->data);
	}
	if(!isLeftChild){
        printf("%d ",root->data);
		top_view(root->right,false);
	}
}

//Tested
void top_view(node *root){
	if(root == NULL){
		return;
	}
	top_view(root->left,true);
	printf("%d ",root->data);
	top_view(root->right,false);
}

#endif /* TOPVIEWBINARYTREE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
