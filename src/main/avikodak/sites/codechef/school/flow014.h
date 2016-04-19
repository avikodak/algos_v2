/****************************************************************************************************************************************************
 *  File Name                   : flow014.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\school\flow014.h
 *  Created on                  : Aug 30, 2015 :: 2:59:05 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/FLOW014
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

#ifndef FLOW014_H_
#define FLOW014_H_

//Tested
void printGradeOfSteel(double hardness,double carbonContent,double tensileStrength) {
    bool hardnessFlag = hardness > 50;
    bool carbonFlag = carbonContent < 0.7;
    bool tensileFlag = tensileStrength > 5600;
    if(hardnessFlag && carbonFlag && tensileFlag) {
        printf("10\n");
    } else if(hardnessFlag && carbonFlag) {
        printf("9\n");
    } else if(carbonFlag && tensileFlag) {
        printf("8\n");
    } else if(hardnessFlag && tensileFlag) {
        printf("7\n");
    } else if(hardnessFlag || carbonFlag || tensileFlag) {
        printf("6\n");
    } else {
        printf("5\n");
    }

}

//Tested
void printResults() {
    unsigned int testCases;
    scanf("%u",&testCases);
    double hardness,carbonContent,tensileStrength;
    while(testCases--) {
        cin >> hardness >> carbonContent >> tensileStrength;
        printGradeOfSteel(hardness,carbonContent,tensileStrength);
    }
}

#endif /* FLOW014_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
