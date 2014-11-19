/****************************************************************************************************************************************************
 *  File Name   		: constructcompletetreefromsill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\constructcompletetreefromsill.h
 *  Created on			: Nov 13, 2014 :: 1:05:02 PM
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

#ifndef CONSTRUCTCOMPLETETREEFROMSILL_H_
#define CONSTRUCTCOMPLETETREEFROMSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *constructTreeFromSill(sillNode *head){
	if(head == null){
		return null;
	}
	itNode *root = new itNode(head->value);
	sillNode *crawler = head->next;
	queue<itNode *> auxSpace;
	auxSpace.push(root);
	itNode *currentNode;
	while(crawler != null){
		currentNode = auxSpace.front();
		auxSpace.pop();
		if(currentNode->left == null){
			currentNode->left = new itNode(crawler->value);
			auxSpace.push(currentNode->left);
		}else{
			currentNode->right = new itNode(crawler->value);
			auxSpace.push(currentNode->right);
			auxSpace.pop();
		}
		crawler = crawler->next;
	}
}

itNode *constructTreeFromSillHashmap(sillNode *head){
	if(head == null){
		return null;
	}
	hash_map<unsigned int,int> indexValueMap;
	unsigned int counter = 0;
	sillNode *crawler = head;
	while(crawler != null){
		indexValueMap.insert(pair<unsigned int,int>(counter++,crawler->value));
		crawler = crawler->next;
	}
	treeutils *utils = new treeutils();
	return utils->getITreeFromHashmap(indexValueMap);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void insertValueIntoTree(itNode **root,int value){
	if(*root == null){
		(*root) = new itNode(value);
		return;
	}
	queue<itNode *> auxSpace;
	auxSpace.push(*root);
	itNode *currentNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}else{
			currentNode->left = new itNode(value);
			return;
		}
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}else{
			currentNode->right = new itNode(value);
			return;
		}
	}
}

itNode *constructCompleteTreeON2(sillNode *head){
	if(head == null){
		return null;
	}
	itNode *root = null;
	sillNode *crawler = head;
	while(crawler != null){
		insertValueIntoTree(&root,crawler->value);
		crawler = crawler->next;
	}
	return root;
}

#endif /* CONSTRUCTCOMPLETETREEFROMSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
