/****************************************************************************************************************************************************
 *  File Name   		: specificlevelorder.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page01\specificlevelorder.h
 *  Created on			: Jan 22, 2015 :: 7:44:11 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal/
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

#ifndef SPECIFICLEVELORDER_H_
#define SPECIFICLEVELORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void perfectTreeSpecificLevelOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	itNode *firstNode,*secondNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		firstNode = auxSpace.front();
		auxSpace.pop();
		printf("%d\t",firstNode->value);
		if(!auxSpace.empty()){
			secondNode = auxSpace.front();
			auxSpace.pop();
			printf("%d\t",secondNode->value);
		}else{
			secondNode = null;
		}
		if(firstNode->left != null){
			auxSpace.push(firstNode->left);
		}
		if(secondNode != null && secondNode->right != null){
			auxSpace.push(secondNode->right);
		}
		if(firstNode->right != null){
			auxSpace.push(firstNode->right);
		}
		if(secondNode != null && secondNode->left != null){
			auxSpace.push(secondNode->left);
		}
	}
}

#endif /* SPECIFICLEVELORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
