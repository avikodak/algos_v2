/****************************************************************************************************************************************************
 *  File Name                   : themovieslevelonedivtwo.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\page03\themovieslevelonedivtwo.h
 *  Created on                  : Jul 22, 2015 :: 11:29:05 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=10899
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

#ifndef THEMOVIESLEVELONEDIVTWO_H_
#define THEMOVIESLEVELONEDIVTWO_H_

class TheMoviesLevelOneDivTwo {
public:
    int find(int n, int m,vector<int> row,vector<int> seat) {
        bool flags[n][m] = {true};
        for(unsigned counter = 0; counter < row.size(); counter++) {
            flags[row[counter]-1][seat[counter]-1] = false;
        }
        int totalCount = 0;
        for(unsigned int rowCounter = 0; rowCounter < row.size(); rowCounter++) {
            for(unsigned int columnCounter = 0; columnCounter < seat.size()-1; columnCounter++) {
                if(flags[rowCounter][columnCounter] && flags[rowCounter][columnCounter+1]) {
                    totalCount++;
                }
            }
        }
        return totalCount;
    }
};

#endif /* THEMOVIESLEVELONEDIVTWO_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
