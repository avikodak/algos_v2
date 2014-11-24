/****************************************************************************************************************************************************
 *  File Name   		: iterativepostordertwostacks.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page05\iterativepostordertwostacks.h
 *  Created on			: Nov 2, 2014 :: 5:18:00 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/iterative-postorder-traversal/
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

#ifndef ITERATIVEPOSTORDERTWOSTACKS_H_
#define ITERATIVEPOSTORDERTWOSTACKS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void iterativePostOrderIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	primaryAuxspace.push(ptr);
	itNode *currentNode;
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentNode);
		if(currentNode->left != null){
			primaryAuxspace.push(currentNode->left);
		}
		if(currentNode->right != null){
			primaryAuxspace.push(currentNode->right);
		}
	}
	while(!secondaryAuxspace.empty()){
		printf("%d\t",secondaryAuxspace.top()->value);
		secondaryAuxspace.pop();
	}
}

#endif /* ITERATIVEPOSTORDERTWOSTACKS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
