/****************************************************************************************************************************************************
 *  File Name   		: bstsort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture09\bstsort.h
 *  Created on			: Nov 18, 2014 :: 2:49:11 PM
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

#ifndef BSTSORT_H_
#define BSTSORT_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void getBstFromVectorMain(itNode **root,itNode *currentNode,vector<int> userInput,unsigned int counter){
	if(counter >= userInput.size()){
		return;
	}
	if(*root == null){
		(*root) = new itNode(userInput[counter]);
		getBstFromVectorMain(root,*root,userInput,counter+1);
	}else{
		if(currentNode->value == userInput[counter]){
			getBstFromVectorMain(root,*root,userInput,counter+1);
		}else if(currentNode->value > userInput[counter]){
			if(currentNode->left == null){
				currentNode->left = new itNode(userInput[counter]);
				getBstFromVectorMain(root,*root,userInput,counter+1);
			}else{
				getBstFromVectorMain(root,currentNode->left,userInput,counter);
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new itNode(userInput[counter]);
				getBstFromVectorMain(root,*root,userInput,counter+1);
			}else{
				getBstFromVectorMain(root,currentNode->right,userInput,counter);
			}
		}
	}
}

//Tested
void setVectorWithInorderValues(itNode *ptr,vector<int> &userInput){
	if(ptr == null){
		return;
	}
	static unsigned int index = 0;
	setVectorWithInorderValues(ptr->left,userInput);
	userInput[index++] = ptr->value;
	setVectorWithInorderValues(ptr->right,userInput);
}

//Tested
void bstSort(vector<int> &userInput){
	if(userInput.size() <= 1){
		return;
	}
	itNode *rootBST = null;
	getBstFromVectorMain(&rootBST,rootBST,userInput,0);
	setVectorWithInorderValues(rootBST,userInput);
}

//Tested
vector<int> getVectorWithInorderIterative(itNode *ptr){
	vector<int> inorderValues;
	if(ptr == null){
		return inorderValues;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			inorderValues.push_back(currentNode->value);
			currentNode = currentNode->right;
		}
	}
	return inorderValues;
}

//Tested
vector<int> getVectorWithInorderValuesMorrisInorder(itNode *ptr){
	vector<int> inorderValues;
	if(ptr == null){
		return inorderValues;
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
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				inorderValues.push_back(currentNode->value);
				currentNode = currentNode->right;
			}
		}else{
			inorderValues.push_back(currentNode->value);
			currentNode = currentNode->right;
		}
	}
	return inorderValues;
}


#endif /* BSTSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
