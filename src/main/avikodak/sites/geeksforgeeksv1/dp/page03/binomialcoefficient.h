/****************************************************************************************************************************************************
 *  File Name                   : binomialcoefficient.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\binomialcoefficient.h
 *  Created on                  : Dec 15, 2014 :: 11:27:57 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/
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

#ifndef BINOMIALCOEFFICIENT_H_
#define BINOMIALCOEFFICIENT_H_

//Tested
int binomialCoefficientMemoization(int n,int r) {
    if(n < r) {
        return INT_MIN;
    }
    vector<vector<int> > auxSpace(n+1);
    for(int rowCounter = 0; rowCounter < n+1; rowCounter++) {
        auxSpace[rowCounter].assign(r+1,0);
        auxSpace[rowCounter][0] = 1;
    }
    for(unsigned int columnCounter = 0; columnCounter < auxSpace[0].size(); columnCounter++) {
        auxSpace[0][columnCounter] = 0;
    }
    auxSpace[0][0] = 1;
    for(unsigned int rowCounter = 1; rowCounter < auxSpace.size(); rowCounter++) {
        for(unsigned int columnCounter = 1; columnCounter < auxSpace[0].size(); columnCounter++) {
            auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter-1][columnCounter-1] + auxSpace[rowCounter-1][columnCounter];
        }
    }
    return auxSpace[auxSpace.size()-1][auxSpace[0].size()-1];
}

//Tested
int binomialCoefficient(int n,int r) {
    if(n == 0) {
        return 0;
    }
    if(r == 0) {
        return 1;
    }
    if(r == 1) {
        return n;
    }
    return binomialCoefficient(n-1,r-1) + binomialCoefficient(n-1,r);
}

#endif /* BINOMIALCOEFFICIENT_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
