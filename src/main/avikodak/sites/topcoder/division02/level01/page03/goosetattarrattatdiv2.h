/****************************************************************************************************************************************************
 *  File Name                   : goosetattarrattatdiv2.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\page03\goosetattarrattatdiv2.h
 *  Created on                  : Jul 19, 2015 :: 2:29:37 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=12733
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

#ifndef GOOSETATTARRATTATDIV2_H_
#define GOOSETATTARRATTATDIV2_H_

//Tested
class GooseTattarrattatDiv2 {
public:
    int getmin(string userInput) {
        int lengths[26] = {0};
        int maxLength = 0;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            lengths[userInput[counter]-'a'] += 1;
            maxLength = max(maxLength,lengths[userInput[counter]-'a']);
        }
        return userInput.size() - maxLength;
    }
};

#endif /* GOOSETATTARRATTATDIV2_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
