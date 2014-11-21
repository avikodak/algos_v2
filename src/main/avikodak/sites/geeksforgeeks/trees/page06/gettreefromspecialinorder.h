/****************************************************************************************************************************************************
 *  File Name   		: gettreefromspecialinorder.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\gettreefromspecialinorder.h
 *  Created on			: Oct 23, 2014 :: 6:42:52 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/construct-binary-tree-from-inorder-traversal/
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

#ifndef GETTREEFROMSPECIALINORDER_H_
#define GETTREEFROMSPECIALINORDER_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int getMaxIndexValue(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	unsigned int maxIndex = startIndex;
	for(int counter = startIndex;counter <= endIndex;counter++){
		if(userInput[maxIndex] < userInput[counter]){
			maxIndex = counter;
		}
	}
	return maxIndex;
}

//Tested
itNode *getTreeFromSpecialInOrderMain(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return null;
	}
	unsigned int maxIndex = getMaxIndexValue(userInput,startIndex,endIndex);
	itNode *node = new itNode(userInput[maxIndex]);
	node->left = getTreeFromSpecialInOrderMain(userInput,startIndex,maxIndex-1);
	node->right = getTreeFromSpecialInOrderMain(userInput,maxIndex+1,endIndex);
	return node;
}

//Tested
itNode *getTreeFromSpecialInorder(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	return getTreeFromSpecialInOrderMain(userInput,0,userInput.size()-1);
}

#endif /* GETTREEFROMSPECIALINORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
