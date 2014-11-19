/****************************************************************************************************************************************************
 *  File Name   		: printmergedbsts.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\printmergedbsts.h
 *  Created on			: Nov 1, 2014 :: 11:09:17 AM
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

#ifndef PRINTMERGEDBSTS_H_
#define PRINTMERGEDBSTS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
//Revise
void printMergedBSTSInSortedOrder(itNode *firstTreePtr,itNode *secondTreePtr){
	treeutils *utils = new treeutils();
	if(firstTreePtr == null || secondTreePtr == null){
		if(firstTreePtr != null){
			utils->inOrderTraversal(firstTreePtr);
		}else{
			utils->inOrderTraversal(secondTreePtr);
		}
		return;
	}
	stack<itNode *> firstTreeAuxspace,secondTreeAuxspace;
	itNode *currentNodeFirstTree = firstTreePtr,*currentNodeSecondTree = secondTreePtr;
	while((!firstTreeAuxspace.empty() || currentNodeFirstTree != null) || (!secondTreeAuxspace.empty() || currentNodeSecondTree != null)){
		if(currentNodeFirstTree != null || currentNodeSecondTree != null){
			if(currentNodeFirstTree != null){
				firstTreeAuxspace.push(currentNodeFirstTree);
				currentNodeFirstTree = currentNodeFirstTree->left;
			}
			if(currentNodeSecondTree != null){
				secondTreeAuxspace.push(currentNodeSecondTree);
				currentNodeSecondTree = currentNodeSecondTree->left;
			}
		}else{
			if(secondTreeAuxspace.empty()){
				while(!firstTreeAuxspace.empty()){
					currentNodeFirstTree = firstTreeAuxspace.top();
					firstTreeAuxspace.pop();
					currentNodeFirstTree->left = null;
					utils->inOrderTraversal(currentNodeFirstTree);
				}
				return;
			}
			if(firstTreeAuxspace.empty()){
				while(!secondTreeAuxspace.empty()){
					currentNodeSecondTree = secondTreeAuxspace.top();
					secondTreeAuxspace.pop();
					currentNodeSecondTree->left = null;
					utils->inOrderTraversal(currentNodeSecondTree);
				}
				return;
			}
			if(firstTreeAuxspace.top()->value <= secondTreeAuxspace.top()->value){
				currentNodeFirstTree = firstTreeAuxspace.top();
				firstTreeAuxspace.pop();
				printf("%d\t",currentNodeFirstTree->value);
				currentNodeFirstTree = currentNodeFirstTree->right;
			}else{
				currentNodeSecondTree = secondTreeAuxspace.top();
				secondTreeAuxspace.pop();
				printf("%d\t",currentNodeSecondTree->value);
				currentNodeSecondTree = currentNodeSecondTree->right;
			}
		}
	}
}

#endif /* PRINTMERGEDBSTS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
