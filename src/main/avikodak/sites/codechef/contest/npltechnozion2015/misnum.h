/****************************************************************************************************************************************************
 *  File Name                   : misnum.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/contest/npltechnozion2015/misnum.h
 *  Created on                  : 19-Oct-2015 :: 6:16:23 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/NPLTZ15/problems/MISNUM
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
#include <stdint.h>
#include <iomanip>
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

#ifndef MISNUM_H_
#define MISNUM_H_

//Tested
vector<long long int> generatePrimeNumberSquarMap(long long int limit) {
    vector<bool> flags;
    flags.assign(limit+2,true);
    vector<long long int> primeNumberMap;
    for(long long int counter = 2; counter <= limit; counter++) {
        if(flags[counter]) {
            long long int innerCounter = 2;
            while(counter*innerCounter <= limit) {
                flags[counter*innerCounter] = false;
                innerCounter+=1;
            }
        }
    }
    for(long long int counter = 2; counter <= limit; counter++) {
        if(flags[counter]) {
            primeNumberMap.push_back(counter*counter);
        }
    }
    return primeNumberMap;
}

//Tested
void printResults() {
    vector<long long int> primeNumberSquareMap = generatePrimeNumberSquarMap(sqrt(1000000001));
    vector<long long int>::iterator itToUpper,itToPrimeNumberSquareMap;
    long long int testCases,min,max,sum;
    scanf("%lld",&testCases);
    while(testCases--) {
        scanf("%lld %lld",&min,&max);
        sum = 0;
        itToUpper = upper_bound(primeNumberSquareMap.begin(),primeNumberSquareMap.end(),min-1);
        for(itToPrimeNumberSquareMap = itToUpper; itToPrimeNumberSquareMap != primeNumberSquareMap.end(); itToPrimeNumberSquareMap++) {
            if(*itToPrimeNumberSquareMap > max) {
                break;
            }
            sum++;
        }
        cout << sum << endl;
    }
}

#endif /* MISNUM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
