/****************************************************************************************************************************************************
 *  File Name   		: lowestancestorstree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page02\lowestancestorstree.h
 *  Created on			: Nov 15, 2014 :: 7:08:02 PM
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

#ifndef LOWESTANCESTORSTREE_H_
#define LOWESTANCESTORSTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool lowestAncestor(itNode *ptr,itNode **lowAncestor,int firstUserinput,int secondUserinput){
	if(ptr == null){
		return false;
	}
	if(ptr->value == firstUserinput || ptr->value == secondUserinput){
		return true;
	}
	bool leftTruthValue = lowestAncestor(ptr->left,lowAncestor,firstUserinput,secondUserinput);
	bool rightTruthValue = lowestAncestor(ptr->right,lowAncestor,firstUserinput,secondUserinput);
	if(leftTruthValue && rightTruthValue){
		if(*lowAncestor == null){
			(*lowAncestor) = ptr;
		}
		return false;
	}
	return leftTruthValue || rightTruthValue;
}

void lowestAncestorMain(itNode *ptr,stack<itNode *> auxSpace,stack<itNode *> &firstValAncestors,stack<itNode *> &secondValAncestors,int firstVal,int secondVal){
	if(ptr == null){
		return;
	}
	if(ptr->value == firstVal || ptr->value == secondVal){
		return;
	}
	lowestAncestorMain(ptr->left,auxSpace,firstValAncestors,secondValAncestors,firstVal,secondVal);
	lowestAncestorMain(ptr->right,auxSpace,firstValAncestors,secondValAncestors,firstVal,secondVal);
}

itNode *lowestAncestorsAuxspace(itNode *ptr,int firstVal,int secondVal){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace,firstValAncestors,secondValAncestors;
	lowestAncestorMain(ptr,auxSpace,firstValAncestors,secondValAncestors,firstVal,secondVal);
	if(firstValAncestors.size() != secondValAncestors.size()){
		if(firstValAncestors.size() > secondValAncestors.size()){
			while(firstValAncestors.size() != secondValAncestors.size()){
				firstValAncestors.pop();
			}
		}else{
			while(firstValAncestors.size() != secondValAncestors.size()){
				secondValAncestors.pop();
			}
		}
	}
	itNode *commonAncestors = null;
	while(firstValAncestors.size() > 0){
		if(firstValAncestors.top() == secondValAncestors.top()){
			return firstValAncestors.top();
		}
		firstValAncestors.pop();
		secondValAncestors.pop();
	}
	return commonAncestors;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* LOWESTANCESTORSTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
