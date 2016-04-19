/****************************************************************************************************************************************************
 *  File Name                   : dragnxor.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\dragnxor.h
 *  Created on                  : Sep 4, 2015 :: 10:18:46 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/DRAGNXOR
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef DRAGNXOR_H_
#define DRAGNXOR_H_

//Tested
vector<long long int> generatePowersOf2() {
    vector<long long int> powersOf2;
    long long int result = 1;
    for(long long int counter = 0; counter < 30; counter++) {
        powersOf2.push_back(result);
        result *= 2;
    }
    return powersOf2;
}

//Tested
long long int countSetBits(long long int userInput) {
    long long int totalSetBits = 0;
    while(userInput) {
        totalSetBits += userInput%2;
        userInput /= 2;
    }
    return totalSetBits;
}

//Tested
void printResults() {
    vector<long long int> powersOf2 = generatePowersOf2();
    long long int testCases,nValue,firstInput,secondInput,result;
    long long int firstSetBitCount,secondSetBitCount,firstClearBitCount,secondClearBitCount,totalSetBitCount;
    scanf("%lld",&testCases);
    while(testCases--) {
        scanf("%lld %lld %lld",&nValue,&firstInput,&secondInput);
        firstSetBitCount = countSetBits(firstInput);
        secondSetBitCount = countSetBits(secondInput);
        firstClearBitCount = nValue - firstSetBitCount;
        secondClearBitCount = nValue - secondSetBitCount;
        totalSetBitCount = min(firstSetBitCount,secondClearBitCount) + min(secondSetBitCount,firstClearBitCount);
        result = 0;
        while(totalSetBitCount--) {
            result += powersOf2[nValue-1];
            nValue--;
        }
        printf("%lld\n",result);
    }
}

#endif /* DRAGNXOR_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
