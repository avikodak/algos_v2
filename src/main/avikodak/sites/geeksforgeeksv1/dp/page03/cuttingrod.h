/****************************************************************************************************************************************************
 *  File Name                   : cuttingrod.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\cuttingrod.h
 *  Created on                  : Dec 9, 2014 :: 8:02:41 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/
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

#ifndef CUTTINGROD_H_
#define CUTTINGROD_H_

//Tested
int maxBenefitRodCuttingMemoization(vector<int> cuts,vector<int> benefits,int length) {
    if(length == 0 || cuts.size() == 0) {
        return 0;
    }
    vector<int> maxBenefits(length+1,0);
    for(int counter = 1; counter <= length; counter++) {
        for(unsigned int cutCounter = 0; cutCounter < cuts.size(); cutCounter++) {
            if(counter >= cuts[cutCounter]) {
                maxBenefits[counter] = max(maxBenefits[counter] ,benefits[cutCounter] + maxBenefits[counter - cuts[cutCounter]]);
            }
        }
    }
    return maxBenefits[maxBenefits.size()-1];
}

//Tested
int maxCuttingRodBenefit(vector<int> cuts,vector<int> benefits,int length) {
    if(length <= 0) {
        return 0;
    }
    int maxBenefit = INT_MIN;
    for(unsigned int counter = 0; counter < cuts.size(); counter++) {
        if(cuts[counter] <= length) {
            maxBenefit = max(maxBenefit,benefits[counter] + maxCuttingRodBenefit(cuts,benefits,length-cuts[counter]));
        }
    }
    return maxBenefit;
}

#endif /* CUTTINGROD_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
