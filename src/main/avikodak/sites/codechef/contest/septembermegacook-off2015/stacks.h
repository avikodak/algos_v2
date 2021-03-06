/****************************************************************************************************************************************************
 *  File Name                   : stacks.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/contest/septembermegacook-off2015/stacks.h
 *  Created on                  : 20-Sep-2015 :: 9:57:04 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/COOK62/problems/STACKS
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
#define gc getchar_unlocked

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef STACKS_H_
#define STACKS_H_

//Tested
void scanllint(long long int &x) {
    register int c = gc();
    x = 0;
    for(; (c<48 || c>57); c = gc());
    for(; c>47 && c<58; c = gc()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
}

//Tested
void printResults() {
    long long int testCases,input;
    long long int size;
    vector<long long int> userInput,stacks;
    vector<long long int>::iterator itToStacks;
    scanllint(testCases);
    while(testCases--) {
        scanllint(size);
        userInput.clear();
        stacks.clear();
        for(unsigned int counter = 0; counter < size; counter++) {
            scanllint(input);
            userInput.push_back(input);
        }
        for(unsigned int outerCounter = 0; outerCounter < size; outerCounter++) {
            itToStacks = upper_bound(stacks.begin(),stacks.end(),userInput[outerCounter]);
            if(itToStacks == stacks.end()) {
                stacks.push_back(userInput[outerCounter]);
            } else {
                stacks[itToStacks-stacks.begin()] = userInput[outerCounter];
            }
        }
        cout << stacks.size() << " ";
        for(unsigned int counter = 0; counter < stacks.size(); counter++) {
            cout << stacks[counter] << " ";
        }
        cout << endl;
    }
}

#endif /* STACKS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
