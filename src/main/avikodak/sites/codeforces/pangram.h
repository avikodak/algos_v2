/****************************************************************************************************************************************************
 *  File Name                   : pangram.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\pangram.h
 *  Created on                  : Apr 11, 2015 :: 7:31:43 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/520/A
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

#ifndef PANGRAM_H_
#define PANGRAM_H_

//Tested
void isStringPangram() {
    unsigned int size;
    scanf("%u",&size);
    string userInput;
    cin >> userInput;
    bool flags[26] = {false};
    for(unsigned int counter = 0; counter < size; counter++) {
        if(userInput[counter] >= 'a' && userInput[counter] <= 'z') {
            flags[userInput[counter]-'a'] = true;
        } else {
            flags[userInput[counter]-'A'] = true;
        }
    }
    for(unsigned int counter = 0; counter < 26; counter++) {
        if(!flags[counter]) {
            printf("NO");
            return;
        }
    }
    printf("YES");
}

#endif /* PANGRAM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
