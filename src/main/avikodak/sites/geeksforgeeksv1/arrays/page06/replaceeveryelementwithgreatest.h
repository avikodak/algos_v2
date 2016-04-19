/****************************************************************************************************************************************************
 *  File Name                   : replaceeveryelementwithgreatest.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\replaceeveryelementwithgreatest.h
 *  Created on                  : Nov 27, 2014 :: 8:00:16 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/replace-every-element-with-the-greatest-on-right-side/
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef REPLACEEVERYELEMENTWITHGREATEST_H_
#define REPLACEEVERYELEMENTWITHGREATEST_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void replaceEveryElementON(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    int maxTillNow = userInput[userInput.size()-1],temp;
    userInput[userInput.size()-1] = -1;
    for(int counter = userInput.size()-2; counter >= 0; counter--) {
        temp = userInput[counter];
        userInput[counter] = maxTillNow;
        maxTillNow = max(maxTillNow,temp);
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void replaceEveryElementON2(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    unsigned int innerCounter;
    int maxElement;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size()-1; outerCounter++) {
        maxElement = userInput[outerCounter+1];
        for(innerCounter = outerCounter+1; innerCounter < userInput.size(); innerCounter++) {
            maxElement = max(maxElement,userInput[innerCounter]);
        }
        userInput[outerCounter] = maxElement;
    }
    userInput[userInput.size()-1] = -1;
}

#endif /* REPLACEEVERYELEMENTWITHGREATEST_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
