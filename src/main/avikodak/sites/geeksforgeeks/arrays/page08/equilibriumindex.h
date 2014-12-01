/****************************************************************************************************************************************************
 *  File Name   		: equilibriumindex.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\equilibriumindex.h
 *  Created on			: Nov 26, 2014 :: 5:31:48 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/equilibrium-index-of-an-array/
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

#ifndef EQUILIBRIUMINDEX_H_
#define EQUILIBRIUMINDEX_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int getEquilibriumIndex(vector<int> userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	vector<int> leftSums(userInput.size()),rightSums(userInput.size());
	leftSums[0] = 0;
	rightSums[userInput.size()-1] = 0;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		leftSums[counter] = userInput[counter-1] + leftSums[counter-1];
	}
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		rightSums[counter] = rightSums[counter+1] + userInput[counter+1];
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(leftSums[counter] == rightSums[counter]){
			return counter;
		}
	}
	return UINT_MAX;
}

//Tested
unsigned int getEquilibriumIndexSpaceOptimized(vector<int> userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	vector<int> leftSum;
	leftSum.push_back(0);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		leftSum.push_back(leftSum[counter-1]+userInput[counter-1]);
	}
	int rightSum = 0;
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		rightSum += userInput[counter+1];
		if(leftSum[counter] == rightSum){
			return counter;
		}
	}
	return UINT_MAX;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int getEquilibriumIndexON2(vector<int> userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	int leftSum,rightSum;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		leftSum = rightSum = 0;
		for(unsigned int leftCounter = 0;leftCounter < outerCounter;leftCounter++){
			leftSum += userInput[leftCounter];
		}
		for(unsigned int rightCounter = outerCounter+1;rightCounter < userInput.size();rightCounter++){
			rightSum += userInput[rightCounter];
		}
		if(leftSum == rightSum){
			return outerCounter;
		}
	}
	return UINT_MAX;
}

#endif /* EQUILIBRIUMINDEX_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
