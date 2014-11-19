/****************************************************************************************************************************************************
 *  File Name   		: constructcompletetree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\constructcompletetree.h
 *  Created on			: Nov 13, 2014 :: 12:21:42 PM
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

#ifndef CONSTRUCTCOMPLETETREE_H_
#define CONSTRUCTCOMPLETETREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *constructCompleteTree(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	queue<itNode *> auxSpace;
	itNode *root = new itNode(userInput[0]);
	auxSpace.push(root);
	itNode *currentNode;
	unsigned int counter = 1;
	while(counter < userInput.size()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		if(currentNode->left == null){
			currentNode->left = new itNode(userInput[counter++]);
			auxSpace.push(currentNode->left);
		}else{
			currentNode->right = new itNode(userInput[counter++]);
			auxSpace.push(currentNode->right);
			auxSpace.pop();
		}
	}
	return root;
}

itNode *constructCompleteTree(vector<int> userInput,unsigned int counter = 0){
	if(counter >= userInput.size()){
		return null;
	}
	itNode *node = new itNode(userInput[counter]);
	node->left = constructCompleteTree(userInput,2*counter+1);
	node->right = constructCompleteTree(userInput,2*counter+2);
	return node;
}

void constructCompleteTreeV2Main(itNode **ptr,vector<int> userInput,unsigned int counter = 0){
	if(counter >= userInput.size()){
		return;
	}
	(*ptr) = new itNode(userInput[counter]);
	constructCompleteTreeV2Main(&((*ptr)->left),2*counter+1);
	constructCompleteTreeV2Main((&(*ptr)->right),2*counter+2);
}

itNode *constructCompleteTreeV2(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	itNode *root = null;
	return constructCompleteTreeV2Main(&root,userInput);
}

itNode *constructCompleteTreeUsingHashmap(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	hash_map<unsigned int,int> indexValuemap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		indexValuemap.insert(pair<unsigned int,int>(counter,userInput[counter]));
	}
	treeutils *utils = new treeutils();
	return utils->getITreeFromHashmap(indexValuemap);
}

#endif /* CONSTRUCTCOMPLETETREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
