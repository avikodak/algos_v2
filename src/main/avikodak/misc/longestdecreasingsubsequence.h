/****************************************************************************************************************************************************
 *  File Name   		: longestdecreasingsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\misc\longestdecreasingsubsequence.h
 *  Created on			: Nov 29, 2014 :: 10:16:42 AM
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

#ifndef LONGESTDECREASINGSUBSEQUENCE_H_
#define LONGESTDECREASINGSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int longestDecreasingSequence(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	vector<int> lengths;
	lengths.push_back(1);
	int maxLength;
	for(unsigned int  outerCounter = 1;outerCounter < userInput.size();outerCounter++){
		maxLength = 1;
		for(unsigned int innerCounter = 0;innerCounter < outerCounter;innerCounter++){
			if(userInput[innerCounter] > userInput[outerCounter]){
				maxLength = max(maxLength,1 + lengths[innerCounter]);
			}
		}
		lengths.push_back(maxLength);
	}
	return lengths[lengths.size()-1];
}

int longestDecreasingSubSequence(vector<int> userInput,int currentIndex = 0){
	if(currentIndex >= userInput.size()){
		return INT_MAX;
	}
	if(userInput.size() == 0){
		return 0;
	}
	if(currentIndex == 1){
		return 1;
	}
	int maxLength = 1;
	for(int counter = currentIndex - 1;counter >= 0;counter--){
		if(userInput[counter] > userInput[currentIndex]){
			maxLength = max(maxLength,longestDecreasingSubSequence(userInput,counter));
		}
	}
	return maxLength;
}


#endif /* LONGESTDECREASINGSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
