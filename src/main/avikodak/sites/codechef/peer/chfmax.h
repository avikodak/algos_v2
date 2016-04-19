/****************************************************************************************************************************************************
 *  File Name                   : chfmax.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/chfmax.h
 *  Created on                  : 24-Sep-2015 :: 8:54:31 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/CHFMAX
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

#ifndef CHFMAX_H_
#define CHFMAX_H_

//Tested
void convertToReqFormat(string userInput) {
    unsigned int frequency[26] = {0},maxFreq = 0;
    char maxOccuringChar;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        frequency[userInput[counter]-'a']++;
        if(maxFreq == frequency[userInput[counter]-'a'] && maxOccuringChar > userInput[counter]) {
            maxOccuringChar = userInput[counter];
        } else if(maxFreq < frequency[userInput[counter]-'a']) {
            maxFreq = frequency[userInput[counter]-'a'];
            maxOccuringChar = userInput[counter];
        }
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("%c",maxOccuringChar==userInput[counter]?'?':userInput[counter]);
    }
    printf("\n");
}

//Tested
void printResults() {
    unsigned int testCases;
    scanf("%u",&testCases);
    string userInput;
    while(testCases--) {
        cin >> userInput;
        convertToReqFormat(userInput);
    }
}

#endif /* CHFMAX_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
