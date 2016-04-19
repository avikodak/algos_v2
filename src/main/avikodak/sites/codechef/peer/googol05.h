/****************************************************************************************************************************************************
 *  File Name                   : googol05.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/googol05.h
 *  Created on                  : 24-Sep-2015 :: 9:26:53 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/GOOGOL05
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

#ifndef GOOGOL05_H_
#define GOOGOL05_H_

//Tested
void printResults() {
    unsigned int testCases;
    map<string,unsigned int> freqMap;
    map<string,unsigned int>::iterator itToFreqMap;
    vector<string> userInput;
    scanf("%u",&testCases);
    string input;
    while(testCases--) {
        cin >> input;
        userInput.push_back(input);
        if((itToFreqMap = freqMap.find(input)) == freqMap.end()) {
            freqMap[input] = 1;
        } else {
            freqMap[input]++;
        }
    }
    sort(userInput.begin(),userInput.end());
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if((itToFreqMap = freqMap.find(userInput[counter])) != freqMap.end()) {
            cout << itToFreqMap->first << " " << itToFreqMap->second << endl;
            freqMap.erase(itToFreqMap->first);
        }
    }
}

#endif /* GOOGOL05_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
