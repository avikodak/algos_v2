/****************************************************************************************************************************************************
 *  File Name   		: maxincreasingsubarraylength.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\misc\maxincreasingsubarraylength.h
 *  Created on			: Nov 28, 2014 :: 12:35:58 PM
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

#ifndef MAXINCREASINGSUBARRAYLENGTH_H_
#define MAXINCREASINGSUBARRAYLENGTH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int maxIncreasingSubarrayLength(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	vector<int> increasingSubarrayLength;
	increasingSubarrayLength.push_back(1);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(userInput[counter] > userInput[counter-1]){
			increasingSubarrayLength.push_back(increasingSubarrayLength[counter-1]+1);
		}else{
			increasingSubarrayLength.push_back(1);
		}
	}
	return max_element(increasingSubarrayLength.begin(),increasingSubarrayLength.end());
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isVectorSortedAscending(vector<int> userInput){
	if(userInput.size() == 0){
		return true;
	}
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(userInput[counter] < userInput[counter-1]){
			return false;
		}
	}
	return true;
}


#endif /* MAXINCREASINGSUBARRAYLENGTH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
