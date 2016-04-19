/****************************************************************************************************************************************************
 *  File Name   		: iloveusername.h
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\iloveusername.h
 *  Created on			: Mar 8, 2015 :: 12:12:33 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/155/A
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef ILOVEUSERNAME_H_
#define ILOVEUSERNAME_H_

//Tested
void getNumberOfAmazingPerformance() {
    unsigned int testCases;
    int points,maxTillNow = INT_MIN,minTillNow = INT_MAX,noOfAmazingPerformance = 0;
    scanf("%d",&testCases);
    for(unsigned int counter = 0; counter < testCases; counter++) {
        scanf("%d",&points);
        if(counter != 0) {
            if(maxTillNow < points) {
                noOfAmazingPerformance++;
                maxTillNow = points;
            } else if(minTillNow > points) {
                noOfAmazingPerformance++;
                minTillNow = points;
            }
        } else {
            maxTillNow = points;
            minTillNow = points;
        }
    }
    printf("%d",noOfAmazingPerformance);
}

#endif /* ILOVEUSERNAME_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
