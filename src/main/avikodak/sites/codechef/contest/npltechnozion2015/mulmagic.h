/****************************************************************************************************************************************************
 *  File Name                   : mulmagic.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/contest/npltechnozion2015/mulmagic.h
 *  Created on                  : 19-Oct-2015 :: 5:54:04 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/NPLTZ15/problems/MULMAGIC
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

#ifndef MULMAGIC_H_
#define MULMAGIC_H_

//Tested
void printResults() {
    unsigned int testCases,size;
    scanf("%u",&testCases);
    long long int sum,maxSum;
    long long int userInput[100001];
    while(testCases--) {
        scanf("%u",&size);
        for(unsigned int counter = 1; counter <= size; counter++) {
            scanf("%lld",&userInput[counter]);
        }
        sum = 0;
        maxSum = 0;
        for(unsigned int outerCounter = 2; outerCounter <= size; outerCounter++) {
            sum = 0;
            for(unsigned int innerCounter = 1; outerCounter*innerCounter <= size; innerCounter++) {
                sum += userInput[outerCounter*innerCounter];
            }
            maxSum = max(maxSum,sum);
        }
        printf("%lld\n",maxSum);
    }
}

#endif /* MULMAGIC_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
