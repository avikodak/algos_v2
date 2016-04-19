/****************************************************************************************************************************************************
 *  File Name                   : subinc.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/contest/octoberchallenge2015/subinc.h
 *  Created on                  : 12-Oct-2015 :: 11:47:44 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/OCT15/problems/SUBINC
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

#ifndef SUBINC_H_
#define SUBINC_H_

//Tested
void printResults() {
    long long int testCases,size,input,result;
    vector<long long int> userInput;
    scanf("%lld",&testCases);
    while(testCases--) {
        scanf("%lld",&size);
        userInput.clear();
        result = 0;
        while(size--) {
            scanf("%lld",&input);
            userInput.push_back(input);
        }
        unsigned int outerCrawler= 0,innerCrawler;
        long long int incSubSize  = 0;
        while(outerCrawler < userInput.size()) {
            innerCrawler = outerCrawler+1;
            incSubSize = 1;
            while(innerCrawler < userInput.size() && userInput[innerCrawler] >= userInput[innerCrawler-1]) {
                incSubSize++;
                innerCrawler++;
            }
            result += ((incSubSize)*(incSubSize+1))/2;
            outerCrawler = innerCrawler;
        }
        printf("%lld\n",result);
    }
}

#endif /* SUBINC_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
