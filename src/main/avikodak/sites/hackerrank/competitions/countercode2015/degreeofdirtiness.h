/****************************************************************************************************************************************************
 *  File Name                   : degreeofdirtiness.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\competitions\countercode2015\degreeofdirtiness.h
 *  Created on                  : Aug 2, 2015 :: 7:31:31 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested but Timeout
 *  URL                         : https://www.hackerrank.com/contests/countercode/challenges/degree-of-dirtiness
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

#ifndef DEGREEOFDIRTINESS_H_
#define DEGREEOFDIRTINESS_H_

//Tested
unsigned int getLeastDirtyLeftToRight(vector<unsigned int> dirtiness) {
    unsigned int minIndex = 0;
    for(unsigned int counter = 1; counter < dirtiness.size(); counter++) {
        if(dirtiness[minIndex] > dirtiness[counter]) {
            minIndex = counter;
        }
    }
    return minIndex;
}

//Tested
int getLeastDirtyRightToLeft(vector<unsigned int> dirtiness,int minIndexLTR) {
    int minIndex = dirtiness.size()-1;
    for(int counter = dirtiness.size()-2; counter >= 0; counter--) {
        if(counter != minIndexLTR && dirtiness[minIndex] > dirtiness[counter]) {
            minIndex = counter;
        }
    }
    return minIndex;
}

//Tested
void printIndexAndDirtiness(unsigned int total,unsigned int personIndex) {
    vector<unsigned int> dirtiness;
    dirtiness.assign(total,0);
    unsigned int minIndexLTR;
    int minIndexRTL;
    for(unsigned int counter = 1; counter <= personIndex; counter += 2) {
        minIndexLTR = getLeastDirtyLeftToRight(dirtiness);
        if(counter == personIndex) {
            cout << minIndexLTR+1 << " " << dirtiness[minIndexLTR] << endl;
            return;
        }
        dirtiness[minIndexLTR]++;
        minIndexRTL = getLeastDirtyRightToLeft(dirtiness,minIndexLTR);
        if(counter+1 == personIndex) {
            cout << minIndexRTL+1 << " " << dirtiness[minIndexRTL] << endl;
            return;
        }
        dirtiness[minIndexRTL]++;
    }
}

//Tested
void getIndexAndDirtiness() {
    unsigned int testCases,total,personIndex;
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%u %u",&total,&personIndex);
        printIndexAndDirtiness(total,personIndex);
    }
}

#endif /* DEGREEOFDIRTINESS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
