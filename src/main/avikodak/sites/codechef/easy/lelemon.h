/****************************************************************************************************************************************************
 *  File Name                   : lelemon.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/lelemon.h
 *  Created on                  : 29-Oct-2015 :: 8:20:17 am
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/LELEMON
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

#ifndef LELEMON_H_
#define LELEMON_H_

void printResults() {
    long long int testCases,noOfRooms,noOfVisitedRooms,totalVolume,input,bottlesInRoom;
    vector<long int> visitedRooms;
    scanf("%lld",&testCases);
    while(testCases--) {
        scanf("%lld %lld",&noOfRooms,&noOfVisitedRooms);
        vector<priority_queue<long int> > roomDrinkInfo(noOfRooms);
        totalVolume = 0;
        for(long long int counter = 0; counter < noOfVisitedRooms; counter++) {
            scanf("%lld",&input);
            visitedRooms.push_back(input);
        }
        for(long long counter = 0; counter < noOfRooms; counter++) {
            scanf("%lld",&bottlesInRoom);
            while(bottlesInRoom--) {
                scanf("%lld",&input);
                roomDrinkInfo[counter].push(noOfRooms);
            }
        }
        for(long long int counter = 0; counter < noOfVisitedRooms; counter++) {
            totalVolume += roomDrinkInfo[visitedRooms[counter]].top();
            roomDrinkInfo[visitedRooms[counter]].pop();
        }
        printf("%lld\n",totalVolume);
    }
}


#endif /* LELEMON_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
