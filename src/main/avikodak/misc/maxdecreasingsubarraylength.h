/****************************************************************************************************************************************************
 *  File Name   		: maxdecreasingsubarraylength.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\misc\maxdecreasingsubarraylength.h
 *  Created on			: Nov 28, 2014 :: 12:41:52 PM
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

#ifndef MAXDECREASINGSUBARRAYLENGTH_H_
#define MAXDECREASINGSUBARRAYLENGTH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int maxDecreasingSubArrayLength(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	vector<int> lengths;
	lengths.push_back(1);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(userInput[counter] < userInput[counter-1]){
			lengths.push_back(lengths[counter-1] + 1);
		}else{
			lengths.push_back(1);
		}
	}
	return lengths;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isVectorSortedDescending(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex || endIndex >= userInput.size()){
		return false;
	}
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(userInput[counter] > userInput[counter-1]){
			return false;
		}
	}
	return true;
}

#endif /* MAXDECREASINGSUBARRAYLENGTH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
