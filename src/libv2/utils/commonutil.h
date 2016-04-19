/****************************************************************************************************************************************************
 *  File Name                   : commonutil.h
 *  File Location               : /algos_v2/src/libv2/utils/commonutil.h
 *  Created on                  : Jan 18, 2016 :: 8:30:01 PM
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
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef LIBV2_UTILS_COMMONUTIL_H_
#define LIBV2_UTILS_COMMONUTIL_H_

vector<int> getIRandomVector(unsigned int size,int lowerLimit = 0,int upperLimit = INT_MAX) {
    vector<int> result;
    if(size == 0) {
        return result;
    }
    srand(time(NULL));
    for(unsigned int counter = 0; counter < size; counter++) {
        result.push_back(rand() % upperLimit + lowerLimit);
    }
    return result;
}

#endif /* LIBV2_UTILS_COMMONUTIL_H_ */
