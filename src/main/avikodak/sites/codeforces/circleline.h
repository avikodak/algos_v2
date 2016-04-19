/****************************************************************************************************************************************************
 *  File Name                   : circleline.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\circleline.h
 *  Created on                  : Apr 13, 2015 :: 12:50:05 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/278/A
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

#ifndef CIRCLELINE_H_
#define CIRCLELINE_H_

//Tested
void printMinDistance() {
    unsigned int stationsCount,userInput,source,destination;
    scanf("%u",&stationsCount);
    vector<int> distances;
    unsigned int totalDistance = 0;
    while(stationsCount--) {
        scanf("%u",&userInput);
        distances.push_back(userInput);
        totalDistance += userInput;
    }
    scanf("%u %u",&source,&destination);
    if(source > destination) {
        swap(source,destination);
    }
    unsigned int calculatedDistance = 0;
    for(unsigned int counter = source-1; counter < destination; counter++) {
        calculatedDistance += distances[counter];
    }
    printf("%u",min(calculatedDistance,totalDistance-calculatedDistance));
}

#endif /* CIRCLELINE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
