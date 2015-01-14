/****************************************************************************************************************************************************
 *  File Name   		: largestindependentsetproblem.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page02\largestindependentsetproblem.h
 *  Created on			: Jan 12, 2015 :: 4:54:53 PM
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

#ifndef LARGESTINDEPENDENTSETPROBLEM_H_
#define LARGESTINDEPENDENTSETPROBLEM_H_

int largestIndependentSetProblem(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	if(ptr->left == null && ptr->right == null){
		return 1;
	}
	int maxExcludingElement = largestIndependentSetProblem(ptr->left) + largestIndependentSetProblem(ptr->right);
	int maxIncludingElement = 1 + (ptr->left != null?largestIndependentSetProblem(ptr->left->left) + largestIndependentSetProblem(ptr->left->right):0) + (ptr->right != null?largestIndependentSetProblem(ptr->right->left) + largestIndependentSetProblem(ptr->right->right):0);
	return max(maxExcludingElement,maxIncludingElement);
}


#endif /* LARGESTINDEPENDENTSETPROBLEM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/