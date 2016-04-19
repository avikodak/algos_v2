/****************************************************************************************************************************************************
 *  File Name                   : palindromeindex.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\strings\palindromeindex.h
 *  Created on                  : Jun 23, 2015 :: 8:29:36 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/palindrome-index
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

#ifndef PALINDROMEINDEX_H_
#define PALINDROMEINDEX_H_

//Tested
void getPalindromeIndex() {
    unsigned int testCases,frontCrawler,rearCrawler;
    scanf("%u",&testCases);
    string userInput;
    bool indexFound;
    while(testCases--) {
        cin >> userInput;
        frontCrawler = 0;
        rearCrawler = userInput.size()-1;
        indexFound = false;
        while(frontCrawler < rearCrawler) {
            if(userInput[frontCrawler] != userInput[rearCrawler]) {
                if(frontCrawler+1 == rearCrawler || frontCrawler+1 == rearCrawler-1) {
                    printf("%d\n",frontCrawler);
                } else if(userInput[frontCrawler+1] == userInput[rearCrawler]) {
                    printf("%d\n",frontCrawler);
                } else {
                    printf("%d\n",rearCrawler);
                }
                indexFound = true;
                break;
            }
            frontCrawler++;
            rearCrawler--;
        }
        if(!indexFound) {
            printf("-1\n");
        }
    }
}

#endif /* PALINDROMEINDEX_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
