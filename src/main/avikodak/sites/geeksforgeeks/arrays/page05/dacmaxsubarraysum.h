/****************************************************************************************************************************************************
 *  File Name   		: dacmaxsubarraysum.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\dacmaxsubarraysum.h
 *  Created on			: Dec 25, 2014 :: 12:20:17 PM
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

#ifndef DACMAXSUBARRAYSUM_H_
#define DACMAXSUBARRAYSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int maxCrossOverSum(vector<int> userInput,int startIndex,int middleIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int leftSum = INT_MIN,sum = 0,rightSum = INT_MIN;
	for(int counter = middleIndex;counter >= startIndex;counter--){
		sum += userInput[counter];
		leftSum = max(leftSum,sum);
	}
	for(unsigned int counter = middleIndex+1;counter <= endIndex;counter++){
		sum += userInput[counter];
		rightSum = max(rightSum,sum);
	}
	return leftSum + rightSum;
}

int dacMaxSubArraySum(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		return userInput[startIndex];
	}
	int middleIndex = (startIndex + endIndex)/2;
	return max(dacMaxSubArraySum(userInput,startIndex,middleIndex),max(dacMaxSubArraySum(userInput,middleIndex+1,endIndex),maxCrossOverSum(userInput,startIndex,middleIndex,endIndex)));
}

#endif /* DACMAXSUBARRAYSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
