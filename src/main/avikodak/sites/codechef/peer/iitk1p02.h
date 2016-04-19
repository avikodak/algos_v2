/****************************************************************************************************************************************************
 *  File Name                   : iitk1p02.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/iitk1p02.h
 *  Created on                  : 17-Sep-2015 :: 1:21:10 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/IITK1P02
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

#ifndef IITK1P02_H_
#define IITK1P02_H_

//Tested
void printResults() {
    string userInput;
    cin >> userInput;
    unsigned int maxFreq = 0,outerCounter = 0,innerCounter = 0,freq;
    char maxChar;
    while(outerCounter < userInput.size()) {
        freq = 1;
        innerCounter = outerCounter+1;
        while(innerCounter < userInput.size() && userInput[outerCounter] == userInput[innerCounter]) {
            freq++;
            innerCounter++;
        }
        if(maxFreq == freq) {
            if(userInput[outerCounter] < maxChar) {
                maxChar = userInput[outerCounter];
            }
        } else if(maxFreq < freq) {
            maxFreq = freq;
            maxChar = userInput[outerCounter];
        }
        outerCounter = innerCounter;
    }
    cout << maxChar << endl;
    cout << maxFreq << endl;
}

#endif /* IITK1P02_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
