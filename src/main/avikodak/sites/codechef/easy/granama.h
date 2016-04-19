/****************************************************************************************************************************************************
 *  File Name                   : granama.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/granama.h
 *  Created on                  : 29-Oct-2015 :: 8:52:58 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/GRANAMA
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

#ifndef GRANAMA_H_
#define GRANAMA_H_

//Tested
void printResults() {
    unsigned int testCases;
    string firstUserInput,secondUserInput;
    scanf("%u",&testCases);
    while(testCases--) {
        cin >> firstUserInput >> secondUserInput;
        int firstFreq[26] = {0},secondFreq[26] = {0};
        for(unsigned int counter = 0; counter < firstUserInput.size(); counter++) {
            firstFreq[firstUserInput[counter]-'a']++;
        }
        for(unsigned int counter = 0; counter < secondUserInput.size(); counter++) {
            secondFreq[secondUserInput[counter]-'a']++;
        }
        bool flag=true;
        for(unsigned int counter = 0; counter < 26; counter++) {
            if(firstFreq[counter] != secondFreq[counter]) {
                flag = false;
                break;
            }
        }
        for(unsigned int counter = 0; counter < 26; counter++) {
            if(firstFreq[counter] > 0 || secondFreq[counter] > 0) {
                if(firstFreq[counter] == 0 || secondFreq[counter] == 0) {
                    flag = true;
                    break;
                }
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
}

#endif /* GRANAMA_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
