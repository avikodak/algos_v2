/****************************************************************************************************************************************************
 *  File Name   		: equilibriumindex.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\careercup\amazon\equilibriumindex.h
 *  Created on			: Jan 20, 2015 :: 2:17:09 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.careercup.com/question?id=5680651472732160
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

#ifndef EQUILIBRIUMINDEX_H_
#define EQUILIBRIUMINDEX_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int getEquilibriumIndex(vector<int> userInput){
	if(userInput.size() < 2){
		return userInput.size();
	}
	int sum = 0,lSum = 0,rSum = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		sum += userInput[counter];
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		rSum = sum  - lSum - userInput[counter];
		if(lSum == rSum){
			return counter;
		}
		lSum += userInput[counter];
	}
	return INT_MIN;
}

#endif /* EQUILIBRIUMINDEX_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
