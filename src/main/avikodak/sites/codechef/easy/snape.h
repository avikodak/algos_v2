/****************************************************************************************************************************************************
 *  File Name                   : snape.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codechef\easy\snape.h
 *  Created on                  : Feb 9, 2015 :: 9:40:43 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SNAPE/
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

#ifndef SNAPE_H_
#define SNAPE_H_

//Tested
void printResults() {
    unsigned int testCases;
    double firstSide,secondSide;
    scanf("%u",&testCases);
    while(testCases--) {
        cin >> firstSide >> secondSide;
        if(firstSide > secondSide) {
            cout << sqrt(firstSide*firstSide - secondSide * secondSide);
        } else {
            cout << sqrt(secondSide*secondSide - firstSide*firstSide);
        }
        cout << " " << sqrt(firstSide*firstSide + secondSide*secondSide) << endl;
    }
}

#endif /* SNAPE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
