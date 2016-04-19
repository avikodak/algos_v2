/****************************************************************************************************************************************************
 *  File Name                   : subgcd.h
 *  File Location               : /home/avikodak/eclipse_ws/algos/algos/src/main/avikodak/sites/codechef/easy/subgcd.h
 *  Created on                  : 08-Sep-2015 :: 10:20:39 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SUBGCD
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

#ifndef SUBGCD_H_
#define SUBGCD_H_

//Tested
unsigned int gcd(unsigned int a,unsigned int b) {
    return b == 0?a:gcd(b,a%b);
}

//Tested
void printsubgcd(vector<unsigned int> userInput) {
    unsigned int result = userInput[0];
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        result = gcd(result,userInput[counter]);
    }
    if(result == 1) {
        printf("%lu\n",userInput.size());
    } else {
        printf("-1\n");
    }
}

//Tested
void printResults() {
    unsigned int testCases,size,input;
    vector<unsigned int> userInput;
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%u",&size);
        userInput.clear();
        while(size--) {
            scanf("%u",&input);
            userInput.push_back(input);
        }
        printsubgcd(userInput);
    }
}


#endif /* SUBGCD_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
