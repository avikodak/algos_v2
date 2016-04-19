/****************************************************************************************************************************************************
 *  File Name                   : ultrafastmultiplication.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\ultrafastmultiplication.h
 *  Created on                  : Mar 5, 2015 :: 8:12:47 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/61/A
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

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef ULTRAFASTMULTIPLICATION_H_
#define ULTRAFASTMULTIPLICATION_H_

//Tested
void getXORResultVeryLong() {
    char firstUserInput[CODEFORCES_MAX_INPUT_SIZE];
    char secondUserInput[CODEFORCES_MAX_INPUT_SIZE];
    scanf("%s %s",firstUserInput,secondUserInput);
    int lengthOfInputString = strlen(firstUserInput);
    for(int counter = 0; counter < lengthOfInputString; counter++) {
        if(firstUserInput[counter] == secondUserInput[counter]) {
            printf("0");
        } else {
            printf("1");
        }
    }
}

#endif /* ULTRAFASTMULTIPLICATION_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
