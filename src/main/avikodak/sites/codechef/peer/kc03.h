/****************************************************************************************************************************************************
 *  File Name                   : kc03.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/kc03.h
 *  Created on                  : 14-Oct-2015 :: 10:02:31 am
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/KC03
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

#ifndef KC03_H_
#define KC03_H_

bool isValidMatrix(vector<string> userInput) {
    unsigned int setBitCount = 0;
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        setBitCount = 0;
        for(unsigned int columnCounter = 0; columnCounter < userInput.size(); columnCounter++) {
            if(userInput[rowCounter][columnCounter] == '1') {
                setBitCount++;
            }
        }
        if(setBitCount&1) {
            return false;
        }
    }
    for(unsigned int columCounter = 0; columCounter < userInput.size(); columCounter++) {
        setBitCount = 0;
        for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
            if(userInput[rowCounter][columCounter] == '1') {
                setBitCount++;
            }
        }
        if(setBitCount&1) {
            return false;
        }
    }
    return true;
}

bool isValidEntry(vector<string> userInput,unsigned int row,unsigned int column) {
    return true;
}

void processMatrix(vector<string> userInput) {
    unsigned int setBitCount;
    unsigned int updatedRow,updatedColumn;
    bool alreadyUpdated = false;
    for(unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        setBitCount = 0;
        for(unsigned int columnCounter = 0; columnCounter < userInput.size(); columnCounter++) {
            if(userInput[rowCounter][columnCounter] == '1') {
                setBitCount++;
            }
        }
        if((setBitCount&1) && !alreadyUpdated) {
            if(alreadyUpdated) {
                printf("0\n");
                return;
            } else {
                for(unsigned int columnCounter = 0; columnCounter < userInput.size(); columnCounter++) {
                    if(userInput[rowCounter][columnCounter] == '0') {

                    }
                }
            }
        }
    }
    if(alreadyUpdated) {
        printf("(%d,%d)",updatedRow,updatedColumn);
    } else {
        printf("1\n");
    }
}

void printResults() {
    unsigned int testCases,size;
    string input;
    scanf("%u",&testCases);
    vector<string> matrix;
    while(testCases--) {
        scanf("%u",&size);
        matrix.clear();
        for(unsigned int counter = 0; counter < size; counter++) {
            cin >> input;
            matrix.push_back(input);
        }
        processMatrix(matrix);
    }
}

#endif /* KC03_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
