/****************************************************************************************************************************************************
 *  File Name                   : valueofstring.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\valueofstring.h
 *  Created on                  : May 1, 2015 :: 3:29:30 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=13678
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

#ifndef VALUEOFSTRING_H_
#define VALUEOFSTRING_H_

class ValueOfString {
public:
    int findValue(string userInput) {
        map<char,int> frequency;
        map<char,int>::iterator itToFrequency;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(frequency.find(userInput[counter]) == frequency.end()) {
                frequency[userInput[counter]] = 1;
            } else {
                frequency[userInput[counter]] += 1;
            }
        }
        int sum = 0;
        for(itToFrequency = frequency.begin(); itToFrequency != frequency.end(); itToFrequency++) {
            sum += itToFrequency->second;
            frequency[itToFrequency->first] = sum;
        }
        sum = 0;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            sum += (userInput[counter] -'a'+1)*(frequency[userInput[counter]]);
        }
        return sum;
    }
};

#endif /* VALUEOFSTRING_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
