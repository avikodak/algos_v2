/****************************************************************************************************************************************************
 *  File Name                   : icecreamparlour.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\hackerrank\search\icecreamparlour.h
 *  Created on                  : Feb 11, 2015 :: 12:32:13 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/icecream-parlor
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

#ifndef ICECREAMPARLOUR_H_
#define ICECREAMPARLOUR_H_

//Tested
void getIndicesForSum() {
    int testCases,size,sum,input;
    vector<int> userInput;
    bool flag;
    while(testCases--) {
        scanf("%d %d",&sum,&size);
        userInput.clear();
        while(size--) {
            scanf("%d",&input);
            userInput.push_back(input);
        }
        flag = false;
        for(unsigned int outerCrawler = 0; outerCrawler < userInput.size(); outerCrawler++) {
            for(unsigned int innerCrawler = outerCrawler+1; innerCrawler < userInput.size(); innerCrawler++) {
                if(userInput[outerCrawler] + userInput[innerCrawler] == sum) {
                    printf("%d %d\n",outerCrawler+1,innerCrawler+1);
                    flag = true;
                }
            }
            if(flag) {
                break;
            }
        }
    }
}

#endif /* ICECREAMPARLOUR_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
