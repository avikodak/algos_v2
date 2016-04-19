/****************************************************************************************************************************************************
 *  File Name                   : halloweenparty.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\hackerrank\warmup\halloweenparty.h
 *  Created on                  : Feb 6, 2015 :: 11:37:42 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/halloween-party
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

#ifndef HALLOWEENPARTY_H_
#define HALLOWEENPARTY_H_

void getMaxCutsChocolateBar() {
    int testCases;
    scanf("%d",&testCases);
    long int userInput,temp;
    while(testCases--) {
        scanf("%ld",&userInput);
        temp = userInput/2;
        if(userInput%2 == 0) {
            printf("%ld\n",temp * temp);
        } else {
            printf("%ld\n",temp * (temp+1));
        }
    }
}

#endif /* HALLOWEENPARTY_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
