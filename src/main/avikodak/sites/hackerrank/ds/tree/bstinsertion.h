/****************************************************************************************************************************************************
 *  File Name                   : bstinsertion.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\tree\bstinsertion.h
 *  Created on                  : Jul 6, 2015 :: 9:07:05 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.hackerrank.com/challenges/binary-search-tree-insertion
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

#ifndef BSTINSERTION_H_
#define BSTINSERTION_H_

/*struct node{
   int data;
   node * left;
   node * right;
};*/

//Tested
node * insert(node *root, int value){
	node *crawler = root;
	if(root == null){
		root = new node();
		root->data = value;
		root->left = null;
		root->right = null;
		return root;
	}
	while(crawler != null){
		if(crawler->data >= value){
			if(crawler->left == null){
				crawler->left = new node();
				crawler->left->data = value;
				crawler->left->left = null;
				crawler->left->right = null;
				break;
			}else{
				crawler = crawler->left;
			}
		}else{
			if(crawler->right == null){
				crawler->right = new node();
				crawler->right->data = value;
				crawler->right->left = null;
				crawler->right->right = null;
                break;
			}else{
				crawler = crawler->right;
			}
		}
	}
	return root;
}

#endif /* BSTINSERTION_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
