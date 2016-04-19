/****************************************************************************************************************************************************
 *  File Name                   : football.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codeforces\football.h
 *  Created on                  : Feb 28, 2015 :: 1:11:19 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/96/A
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
#define MAX_INPUT_SIZE 101

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef FOOTBALL_H_
#define FOOTBALL_H_

//Tested
void isCombinationDangerous() {
    char *ptrToUserInput,userInput[MAX_INPUT_SIZE];
    scanf("%s",userInput);
    unsigned int frequency;
    bool isDangerous = false;
    ptrToUserInput = userInput;
    while(ptrToUserInput[0] != '\0') {
        frequency = 1;
        while(ptrToUserInput[1] != '\0' && ptrToUserInput[0] == ptrToUserInput[1]) {
            ptrToUserInput++;
            frequency++;
            if(frequency >= 7) {
                isDangerous = true;
                break;
            }
        }
        if(isDangerous) {
            break;
        }
        ptrToUserInput++;
    }
    printf("%s",isDangerous?"YES":"NO");
}

#endif /* FOOTBALL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
