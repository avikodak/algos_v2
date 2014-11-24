/****************************************************************************************************************************************************
 *  File Name   		: reverselevelordertraversal.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\reverselevelordertraversal.h
 *  Created on			: Nov 21, 2014 :: 9:23:44 PM
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

#ifndef REVERSELEVELORDERTRAVERSAL_H_
#define REVERSELEVELORDERTRAVERSAL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void rPrintReverseLevelOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	auxSpace.push(ptr);
	itNode *currentNode;
	stack<itNode *> reverseAuxspace;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		reverseAuxspace.push(currentNode);
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
		}
	}
	while(!reverseAuxspace.empty()){
		printf("%d\t",reverseAuxspace.top()->value);
		reverseAuxspace.pop();
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printReverseLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return;
	}
	if(level == 0){
		printf("%d\t",ptr->value);
		return;
	}
	printReverseLevel(ptr->right,level-1);
	printReverseLevel(ptr->left,level-1);
}

//Tested
void printReverseLevelOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	int height = utils->getHeightOfTree(ptr);
	for(int counter = height-1;counter >= 0;counter--){
		printReverseLevel(ptr,counter);
	}
}

#endif /* REVERSELEVELORDERTRAVERSAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
