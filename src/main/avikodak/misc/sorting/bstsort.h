/****************************************************************************************************************************************************
 *  File Name   		: bstsort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\misc\sorting\bstsort.h
 *  Created on			: Dec 11, 2014 :: 1:01:27 PM
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef BSTSORT_H_
#define BSTSORT_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void bsInsertIntoBST(iftNode **root,iftNode *currentNode,vector<int> userInput,int currentIndex){
	if(currentIndex >= userInput.size()){
		return;
	}
	if(*root == null){
		(*root) = new iftNode(userInput[currentIndex]);
		bsInsertIntoBST(root,*root,userInput,currentIndex+1);
	}else if(currentNode->value == userInput[currentIndex]){
		currentNode->frequency += 1;
		bsInsertIntoBST(root,*root,userInput,currentIndex+1);
	}else if(currentNode->value > userInput[currentIndex]){
		if(currentNode->left == null){
			currentNode->left = new iftNode(userInput[currentIndex]);
			bsInsertIntoBST(root,*root,userInput,currentIndex+1);
		}else{
			bsInsertIntoBST(root,currentNode->left,userInput,currentIndex);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new iftNode(userInput[currentIndex]);
			bsInsertIntoBST(root,*root,userInput,currentIndex+1);
		}else{
			bsInsertIntoBST(root,currentNode->right,userInput,currentIndex);
		}
	}
}

void bsSetVectorWithInorderValues(iftNode *ptr,vector<int> &userInput){
	if(ptr == null){
		return;
	}
	static int fillCounter = -1;
	bsSetVectorWithInorderValues(ptr->left,userInput);
	while(ptr->frequency--){
		userInput[++fillCounter] = ptr->value;
	}
	bsSetVectorWithInorderValues(ptr->right,userInput);
}

void bstSort(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	iftNode *root = null;
	bsInsertIntoBST(&root,root,userInput,0);
	bsSetVectorWithInorderValues(root,userInput);
}

#endif /* BSTSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
