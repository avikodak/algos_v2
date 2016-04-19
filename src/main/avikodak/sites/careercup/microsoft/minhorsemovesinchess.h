/****************************************************************************************************************************************************
 *  File Name                   : minhorsemovesinchess.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\careercup\microsoft\minhorsemovesinchess.h
 *  Created on                  : Dec 22, 2014 :: 10:22:50 PM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : http://www.careercup.com/question?id=5657515507318784
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef MINHORSEMOVESINCHESS_H_
#define MINHORSEMOVESINCHESS_H_

int minHorseMoveInChess(vector<vector<bool> > configuration,int destinationX,int destinationY,int currentX,int currentY) {
    if(currentX > configuration[0].size() || currentX < 0 || currentY > configuration.size() || currentY < 0) {
        return INT_MAX;
    }
    if(currentX == destinationX && currentY == destinationY) {
        return 0;
    }
    int minMoves = INT_MAX;
    configuration[currentX][currentY] = true;
    if(!configuration[currentX+1][currentY-2]) {
        minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX+1,currentY-2));
    }
    if(!configuration[currentX+1][currentY+2]) {
        minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX+1,currentY+2));
    }
    if(!configuration[currentX+2][currentY-1]) {
        minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX+2,currentY-1));
    }
    if(!configuration[currentX+2][currentY+1]) {
        minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX+2,currentY+1));
    }
    if(!configuration[currentX-1][currentY-2]) {
        minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX-1,currentY-2));
    }
    if(!configuration[currentX-1][currentY+2]) {
        minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX-1,currentY+2));
    }
    if(!configuration[currentX-2][currentY-1]) {
        minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX-2,currentY-1));
    }
    if(!configuration[currentX-2][currentY+1]) {
        minMoves = min(minMoves,minHorseMoveInChess(configuration,destinationX,destinationY,currentX-2,currentY+1));
    }
    return minMoves;
}

#endif /* MINHORSEMOVESINCHESS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
