/****************************************************************************************************************************************************
 *  File Name   		: fractionalknapsack.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture12\fractionalknapsack.h
 *  Created on			: Dec 16, 2014 :: 6:07:05 PM
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

#ifndef FRACTIONALKNAPSACK_H_
#define FRACTIONALKNAPSACK_H_

int quickSortDivideStep(vector<int> &weights,vector<int> &benefits,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int pivotIndex = endIndex;
	float key = (weights[pivotIndex]/(float)benefits[pivotIndex]);
	while(startIndex < endIndex){
		while((weights[startIndex]/(float)benefits[startIndex]) < key){
			startIndex++;
		}
		while(startIndex < endIndex && (weights[endIndex]/(float)benefits[endIndex]) >= key){
			endIndex--;
		}
		if(startIndex < endIndex){
			swap(weights[pivotIndex],weights[endIndex]);
			swap(benefits[pivotIndex],benefits[endIndex]);
		}
	}
	swap(weights[pivotIndex],weights[endIndex]);
	swap(benefits[pivotIndex],benefits[endIndex]);
	return endIndex;
}

void quickSortWeightsAndBenefits(vector<int> &weights,vector<int> &benefits,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int dividingIndex = quickSortDivideStep(weights,benefits,startIndex,endIndex);
	quickSortWeightsAndBenefits(weights,benefits,startIndex,dividingIndex-1);
	quickSortWeightsAndBenefits(weights,benefits,dividingIndex+1,endIndex);
}

float fractionalKnapsack(vector<int> weights,vector<int> benefits,int maxWeight){
	if(weights.size() == 0){
		return 0.0;
	}
	quickSortWeightsAndBenefits(weights,benefits,0,weights.size()-1);
	float maxBenefit = 0;
	for(unsigned int counter = 0;counter < weights.size();counter++){
		if(weights[counter] <= maxWeight){
			maxBenefit += benefits[counter];
			maxWeight -= weights[counter];
		}else{
			maxBenefit += (benefits[counter] /(float)weights[counter])*maxWeight;
			break;
		}
	}
	return maxBenefit;
}

#endif /* FRACTIONALKNAPSACK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/