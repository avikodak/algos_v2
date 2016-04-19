/****************************************************************************************************************************************************
 *  File Name                   : lch15jab.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\school\lch15jab.h
 *  Created on                  : Aug 25, 2015 :: 8:41:36 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/LCH15JAB
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

#ifndef LCH15JAB_H_
#define LCH15JAB_H_

//Tested
void areCharWithSameFrequency(string userInput) {
    sort(userInput.begin(),userInput.end());
    unsigned int counter = 0,frequency,maxFrequency = 0;
    while(counter < userInput.size()) {
        frequency = 1;
        while(counter+1 < userInput.size() && userInput[counter] == userInput[counter+1]) {
            counter++;
            frequency++;
        }
        counter++;
        maxFrequency = max(maxFrequency,frequency);
    }
    printf("%s\n",maxFrequency == userInput.size()-maxFrequency?"YES":"NO");
}

//Tested
void printResults() {
    unsigned int testCases;
    cin >> testCases;
    string userInput;
    while(testCases--) {
        cin >> userInput;
        areCharWithSameFrequency(userInput);
    }
}

#endif /* LCH15JAB_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
