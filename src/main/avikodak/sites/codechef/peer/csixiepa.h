/****************************************************************************************************************************************************
 *  File Name                   : csixiepa.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/csixiepa.h
 *  Created on                  : 23-Sep-2015 :: 11:35:31 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/CSIXIEPA
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

#ifndef CSIXIEPA_H_
#define CSIXIEPA_H_

//Tested
void printResults() {
    vector<bool> flags;
    flags.assign(26,false);
    unsigned int testCases;
    string userInput;
    cin >> testCases;
    cin.ignore();
    while(testCases--) {
        getline(cin,userInput);
        fill(flags.begin(),flags.end(),false);
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(userInput[counter] >= 'a' && userInput[counter] <= 'z') {
                flags[userInput[counter]-'a'] = true;
            } else if(userInput[counter] >= 'A' && userInput[counter] <= 'Z') {
                flags[userInput[counter]-'A'] = true;
            }
        }
        bool isPangram = true;
        for(unsigned int counter = 0; counter < 26; counter++) {
            if(!flags[counter]) {
                isPangram = false;
                break;
            }
        }
        printf("%s\n",isPangram?"TRUE":"FALSE");
    }
}

#endif /* CSIXIEPA_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
