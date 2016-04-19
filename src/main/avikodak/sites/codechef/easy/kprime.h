/****************************************************************************************************************************************************
 *  File Name                   : kprime.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\kprime.h
 *  Created on                  : Sep 4, 2015 :: 9:49:35 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/KPRIME
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
#define LIMIT 100001

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef KPRIME_H_
#define KPRIME_H_

vector<vector<unsigned int> > initialize() {
    unsigned int factorsCount[LIMIT] = {0};
    unsigned int innerCounter;
    for(unsigned int outerCounter = 2; outerCounter < LIMIT; outerCounter++) {
        innerCounter = 2*outerCounter;
        if(factorsCount[outerCounter] == 0) {
            factorsCount[outerCounter] = 1;
            while(innerCounter < LIMIT) {
                factorsCount[innerCounter]++;
                innerCounter += outerCounter;
            }
        }
    }
    vector<vector<unsigned int> > factorsMapCount(7);
    for(unsigned int counter = 0; counter < 7; counter++) {
        factorsMapCount[counter].assign(LIMIT,0);
    }
    for(unsigned int outerCounter = 1; outerCounter < 7; outerCounter++) {
        for(unsigned int innerCounter = 2; innerCounter < LIMIT; innerCounter++) {
            factorsMapCount[outerCounter][innerCounter] = factorsMapCount[outerCounter][innerCounter-1] + (factorsCount[innerCounter]==outerCounter?1:0);
        }
    }
    return factorsMapCount;
}

void printResults() {
    vector<vector<unsigned int> > factorsMapCount = initialize();
    unsigned int testCases;
    unsigned int A,B,N;
    scanf("%u",&testCases);
    while(testCases--) {
        cin >> A >> B >> N;
        cout << factorsMapCount[N][B] - factorsMapCount[N][A-1] << endl;
    }
}

#endif /* KPRIME_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
