/****************************************************************************************************************************************************
 *  File Name   		: twonodesfixbst.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\twonodesfixbst.h
 *  Created on			: Nov 13, 2014 :: 10:24:20 AM
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

#ifndef TWONODESFIXBST_H_
#define TWONODESFIXBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void fixNodesInInorderMain(itNode *ptr,itNode **firstPtr,itNode **midPtr,itNode **lastPtr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	fixNodesInInorderMain(ptr->left,firstPtr,midPtr,lastPtr);
	if(prevNode != null){
		if(ptr->value < prevNode->value){
			if(*firstPtr == null){
				(*firstPtr) = prevNode;
				(*midPtr) = ptr;
			}else{
				(*lastPtr) = ptr;
			}
		}
	}
	prevNode = ptr;
	fixNodesInInorderMain(ptr->right,firstPtr,midPtr,lastPtr);
}

//Tested
void fixNodesInInOrderON(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *firstPtr = null,*midPtr = null,*lastPtr = null;
	fixNodesInInorderMain(ptr,&firstPtr,&midPtr,&lastPtr);
	int temp;
	if(lastPtr != null){
		temp = lastPtr->value;
		lastPtr->value = firstPtr->value;
		firstPtr->value = temp;
	}else{
		temp = midPtr->value;
		midPtr->value = firstPtr->value;
		firstPtr->value = temp;
	}
}


/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void insertNodesInInorder(itNode *ptr,vector<int> inorderValues){
	if(ptr == null){
		return;
	}
	static unsigned int counter = 0;
	insertNodesInInorder(ptr->left,inorderValues);
	ptr->value = inorderValues[counter++];
	insertNodesInInorder(ptr->right,inorderValues);
}

//Tested
void fixBST(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	vector<int> inorderValues = utils->getValuesInInorder(ptr);
	sort(inorderValues.begin(),inorderValues.end());
	insertNodesInInorder(ptr,inorderValues);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* TWONODESFIXBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
