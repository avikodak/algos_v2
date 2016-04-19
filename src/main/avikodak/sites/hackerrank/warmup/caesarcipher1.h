/****************************************************************************************************************************************************
 *  File Name                   : caesarcipher1.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\warmup\caesarcipher1.h
 *  Created on                  : Jun 24, 2015 :: 10:57:35 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/caesar-cipher-1
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
#define MAX_SIZE_USER_INPUT 101

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef CAESARCIPHER1_H_
#define CAESARCIPHER1_H_

void getEncodedString() {
    unsigned int size,rotate;
    char userInput[101];
    scanf("%u",&size);
    scanf("%s",userInput);
    scanf("%u",&rotate);
    unsigned int charAscii;
    for(unsigned int counter = 0; counter < size; counter++) {
        if(isalpha(userInput[counter])) {
            if(isupper(userInput[counter])) {
                charAscii = userInput[counter] - 'A' + rotate;
                printf("%c",(charAscii%26) + 'A');
            } else {
                charAscii = userInput[counter] - 'a' + rotate;
                printf("%c",(charAscii%26) + 'a');
            }
        } else {
            printf("%c",userInput[counter]);
        }
    }
}

#endif /* CAESARCIPHER1_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
