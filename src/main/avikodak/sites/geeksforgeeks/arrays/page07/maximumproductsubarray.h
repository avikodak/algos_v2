/****************************************************************************************************************************************************
 *  File Name   		: maximumproductsubarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\maximumproductsubarray.h
 *  Created on			: Jan 2, 2015 :: 12:33:38 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/maximum-product-subarray/
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

#ifndef MAXIMUMPRODUCTSUBARRAY_H_
#define MAXIMUMPRODUCTSUBARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maximumProductSubarray(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	int negativeProduct = 1,positiveProduct = 1,maxProduct = INT_MIN,temp;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] > 0){
			positiveProduct *= userInput[counter];
			negativeProduct = min(1,negativeProduct * userInput[counter]);
		}else if(userInput[counter] == 0){
			negativeProduct = 1;
			positiveProduct = 1;
		}else if(userInput[counter] < 0){
			temp = maxProduct;
			maxProduct = max(1,negativeProduct * userInput[counter]);
			negativeProduct = min(negativeProduct,temp * userInput[counter]);
		}
		maxProduct = max(maxProduct,positiveProduct);
	}
	return maxProduct;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maxProductSubArrayON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	int maxProduct = INT_MIN,currentProduct;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		currentProduct = 1;
		for(unsigned int innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
			currentProduct *= userInput[innerCounter];
			maxProduct = max(maxProduct,currentProduct);
		}
	}
	return maxProduct;
}

#endif /* MAXIMUMPRODUCTSUBARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
