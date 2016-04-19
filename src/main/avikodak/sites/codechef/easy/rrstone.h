/****************************************************************************************************************************************************
 *  File Name                   : rrstone.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\rrstone.h
 *  Created on                  : Sep 7, 2015 :: 9:23:36 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/RRSTONE
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

#ifndef RRSTONE_H_
#define RRSTONE_H_

//Tested
void printArray(long long int size, vector<long long int> userInput) {
    for(long long int counter = 0; counter < size; counter++) {
        cout << userInput[counter] << " ";
    }
    cout << endl;
}

//Tested
void printArrayPostOps() {
    long long int size,operations,maxVal,input;
    cin >> size >> operations;
    vector<long long int> userInput;
    for(long long int counter = 0; counter < size; counter++) {
        cin >> input;
        userInput.push_back(input);
    }
    if(operations == 0) {
        printArray(size,userInput);
        return;
    }
    if(operations%2 == 1) {
        operations = 1;
    } else {
        operations = 2;
    }
    for(long long int counter = 0; counter < operations; counter++) {
        maxVal = *max_element(userInput.begin(),userInput.end());
        for(int innerCounter = 0; innerCounter < size; innerCounter++) {
            userInput[innerCounter] = maxVal - userInput[innerCounter];
        }
    }

    printArray(size, userInput);
}

#endif /* RRSTONE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
