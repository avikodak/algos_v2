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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>
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
