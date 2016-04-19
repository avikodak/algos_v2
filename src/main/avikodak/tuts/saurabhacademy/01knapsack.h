/****************************************************************************************************************************************************
 *  File Name   		: 01knapsack.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\01knapsack.h
 *  Created on			: Oct 28, 2014 :: 7:32:20 PM
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef KNAPSACK01_H_
#define KNAPSACK01_H_

//Tested
int knapsackProblem(vector<int> weights,vector<int> benefits,int maxWeight,unsigned int currentIndex = 0) {
    if(currentIndex > weights.size()) {
        return INT_MIN;
    }
    if(currentIndex == weights.size()) {
        return 0;
    }
    return max(knapsackProblem(weights,benefits,maxWeight,currentIndex+1),weights[currentIndex] > maxWeight?INT_MIN:benefits[currentIndex] + knapsackProblem(weights,benefits,maxWeight-weights[currentIndex],currentIndex+1));
}

//Tested
int knapsackProblemMemoization(vector<int> weights,vector<int> benefits,unsigned int maxWeight) {
    if(weights.size() == 0) {
        return INT_MIN;
    }
    vector<vector<int> > auxSpace(weights.size());
    for(unsigned int rowCounter = 0; rowCounter < weights.size(); rowCounter++) {
        auxSpace[rowCounter].resize(maxWeight+1);
        auxSpace[rowCounter][0] = 0;
    }
    for(unsigned int columnCounter = 0; columnCounter <= maxWeight; columnCounter++) {
        auxSpace[0][columnCounter] = 0;
    }
    for(unsigned int rowCounter = 1; rowCounter < weights.size(); rowCounter++) {
        for(unsigned int columnCounter = 1; columnCounter <= maxWeight; columnCounter++) {
            auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter-1][columnCounter];
            if(weights[rowCounter-1] <= (int)columnCounter ) {
                auxSpace[rowCounter][columnCounter] = max(auxSpace[rowCounter][columnCounter],benefits[rowCounter-1] + auxSpace[rowCounter-1][columnCounter-weights[rowCounter-1]]);
            }
        }
    }
    return auxSpace[auxSpace.size()-1][maxWeight];
}

//Tested
int knapsackProblemO2NMain(vector<int> weights,vector<int> benefits,unsigned int maxWeight,vector<int> subset,unsigned int currentIndex = 0) {
    if(currentIndex > weights.size()) {
        return INT_MIN;
    }
    if(currentIndex == weights.size()) {
        unsigned int sumWeight = 0;
        int sumBenefit = 0;
        for(unsigned int counter = 0; counter < subset.size(); counter++) {
            sumWeight += weights[subset[counter]];
            sumBenefit += benefits[subset[counter]];
        }
        return sumWeight == maxWeight?sumBenefit:INT_MIN;
    }
    int result = knapsackProblemO2NMain(weights,benefits,maxWeight,subset,currentIndex+1);
    subset.push_back(currentIndex);
    return max(result,knapsackProblemO2NMain(weights,benefits,maxWeight,subset,currentIndex+1));
}

//Tested
int knapsackProblemO2N(vector<int> weights,vector<int> benefits,unsigned int maxWeight) {
    if(weights.size() == 0) {
        return INT_MIN;
    }
    vector<int> subset;
    return knapsackProblemO2NMain(weights,benefits,maxWeight,subset);
}

//Tested
int knapsackProblemO2NIterative(vector<int> weight,vector<int> benefits,unsigned int maxWeight) {
    if(weight.size() == 0) {
        return INT_MIN;
    }
    unsigned int sumWeight;
    int sumBenefits;
    int maxBenefit = INT_MIN;
    for(unsigned int outerCounter = 0; outerCounter < pow(2,weight.size()); outerCounter++) {
        sumWeight = 0;
        sumBenefits = 0;
        for(unsigned int innerCounter = 0; innerCounter < weight.size(); innerCounter++) {
            if(outerCounter & 1 << innerCounter) {
                sumWeight += weight[innerCounter];
                sumBenefits += benefits[innerCounter];
            }
        }
        if(sumWeight <= maxWeight) {
            maxBenefit = max(maxBenefit,sumBenefits);
        }
    }
    return maxBenefit;
}

#endif /* 01KNAPSACK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
