/****************************************************************************************************************************************************
 *  File Name                   : pathsumtwoways.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\pathsumtwoways.h
 *  Created on                  : Aug 19, 2015 :: 11:04:49 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=81
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

#ifndef PATHSUMTWOWAYS_H_
#define PATHSUMTWOWAYS_H_

//Tested
vector<vector<unsigned int> > getMatrix() {
    unsigned int size,input;
    cin >> size;
    vector<vector<unsigned int> > userInput(size);
    for(unsigned int counter = 0; counter < size; counter++) {
        userInput[counter].assign(size,0);
    }
    for(unsigned int rowCounter = 0; rowCounter < size; rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < size; columnCounter++) {
            cin >> input;
            userInput[rowCounter][columnCounter] = input;
        }
    }
    return userInput;
}

//Tested
//Ans : 427337
void printMinimalPathSum() {
    vector<vector<unsigned int> > userInput = getMatrix();
    unsigned int size = userInput.size();
    for(int columnCounter = size-2; columnCounter >= 0; columnCounter--) {
        userInput[size-1][columnCounter] += userInput[size-1][columnCounter+1];
    }
    for(int rowCounter = size-2; rowCounter >= 0; rowCounter--) {
        userInput[rowCounter][size-1] += userInput[rowCounter+1][size-1];
    }
    for(int rowCounter = size-2; rowCounter >= 0; rowCounter--) {
        for(int columnCounter = size-2; columnCounter >=0; columnCounter--) {
            userInput[rowCounter][columnCounter] += min(userInput[rowCounter][columnCounter+1],userInput[rowCounter+1][columnCounter]);
        }
    }
    cout << userInput[0][0] << endl;
}

#endif /* PATHSUMTWOWAYS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
