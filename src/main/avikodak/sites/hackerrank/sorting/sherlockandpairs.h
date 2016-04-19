/****************************************************************************************************************************************************
 *  File Name                   : sherlockandpairs.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\hackerrank\sorting\sherlockandpairs.h
 *  Created on                  : Feb 12, 2015 :: 3:13:12 PM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : TODO
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef SHERLOCKANDPAIRS_H_
#define SHERLOCKANDPAIRS_H_

void countEqualPairs() {
    long int testCases,size,input;
    scanf("%ld",&testCases);
    vector<long int> userInput;
    long int crawler,counter,total;
    while(testCases--) {
        scanf("%ld",&size);
        userInput.clear();
        while(size--) {
            scanf("%ld",&input);
            userInput.push_back(input);
        }
        sort(userInput.begin(),userInput.end());
        crawler = counter = total = 0;
        while(crawler < userInput.size()) {
            counter = 1;
            while(crawler+1 < userInput.size() && userInput[crawler] == userInput[crawler+1]) {
                counter += 1;
                crawler++;
            }
            total += (counter * (counter-1));
            crawler++;
        }
        printf("%ld\n",total);
    }
}

#endif /* SHERLOCKANDPAIRS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
