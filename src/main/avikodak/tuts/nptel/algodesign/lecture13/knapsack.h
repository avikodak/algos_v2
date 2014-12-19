/****************************************************************************************************************************************************
 *  File Name   		: knapsack.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture13\knapsack.h
 *  Created on			: Dec 17, 2014 :: 9:11:23 AM
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
#include "../lecture12/fractionalknapsack.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef KNAPSACK_H_
#define KNAPSACK_H_

int zeroOneKnapSackBruteForce(vector<int> weights,vector<int> benefits,int maxWeight,int currentIndex){
	if(currentIndex > weights.size()){
		return INT_MIN;
	}
	if(currentIndex == weights.size()){
		return 0;
	}
	if(weights[currentIndex] > maxWeight){
		return zeroOneKnapSackBruteForce(weights,benefits,maxWeight,currentIndex+1);
	}else{
		return max(zeroOneKnapSackBruteForce(weights,benefits,maxWeight,currentIndex+1),benefits[currentIndex] + zeroOneKnapSackBruteForce(weights,benefits,maxWeight - weights[currentIndex],currentIndex+1));
	}
}

int zeroOneKnapSackBranchAndBoundMain(vector<int> weights,vector<int> benefits,int rejectedValue,int maxWeight,int currentIndex){
	static int minRejectedValue = INT_MAX;
	if(currentIndex > weights.size()){
		return INT_MIN;
	}
	if(currentIndex == weights.size()){
		minRejectedValue = min(minRejectedValue,rejectedValue);
		return 0;
	}
	if(weights[currentIndex] >= maxWeight){
		if(rejectedValue + benefits[currentIndex] < minRejectedValue){
			return zeroOneKnapSackBranchAndBoundMain(weights,benefits,rejectedValue + benefits[currentIndex],maxWeight,currentIndex+1);
		}
	}else{
		int minValue = INT_MAX;
		minValue = min(minValue,benefits[currentIndex] + zeroOneKnapSackBranchAndBoundMain(weights,benefits,rejectedValue,maxWeight - weights[currentIndex],currentIndex+1));
		if(rejectedValue + benefits[currentIndex] < minRejectedValue){
			minValue = min(minValue,zeroOneKnapSackBranchAndBoundMain(weights,benefits,benefits[currentIndex] + rejectedValue,maxWeight,currentIndex+1));
		}
		return minValue;
	}
}

int zeroOneKnapSackBranchAndBound(vector<int> weights,vector<int> benefits,int maxWeight){
	if(weights.size() == 0){
		return INT_MIN;
	}
	quickSortWeightsAndBenefits(weights,benefits,0,weights.size()-1);
	return zeroOneKnapSackBranchAndBoundMain(weights,benefits,0,maxWeight,0);
}

#endif /* KNAPSACK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
