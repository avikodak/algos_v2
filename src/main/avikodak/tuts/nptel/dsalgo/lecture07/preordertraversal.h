/****************************************************************************************************************************************************
 *  File Name   		: preordertraversal.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture07\preordertraversal.h
 *  Created on			: Nov 17, 2014 :: 11:06:58 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PREORDERTRAVERSAL_H_
#define PREORDERTRAVERSAL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void preOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	printf("%d\t",ptr->value);
	preOrderTraversal(ptr->left);
	preOrderTraversal(ptr->right);
}

//Tested
void preOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		printf("%d\t",currentNode->value);
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}
	}
}

//Tested
void morrisPreorderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *currentNode = ptr,*temp;
	while(currentNode != null){
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = currentNode;
				printf("%d\t",currentNode->value);
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				currentNode = currentNode->right;
			}
		}else{
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

#endif /* PREORDERTRAVERSAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
