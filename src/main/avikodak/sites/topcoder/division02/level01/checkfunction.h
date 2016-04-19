/****************************************************************************************************************************************************
 *  File Name                   : CheckFunction.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\CheckFunction.h
 *  Created on                  : Mar 23, 2015 :: 12:26:09 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=4788
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

#ifndef CHECKFUNCTION_H_
#define CHECKFUNCTION_H_

//Tested
class CheckFunction {
public:
    int newFunction(string userInput) {
        if(userInput.size() == 0) {
            return 0;
        }
        unsigned dashFrequency = 0;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            switch(userInput[counter]) {
            case '0':
            case '6':
            case '9':
                dashFrequency += 6;
                break;
            case '1':
                dashFrequency += 2;
                break;
            case '2':
            case '3':
            case '5':
                dashFrequency += 5;
                break;
            case '4':
                dashFrequency += 4;
                break;
            case '7':
                dashFrequency += 3;
                break;
            case '8':
                dashFrequency += 7;
                break;
            }
        }
        return dashFrequency;
    }
};

#endif /* CHECKFUNCTION_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
