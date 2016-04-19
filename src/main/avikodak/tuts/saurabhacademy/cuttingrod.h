/****************************************************************************************************************************************************
 *  File Name                   : cuttingrod.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\saurabhacademy\cuttingrod.h
 *  Created on                  : Oct 24, 2014 :: 8:52:41 PM
 *  Author                      : AVINASH
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef CUTTINGROD_H_
#define CUTTINGROD_H_

//Tested
int cuttingRod(map<unsigned int,int> &lengthBenefitMap,unsigned int lengthOfRod) {
    if(lengthOfRod <= 0) {
        return 0;
    }
    int maxBenefit = 0;
    map<unsigned int,int>::iterator itToLengthBenefitMap;
    for(itToLengthBenefitMap = lengthBenefitMap.begin(); itToLengthBenefitMap != lengthBenefitMap.end(); itToLengthBenefitMap++) {
        if(lengthOfRod >= itToLengthBenefitMap->first) {
            maxBenefit = max(maxBenefit,itToLengthBenefitMap->second + cuttingRod(lengthBenefitMap,lengthOfRod - itToLengthBenefitMap->first));
        }
    }
    return maxBenefit;
}

int cuttingRodBottomUp(map<unsigned int,int> lengthBenefitMap,unsigned int lengthOfRod) {
    return 0;
}

//Tested
int cuttingRodMemoization(map<unsigned int,int> lengthBenefitMap,unsigned int lengthOfRod) {
    if(lengthOfRod <= 0) {
        return 0;
    }
    int maxBenefit = 0;
    static map<unsigned int,int> optimizedLengthBenefitMap;
    map<unsigned int,int>::iterator itToLengthBenefitMap,itToOptimizedLengthBenefitMap;
    for(itToLengthBenefitMap = lengthBenefitMap.begin(); itToLengthBenefitMap != lengthBenefitMap.end(); itToLengthBenefitMap++) {
        if(lengthOfRod >= itToLengthBenefitMap->first) {
            if((itToOptimizedLengthBenefitMap = optimizedLengthBenefitMap.find((unsigned int)(lengthOfRod - itToLengthBenefitMap->first))) == optimizedLengthBenefitMap.end()) {
                maxBenefit = max(maxBenefit,itToLengthBenefitMap->second + cuttingRodMemoization(lengthBenefitMap,lengthOfRod - itToLengthBenefitMap->first));
            } else {
                maxBenefit = max(maxBenefit,itToOptimizedLengthBenefitMap->second);
            }
        }
    }
    optimizedLengthBenefitMap.insert(pair<unsigned int,int>(lengthOfRod,maxBenefit));
    return maxBenefit;
}

#endif /* CUTTINGROD_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
