/****************************************************************************************************************************************************
 *  File Name                   : awsgame1.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\awsgame1.h
 *  Created on                  : Sep 5, 2015 :: 9:34:01 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/AMSGAME1
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

#ifndef AWSGAME1_H_
#define AWSGAME1_H_

//Tested
long long int gcd(long long int first,long long int second) {
    if(second == 0) {
        return first;
    }
    return gcd(second,first%second);
}

//Tested
void printGCD(vector<long long int> userInput) {
    if(userInput.size() == 1) {
        printf("%lld\n",userInput[0]);
        return;
    }
    long long int result = gcd(userInput[0],userInput[1]);
    for(unsigned int counter = 2; counter < userInput.size(); counter++) {
        result = gcd(result,userInput[counter]);
    }
    cout << result << endl;
}

//Tested
void printResults() {
    unsigned int testCases,size;
    long long int input;
    vector<long long int> userInput;
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%u",&size);
        userInput.clear();
        for(unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld",&input);
            userInput.push_back(input);
        }
        printGCD(userInput);
    }
}

#endif /* AWSGAME1_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
