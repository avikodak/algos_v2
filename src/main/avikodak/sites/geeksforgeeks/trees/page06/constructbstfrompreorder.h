/****************************************************************************************************************************************************
 *  File Name   		: constructbstfrompreorder.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\constructbstfrompreorder.h
 *  Created on			: Nov 13, 2014 :: 10:47:11 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
 *  					  http://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversal-set-2/
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

#ifndef CONSTRUCTBSTFROMPREORDER_H_
#define CONSTRUCTBSTFROMPREORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *constructBSTFromPreOrderON(vector<int> userInput,int minValue = INT_MIN,int maxValue = INT_MAX){
	static unsigned int counter = 0;
	if(counter >= userInput.size()){
		return null;
	}
	int value = userInput[counter];
	if(value < minValue || value > maxValue){
		return null;
	}
	itNode *node = new itNode(value);
	counter++;
	node->left = constructBSTFromPreOrderON(userInput,minValue,value);
	node->right = constructBSTFromPreOrderON(userInput,value,maxValue);
	return node;
}

//Tested
itNode *constructBSTFromPreorderIterative(vector<int> userInput){
	if(userInput.size() ==0){
		return null;
	}
	stack<itNode *> auxSpace;
	itNode *root = new itNode(userInput[0]);
	auxSpace.push(root);
	itNode *temp;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		temp = null;
		while(!auxSpace.empty() && userInput[counter] > auxSpace.top()->value){
			temp = auxSpace.top();
			auxSpace.pop();
		}
		if(temp != null){
			temp->right = new itNode(userInput[counter]);
			auxSpace.push(temp->right);
		}else{
			auxSpace.top()->left = new itNode(userInput[counter]);
			auxSpace.push(auxSpace.top()->left);
		}
	}
	return root;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *constructBSTFromPreOrderON2(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return null;
	}
	itNode *node = new itNode(userInput[startIndex]);
	int counter = startIndex+1;
	while(userInput[startIndex] > userInput[counter] && counter <= endIndex){
		counter++;
	}
	node->left = constructBSTFromPreOrderON2(userInput,startIndex+1,counter-1);
	node->right = constructBSTFromPreOrderON2(userInput,counter,endIndex);
	return node;
}

#endif /* CONSTRUCTBSTFROMPREORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
