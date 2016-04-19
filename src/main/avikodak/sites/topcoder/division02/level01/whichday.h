/****************************************************************************************************************************************************
 *  File Name                   : whichday.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\whichday.h
 *  Created on                  : Mar 30, 2015 :: 5:09:41 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=11553
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

#ifndef WHICHDAY_H_
#define WHICHDAY_H_

//Tested
class WhichDay {
public:
    string getDay(vector<string> notOnThisDay) {
        bool flags[7] = {false};
        string days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        string input;
        for(unsigned int counter = 0; counter < notOnThisDay.size(); counter++) {
            input = notOnThisDay[counter];
            if(input.compare("Sunday")) {
                flags[0] = true;
            } else if(input.compare("Monday")) {
                flags[1] = true;
            } else if(input.compare("Tuesday")) {
                flags[2] = true;
            } else if(input.compare("Wednesday")) {
                flags[3] = true;
            } else if(input.compare("Thursday")) {
                flags[4] = true;
            } else if(input.compare("Friday")) {
                flags[5] = true;
            } else if(input.compare("Saturday")) {
                flags[6] = true;
            }
        }
        for(unsigned int counter = 0; counter < 7; counter++) {
            if(!flags[counter]) {
                return days[counter];
            }
        }
    }
};

#endif /* WHICHDAY_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
