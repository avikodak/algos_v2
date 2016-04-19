/****************************************************************************************************************************************************
 *  File Name                   : jeryfibo.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/jeryfibo.h
 *  Created on                  : 17-Oct-2015 :: 7:46:13 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/JERYFIBO
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

#ifndef JERYFIBO_H_
#define JERYFIBO_H_

//Tested
vector<long long int> init() {
    vector<long long int> fibonacciNumbers;
    long long int currentTerm = 1,prevTerm = 1,nextTerm;
    fibonacciNumbers.push_back(1);
    while(currentTerm+prevTerm < 1000000001) {
        nextTerm = currentTerm + prevTerm;
        prevTerm = currentTerm;
        currentTerm = nextTerm;
        fibonacciNumbers.push_back(currentTerm);
    }
    return fibonacciNumbers;
}

//Tested
void printResults() {
    unsigned int testCases;
    long long int userInput;
    vector<long long int> fibonacciNumbers = init();
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%lld",&userInput);
        printf("%s\n",binary_search(fibonacciNumbers.begin(),fibonacciNumbers.end(),userInput)?"is fibo":"not fibo");
    }
}

#endif /* JERYFIBO_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
