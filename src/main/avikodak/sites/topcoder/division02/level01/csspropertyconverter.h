/****************************************************************************************************************************************************
 *  File Name                   : csspropertyconverter.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\csspropertyconverter.h
 *  Created on                  : May 1, 2015 :: 2:30:36 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=7503
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

#ifndef CSSPROPERTYCONVERTER_H_
#define CSSPROPERTYCONVERTER_H_

class CssPropertyConverter {
public:
    string getCamelized(string cssPropertyName) {
        string result;
        for(unsigned int counter = 0; counter < cssPropertyName.size(); counter++) {
            if(cssPropertyName[counter] == '-') {
                result.push_back(cssPropertyName[counter+1]-'a'+'A');
                counter++;
            } else {
                result.push_back(cssPropertyName[counter]);
            }
        }
        return result;
    }
};

#endif /* CSSPROPERTYCONVERTER_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
