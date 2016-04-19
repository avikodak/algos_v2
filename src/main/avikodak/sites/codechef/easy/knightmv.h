/****************************************************************************************************************************************************
 *  File Name                   : knightmv.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/knightmv.h
 *  Created on                  : 09-Sep-2015 :: 11:08:25 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/KNIGHTMV
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

#ifndef KNIGHTMV_H_
#define KNIGHTMV_H_

//Tested
bool isRightAlpha(char ch) {
    return ch >= 'a' && ch <= 'h';
}

//Tested
bool isRightNumber(char ch) {
    return ch >= '1' && ch <= '8';
}

//Tested
void printResults() {
    unsigned int testCases;
    cin >> testCases;
    cin.ignore();
    string userInput;
    int alphaDiff,numbDiff;
    while(testCases--) {
        getline(cin,userInput);
        if(userInput.size() == 5 && isRightAlpha(userInput[0]) && isRightAlpha(userInput[3]) && isRightNumber(userInput[1]) && isRightNumber(userInput[4]) && userInput[2] == '-') {
            alphaDiff = abs(userInput[3]-userInput[0]);
            numbDiff = abs(userInput[4]-userInput[1]);
            if(alphaDiff == 2) {
                printf("%s\n",numbDiff == 1?"Yes":"No");
            } else if(alphaDiff == 1) {
                printf("%s\n",numbDiff == 2?"Yes":"No");
            } else {
                printf("No\n");
            }
        } else {
            cout << "Error" << endl;
        }
    }
}

#endif /* KNIGHTMV_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
