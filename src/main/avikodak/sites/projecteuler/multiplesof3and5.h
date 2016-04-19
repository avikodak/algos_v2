/****************************************************************************************************************************************************
 *  File Name                   : multiplesof3and5.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\multiplesof3and5.h
 *  Created on                  : Jul 25, 2015 :: 5:52:59 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=1
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

#ifndef MULTIPLESOF3AND5_H_
#define MULTIPLESOF3AND5_H_

//Tested
void sumOfMultiplesOf3And5(long long int number) {
    long long int sum = 0,threeMultiple = 0,fiveMultiple =0;
    while(threeMultiple < number || fiveMultiple < number) {
        if(threeMultiple == fiveMultiple) {
            sum += threeMultiple;
            threeMultiple += 3;
            fiveMultiple += 5;
        } else if(threeMultiple < fiveMultiple) {
            sum +=  threeMultiple;
            threeMultiple += 3;
        } else {
            sum += fiveMultiple;
            fiveMultiple += 5;
        }
    }
    cout << sum << endl;
}


//Can be solved using AP sum(3mutiples) + sum(5multiples) - sum(15multiples)
#endif /* MULTIPLESOF3AND5_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
