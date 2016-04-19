/****************************************************************************************************************************************************
 *  File Name                   : approx2.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/approx2.h
 *  Created on                  : 27-Oct-2015 :: 8:24:58 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/APPROX2
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

#ifndef APPROX2_H_
#define APPROX2_H_

//Tested
void printResults() {
    long long int testCases,size,key,input,total,result,minValue;
    vector<long long int> userInput;
    scanf("%lld",&testCases);
    while(testCases--) {
        scanf("%lld %lld",&size,&key);
        userInput.clear();
        for(long long int counter = 0; counter < size; counter++) {
            scanf("%lld",&input);
            userInput.push_back(input);
        }
        minValue = abs(userInput[1] + userInput[0] - key);
        total = 0;
        for(long long int outerCrawler = 0; outerCrawler < size; outerCrawler++) {
            for(long long int innerCrawler = outerCrawler+1; innerCrawler < size; innerCrawler++) {
                result = abs(userInput[outerCrawler] + userInput[innerCrawler]-key);
                if(result < minValue) {
                    total = 1;
                    minValue = result;
                } else if(result == minValue) {
                    total++;
                }
            }
        }
        printf("%lld %lld\n",minValue,total);
    }
}

#endif /* APPROX2_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
