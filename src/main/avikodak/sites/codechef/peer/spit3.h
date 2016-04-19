/****************************************************************************************************************************************************
 *  File Name                   : spit3.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/spit3.h
 *  Created on                  : 24-Sep-2015 :: 3:16:49 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SPIT3
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
#include <iomanip>
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

#ifndef SPIT3_H_
#define SPIT3_H_

//Tested
void printResults() {
    string userInput;
    getline(cin,userInput);
    if(userInput.size() < 5) {
        printf("NO");
        return;
    }
    bool smallFlag = false,capitalFlag = false,numFlag = false,isValid = false;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] >= 'a' && userInput[counter] <= 'z') {
            smallFlag = true;
        } else if(userInput[counter] >= 'A' && userInput[counter] <= 'Z') {
            capitalFlag = true;
        } else if(userInput[counter] >= '0' && userInput[counter] <= '9') {
            numFlag = true;
        }
        if(smallFlag && numFlag && capitalFlag) {
            isValid = true;
            break;
        }
    }
    printf("%s\n",isValid?"YES":"NO");
}

#endif /* SPIT3_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
