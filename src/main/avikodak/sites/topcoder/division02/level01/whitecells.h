/****************************************************************************************************************************************************
 *  File Name   		: whitecells.h
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\whitecells.h
 *  Created on			: Mar 25, 2015 :: 11:02:56 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://community.topcoder.com/stat?c=problem_statement&pm=8204
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

#ifndef WHITECELLS_H_
#define WHITECELLS_H_

//Tested
class WhiteCells {
public:
    int countOccupied(vector<string> board) {
        bool flag = true;
        int occupiedCells = 0;
        for(unsigned int outerCounter = 0; outerCounter < board.size(); outerCounter++) {
            if(flag) {
                for(unsigned int innerCounter = 0; innerCounter < board[0].size(); innerCounter += 2) {
                    if(board[outerCounter][innerCounter] == 'F') {
                        occupiedCells++;
                    }
                }
            } else {
                for(unsigned int innerCounter = 1; innerCounter < board[0].size(); innerCounter += 2) {
                    if(board[outerCounter][innerCounter] == 'F') {
                        occupiedCells++;
                    }
                }
            }
            flag = !flag;
        }
        return occupiedCells;
    }
};

#endif /* WHITECELLS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
