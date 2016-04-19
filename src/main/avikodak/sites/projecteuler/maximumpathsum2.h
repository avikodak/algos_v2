/****************************************************************************************************************************************************
 *  File Name                   : maximumpathsum2.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\maximumpathsum2.h
 *  Created on                  : Aug 12, 2015 :: 8:57:29 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=67
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

#ifndef MAXIMUMPATHSUM2_H_
#define MAXIMUMPATHSUM2_H_

//Tested
//Ans : 7273
void getMaximumPathSum() {
    unsigned int rows,input;
    cin >> rows;
    vector<vector<unsigned int> > userInput(rows);
    for(unsigned int rowCounter = 1; rowCounter <= rows; rowCounter++) {
        for(unsigned int columnCounter = 1; columnCounter <= rowCounter; columnCounter++) {
            cin >> input;
            userInput[rowCounter-1].push_back(input);
        }
    }
    for(int rowCounter = userInput.size()-2; rowCounter >= 0; rowCounter--) {
        for(int columnCounter = userInput[rowCounter].size()-1; columnCounter >= 0; columnCounter--) {
            userInput[rowCounter][columnCounter] += max(userInput[rowCounter+1][columnCounter],userInput[rowCounter+1][columnCounter+1]);
        }
    }
    cout << userInput[0][0] << endl;
}

#endif /* MAXIMUMPATHSUM2_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
