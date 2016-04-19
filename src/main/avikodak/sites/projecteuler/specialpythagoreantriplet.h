/****************************************************************************************************************************************************
 *  File Name                   : specialpythagoreantriplet.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\specialpythagoreantriplet.h
 *  Created on                  : Aug 11, 2015 :: 8:38:07 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=9
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

#ifndef SPECIALPYTHAGOREANTRIPLET_H_
#define SPECIALPYTHAGOREANTRIPLET_H_

//Tested
//Ans : 31875000
void printSpecialPythagoreanTriplet() {
    unsigned int counter;
    for(unsigned int outerCounter = 2; outerCounter < 1000; outerCounter++) {
        for(unsigned int innerCounter = outerCounter+1; innerCounter < 1000; innerCounter++) {
            counter = 1000 - outerCounter - innerCounter;
            if(counter > 0) {
                if(outerCounter*outerCounter + innerCounter * innerCounter == counter *counter) {
                    cout << outerCounter * innerCounter * counter << endl;
                    return;
                }
            } else {
                break;
            }
        }
    }
}

#endif /* SPECIALPYTHAGOREANTRIPLET_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
