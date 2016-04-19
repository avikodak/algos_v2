/****************************************************************************************************************************************************
 *  File Name                   : zerooneknapsack.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\zerooneknapsack.h
 *  Created on                  : Dec 9, 2014 :: 8:02:23 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef ZEROONEKNAPSACK_H_
#define ZEROONEKNAPSACK_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int zeroOneKnapsack(vector<int> weights,vector<int> benefits,int maxWeight) {
    if(weights.size() == 0) {
        return INT_MIN;
    }
    vector<vector<int> > auxSpace(weights.size());
    for(unsigned int counter = 0; counter < auxSpace.size(); counter++) {
        auxSpace.resize(maxWeight+1);
    }
    for(unsigned int rowCounter = 0; rowCounter < auxSpace.size(); rowCounter++) {
        auxSpace[rowCounter][0] = 0;
    }
    for(unsigned int columnCounter = 0; columnCounter < auxSpace.size(); columnCounter++) {
        auxSpace[0][columnCounter] = 0;
    }
    for(unsigned int rowCounter = 1; rowCounter < auxSpace.size(); rowCounter++) {
        for(unsigned int columnCounter = 1; columnCounter < auxSpace[0].size(); columnCounter++) {
            auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter-1][columnCounter];
            if(weights[rowCounter] <= columnCounter) {
                auxSpace[rowCounter][columnCounter] = max(auxSpace[rowCounter][columnCounter],benefits[rowCounter] + auxSpace[rowCounter-1][columnCounter - weights[rowCounter]]);
            }
        }
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(2^N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int zeroOneKnapsackO2N(vector<int> weights,vector<int> benefits,int maxWeight,int currentIndex) {
    if(maxWeight < 0) {
        return INT_MIN;
    }
    if(maxWeight == 0 || currentIndex == weights.size()) {
        return 0;
    }
    return max(zeroOneKnapsackO2N(weights,benefits,maxWeight,currentIndex+1),benefits[currentIndex] + zeroOneKnapsackO2N(weights,benefits,maxWeight-weights[currentIndex],currentIndex+1));
}

int zeroOneKnapGenerateSets(vector<int> weights,vector<int> benefits,int maxWeights) {
    if(weights.size() < 2) {
        return weights.size();
    }
    int limit = pow(2,weights.size());
    int maxBenefit = INT_MIN,itemsWeight,itemsBenefits;
    for(unsigned int counter = 0; counter < limit; counter++) {
        itemsBenefits = 0;
        itemsWeight = 0;
        for(unsigned int itemCounter = 0; itemCounter < weights.size(); itemCounter++) {
            if(counter & 1 << itemCounter) {
                itemsBenefits += benefits[itemCounter];
                itemsWeight += weights[itemCounter];
            }
        }
        if(itemsWeight <= maxWeights) {
            maxBenefit = max(maxBenefit,itemsBenefits);
        }
    }
    return maxBenefit;
}

#endif /* ZEROONEKNAPSACK_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
