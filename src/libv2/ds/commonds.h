/****************************************************************************************************************************************************
 *  File Name                   : commonds.h
 *  File Location               : /algos_v2/src/libv2/ds/commonds.h
 *  Created on                  : Jan 18, 2016 :: 8:28:18 PM
 *  Author                      : avikodak
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
#include <stdint.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef LIBV2_DS_COMMONDS_H_
#define LIBV2_DS_COMMONDS_H_

struct iPair {
    int firstValue;
    int secondValue;

    iPair() {
        this->firstValue = 0;
        this->secondValue = 0;
    }

    iPair(int firstValue,int secondValue) {
        this->firstValue = firstValue;
        this->secondValue = secondValue;
    }
};

#endif /* LIBV2_DS_COMMONDS_H_ */
