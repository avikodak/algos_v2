/****************************************************************************************************************************************************
 *  File Name                   : boyorgirl.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codeforces\boyorgirl.h
 *  Created on                  : Mar 1, 2015 :: 9:52:09 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/236/A
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/
#define ALPHABET_SIZE 26

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef BOYORGIRL_H_
#define BOYORGIRL_H_

//Tested
void isUserBoyOrGirl() {
    char userInput[CODEFORCES_MAX_INPUT_SIZE],*ptrToUserInput;
    scanf("%s",userInput);
    bool flags[ALPHABET_SIZE] = {false};
    unsigned int uniqueCharCount = 0;
    ptrToUserInput = userInput;
    while(ptrToUserInput[0] != '\0') {
        flags[ptrToUserInput[0]-'a'] = true;
        ptrToUserInput++;
    }
    for(unsigned int counter = 0; counter < ALPHABET_SIZE; counter++) {
        if(flags[counter]) {
            uniqueCharCount++;
        }
    }
    if(uniqueCharCount&1) {
        printf("IGNORE HIM!");
    } else {
        printf("CHAT WITH HER!");
    }
}


#endif /* BOYORGIRL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
