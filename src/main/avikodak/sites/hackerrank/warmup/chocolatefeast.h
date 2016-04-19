/****************************************************************************************************************************************************
 *  File Name                   : chocolatefeast.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\hackerrank\warmup\chocolatefeast.h
 *  Created on                  : Feb 6, 2015 :: 9:06:34 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/chocolate-feast
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

#ifndef CHOCOLATEFEAST_H_
#define CHOCOLATEFEAST_H_

//Tested
void totalChocolates() {
    int testCases;
    scanf("%d",&testCases);
    long int money,cost,offer,total,activeWrappers;
    while(testCases--) {
        scanf("%ld %ld %ld",&money,&cost,&offer);
        total = money/cost;
        activeWrappers = total;
        while(activeWrappers >= offer) {
            total += (activeWrappers/offer);
            activeWrappers = (activeWrappers/offer) + (activeWrappers%offer);
        }
        printf("%ld\n",total);
    }
}

#endif /* CHOCOLATEFEAST_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
