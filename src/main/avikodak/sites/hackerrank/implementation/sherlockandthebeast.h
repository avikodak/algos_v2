/****************************************************************************************************************************************************
 *  File Name                   : sherlockandthebeast.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\implementation\sherlockandthebeast.h
 *  Created on                  : Jun 28, 2015 :: 8:52:36 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/sherlock-and-the-beast
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

#ifndef SHERLOCKANDTHEBEAST_H_
#define SHERLOCKANDTHEBEAST_H_

//Tested
void getVirusNumber() {
    unsigned int testCases,userInput;
    scanf("%u",&testCases);
    int largestThreeMultiple,remainder;
    while(testCases--) {
        scanf("%u",&userInput);
        largestThreeMultiple = (userInput/3)*3;
        remainder = userInput - largestThreeMultiple;
        bool flag=false;
        while(largestThreeMultiple >= 0) {
            if(remainder%5 == 0) {
                for(unsigned int counter = 0; counter < largestThreeMultiple; counter++) {
                    printf("5");
                }
                for(unsigned int counter = 0; counter < remainder; counter++) {
                    printf("3");
                }
                break;
            }
            largestThreeMultiple -= 3;
            remainder += 3;
        }
        if(!flag) {
            printf("-1");
        }
        printf("\n");
    }
}

#endif /* SHERLOCKANDTHEBEAST_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
