/****************************************************************************************************************************************************
 *  File Name                   : hotel.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\hotel.h
 *  Created on                  : Sep 1, 2015 :: 1:10:02 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/HOTEL
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

#ifndef HOTEL_H_
#define HOTEL_H_

//Tested
void printResults() {
    unsigned int testCases,arrival,departure,size,maxGuests;
    scanf("%u",&testCases);
    vector<unsigned int> guestsCount,arrivalTimes,departureTimes;
    while(testCases--) {
        scanf("%u",&size);
        arrivalTimes.clear();
        departureTimes.clear();
        for(unsigned int counter = 0; counter < size; counter++) {
            scanf("%u",&arrival);
            arrivalTimes.push_back(arrival);
        }
        for(unsigned int counter = 0; counter < size; counter++) {
            scanf("%u",&departure);
            departureTimes.push_back(departure);
        }
        guestsCount.clear();
        guestsCount.assign(1001,0);
        maxGuests = 0;
        for(unsigned int counter = 0; counter < arrivalTimes.size(); counter++) {
            for(unsigned int timeCounter = arrivalTimes[counter]; timeCounter < departureTimes[counter]; timeCounter++) {
                guestsCount[timeCounter]++;
                maxGuests = max(maxGuests,guestsCount[timeCounter]);
            }
        }
        printf("%u\n",maxGuests);
    }
}

#endif /* HOTEL_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
