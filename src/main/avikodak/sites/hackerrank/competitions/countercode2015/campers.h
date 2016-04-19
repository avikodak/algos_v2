/****************************************************************************************************************************************************
 *  File Name                   : campers.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\competitions\countercode2015\campers.h
 *  Created on                  : Aug 2, 2015 :: 12:16:03 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.hackerrank.com/contests/countercode/challenges/campers
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

#ifndef CAMPERS_H_
#define CAMPERS_H_

void getMaxNumberPlayers() {
    unsigned int totalPlayers,snipersCount,sniperIndex;
    cin >> totalPlayers >> snipersCount;
    vector<int> flags[totalPlayers] = {0};
    while(snipersCount--) {
        cin >> sniperIndex;
        sniperIndex -= 1;
        flags[sniperIndex] = 1;
        if(sniperIndex-1 >= 0) {
            flags[sniperIndex] = -1;
        }
        if(sniperIndex+1 < totalPlayers) {
            flags[sniperIndex] = -1;
        }
    }
    bool neighboursChosen;
    unsigned int maxPlayerCount = 0;
    for(unsigned int counter = 0; counter < totalPlayers; counter++) {
        if(flags[counter] == 1) {
            maxPlayerCount++;
            continue;
        }
        if(counter-1 >= 0) {
            if(flags[counter-1] != 1) {
                continue;
            }
        }
        if(counter+1 < totalPlayers) {
            if(flags[counter+1] !=0) {
                continue;
            }
        }
        flags[counter] = 1;
        maxPlayerCount++;
        if(counter-1 >= 0) {
            flags[counter-1] = -1;
        }
        if(counter+1 < totalPlayers) {
            flags[counter+1] = -1;
        }
    }
    cout << maxPlayerCount << endl;
}

#endif /* CAMPERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
