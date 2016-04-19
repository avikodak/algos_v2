/****************************************************************************************************************************************************
 *  File Name                   : dbyz15a.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/dbyz15a.h
 *  Created on                  : 16-Oct-2015 :: 9:23:51 am
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/DBYZ15A
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

#ifndef DBYZ15A_H_
#define DBYZ15A_H_

long long int gcd(long long int a,long long int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b,a%b);
}

long long int lcm(long long int a,long long int b) {
    return (a*b)/(gcd(a,b));
}

void printResults() {
    long long int nValue,input,totalPairs = 0;
    vector<long long int> userInput;
    scanf("%lld",&nValue);
    for(long long int counter = 0; counter < nValue; counter++) {
        scanf("%lld",&input);
        userInput.push_back(input);
    }
    for(unsigned int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        for(unsigned int innerCounter = outerCounter+1; innerCounter < userInput.size(); innerCounter++) {
            if(lcm(userInput[outerCounter],userInput[innerCounter]) > min(userInput[outerCounter],userInput[innerCounter])) {
                totalPairs++;
            }
        }
    }
    printf("%lld",totalPairs);
}

#endif /* DBYZ15A_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
