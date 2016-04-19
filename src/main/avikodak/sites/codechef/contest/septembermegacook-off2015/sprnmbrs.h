/****************************************************************************************************************************************************
 *  File Name                   : sprnmbrs.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/contest/septembermegacook-off2015/sprnmbrs.h
 *  Created on                  : 20-Sep-2015 :: 10:35:36 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/COOK62/problems/SPRNMBRS
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
#define gc getchar_unlocked

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef SPRNMBRS_H_
#define SPRNMBRS_H_

//Tested
void scanllint(long long int &x) {
    register int c = gc();
    x = 0;
    for(; (c<48 || c>57); c = gc());
    for(; c>47 && c<58; c = gc()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
}

//Tested
void scanuint(unsigned int &x) {
    register int c = gc();
    x = 0;
    for(; (c<48 || c>57); c = gc());
    for(; c>47 && c<58; c = gc()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
}

//Tested
vector<long long int> init() {
    long long int product;
    long long int limit = 1000000000000000000;
    vector<long long int> twoPowers;
    vector<long long int> twoThreePowers;
    product = 2;
    while(product <= limit) {
        twoPowers.push_back(product);
        product *= 2;
    }
    for(unsigned int counter = 0; counter < twoPowers.size() && twoPowers[counter] <= limit; counter++) {
        product = 3;
        for(long long int innerCounter = 1; twoPowers[counter]*product <= limit; innerCounter++) {
            twoThreePowers.push_back(twoPowers[counter]*product);
            product *= 3;
        }
    }
    for(unsigned int counter = 0; counter < twoThreePowers.size(); counter++) {
        twoPowers.push_back(twoThreePowers[counter]);
    }
    twoPowers.push_back(1);
    sort(twoPowers.begin(),twoPowers.end());
    return twoPowers;
}

//Tested
void printResults() {
    unsigned int testCases,total;
    long long int minValue,maxValue;
    vector<long long int> totientFlagMap = init();
    vector<long long int>::iterator itToMin,itToMax;
    scanuint(testCases);
    while(testCases--) {
        scanllint(minValue);
        scanllint(maxValue);
        total=0;
        for(unsigned int counter = 0; counter < totientFlagMap.size(); counter++) {
            if(totientFlagMap[counter]>= minValue && totientFlagMap[counter] <= maxValue) {
                total++;
            }
        }
        cout << total << endl;
    }
}

#endif /* SPRNMBRS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
