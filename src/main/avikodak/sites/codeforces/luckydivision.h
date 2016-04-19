/****************************************************************************************************************************************************
 *  File Name                   : luckydivision.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\luckydivision.h
 *  Created on                  : Mar 3, 2015 :: 6:30:19 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/122/A
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

#ifndef LUCKYDIVISION_H_
#define LUCKYDIVISION_H_

//Tested
void printIsNumberCloseToLucky() {
    int luckyNumbers[] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};
    unsigned int userInput;
    scanf("%d",&userInput);
    unsigned int size = sizeof(luckyNumbers)/sizeof(int);
    for(unsigned int counter = 0; counter < size; counter++) {
        if(luckyNumbers[counter] > userInput) {
            printf("NO");
            return;
        }
        if(userInput%luckyNumbers[counter] == 0) {
            printf("YES");
            return;
        }
    }
    printf("NO");
}

#endif /* LUCKYDIVISION_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
