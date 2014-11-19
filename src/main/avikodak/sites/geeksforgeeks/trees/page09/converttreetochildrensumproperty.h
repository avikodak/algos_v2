/****************************************************************************************************************************************************
 *  File Name   		: converttreetochildrensumproperty.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page09\converttreetochildrensumproperty.h
 *  Created on			: Oct 16, 2014 :: 1:48:16 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/
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

#ifndef CONVERTTREETOCHILDRENSUMPROPERTY_H_
#define CONVERTTREETOCHILDRENSUMPROPERTY_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void incrementValueInSubTree(itNode *ptr,int value){
	if(ptr == null){
		return;
	}
	ptr->value += value;
	if(ptr->left != null){
		incrementValueInSubTree(ptr->left,value);
	}else{
		incrementValueInSubTree(ptr->right,value);
	}
}

//Tested
int convertTreeToChildrenSumProperty(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	if(ptr->left == null && ptr->right == null){
		return ptr->value;
	}
	int leftSum = convertTreeToChildrenSumProperty(ptr->left);
	int rightSum = convertTreeToChildrenSumProperty(ptr->right);
	int sumOfChildren = leftSum + rightSum;
	if(ptr->value < sumOfChildren){
		ptr->value += (sumOfChildren - ptr->value);
	}else if(ptr->value > sumOfChildren){
		if(ptr->left != null){
			incrementValueInSubTree(ptr->left,ptr->value - sumOfChildren);
		}else{
			incrementValueInSubTree(ptr->right,ptr->value - sumOfChildren);
		}
	}
	return ptr->value;
}

#endif /* CONVERTTREETOCHILDRENSUMPROPERTY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
