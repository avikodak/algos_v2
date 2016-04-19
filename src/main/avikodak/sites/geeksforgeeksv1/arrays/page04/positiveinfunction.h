/****************************************************************************************************************************************************
 *  File Name                   : positiveinfunction.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\positiveinfunction.h
 *  Created on                  : Dec 22, 2014 :: 6:07:04 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/find-the-point-where-a-function-becomes-negative/
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

#ifndef POSITIVEINFUNCTION_H_
#define POSITIVEINFUNCTION_H_

/****************************************************************************************************************************************************/
/*                                                                 O(LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int functionalValue(int x) {
    return (x*x - 10*x - 20); ;
}

//Tested
int getValueWhereFuncIsPositive() {
    int counter = 1;
    while(functionalValue(counter) <= 0) {
        counter *= 2;
    }
    return counter;
}

//Tested
int firstValFuncIsPositiveBinarySearchMain(int startVal,int endVal) {
    if(startVal > endVal) {
        return INT_MIN;
    }
    int middleVal = (startVal + endVal)/2;
    if(functionalValue(middleVal) > 0) {
        if(middleVal-1 > startVal && functionalValue(middleVal-1) > 0) {
            return firstValFuncIsPositiveBinarySearchMain(startVal,middleVal-1);
        } else {
            return middleVal;
        }
    } else {
        return firstValFuncIsPositiveBinarySearchMain(middleVal+1,endVal);
    }
}

//Tested
int firstValFuncIsPositiveBinarySearch() {
    int value = getValueWhereFuncIsPositive();
    return firstValFuncIsPositiveBinarySearchMain(value/2,value);
}

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int firstPointFuncPositive() {
    unsigned int counter;
    for(counter = 1; functionalValue(counter) <= 0; counter++);
    return counter;
}

#endif /* POSITIVEINFUNCTION_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
