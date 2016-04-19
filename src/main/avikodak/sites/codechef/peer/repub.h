/****************************************************************************************************************************************************
 *  File Name                   : repub.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/repub.h
 *  Created on                  : 24-Sep-2015 :: 9:12:41 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/REPUB
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

#ifndef REPUB_H_
#define REPUB_H_

//Tested
void printMaxChar(string userInput) {
    unsigned int freq[26] = {0},maxFreq = 0;
    char maxChar;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] >= 'A' && userInput[counter] <= 'Z') {
            freq[userInput[counter]-'A']++;
            if(maxFreq == freq[userInput[counter]-'A'] && userInput[counter]-'A'+'a' > maxChar) {
                maxChar = userInput[counter]-'A'+'a';
            } else if(maxFreq < freq[userInput[counter]-'A']) {
                maxChar = userInput[counter]-'A'+'a';
                maxFreq = freq[userInput[counter]-'A'];
            }
        } else if(userInput[counter] >= 'a' && userInput[counter] <= 'z') {
            freq[userInput[counter]-'a']++;
            if(maxFreq == freq[userInput[counter]-'a'] && userInput[counter] > maxChar) {
                maxChar = userInput[counter];
            } else if(maxFreq < freq[userInput[counter]-'a']) {
                maxChar = userInput[counter];
                maxFreq = freq[userInput[counter]-'a'];
            }
        }
    }
    cout << maxChar << endl;
}

//Tested
void printResults() {
    unsigned int testCases;
    scanf("%u",&testCases);
    string userInput;
    while(testCases--) {
        cin >> userInput;
        printMaxChar(userInput);
    }
}


#endif /* REPUB_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
