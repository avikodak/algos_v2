/****************************************************************************************************************************************************
 *  File Name   		: treefrompreinorder.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page08\treefrompreinorder.h
 *  Created on			: Oct 18, 2014 :: 2:10:25 PM
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

#ifndef TREEFROMPREINORDER_H_
#define TREEFROMPREINORDER_H_

itNode *getTreeFromPreInorder(vector<int> preOrder,vector<int> inOrder,unsigned int startPreOrderIndex,unsigned int endPreOrderIndex,unsigned int startInOrderIndex,unsigned int endInOrderIndex){
	if(startPreOrderIndex > endPreOrderIndex || startInOrderIndex > endInOrderIndex){
		return null;
	}
	itNode *node = new itNode(preOrder[startPreOrderIndex]);
	unsigned int counter = startInOrderIndex;
	while(counter <= endInOrderIndex && inOrder[counter] != preOrder[startPreOrderIndex]){
		counter++;
	}
	if(counter > endInOrderIndex){
		throw "Invalid sequence";
	}
	unsigned int difference = counter - startInOrderIndex;
	node->left =  getTreeFromPreInorder(preOrder,inOrder,startPreOrderIndex+1,startPreOrderIndex+counter,startInOrderIndex,startInOrderIndex+counter-1);
	node->right =  getTreeFromPreInorder(preOrder,inOrder,startPreOrderIndex+1+counter,endPreOrderIndex,startInOrderIndex+counter+1,endInOrderIndex);
	return node;
}

#endif /* TREEFROMPREINORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
