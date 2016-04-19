/****************************************************************************************************************************************************
 *  File Name                   : sherlockandarray.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\hackerrank\implementation\sherlockandarray.h
 *  Created on                  : Feb 10, 2015 :: 6:45:22 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/sherlock-and-array
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

#ifndef SHERLOCKANDARRAY_H_
#define SHERLOCKANDARRAY_H_

//Tested
void doesEquilibriumElementExists() {
    int testCases,size;
    long int input,sumOfArray,leftSum;
    scanf("%d",&testCases);
    vector<int> userInput;
    bool flag;
    while(testCases--) {
        scanf("%d",&size);
        sumOfArray = 0;
        userInput.clear();
        while(size--) {
            scanf("%ld",&input);
            sumOfArray += input;
            userInput.push_back(input);
        }
        leftSum = 0;
        flag = false;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(leftSum == sumOfArray - leftSum - userInput[counter]) {
                flag = true;
                break;
            }
            leftSum += userInput[counter];
        }
        printf("%s\n",flag?"YES":"NO");
    }
}

#endif /* SHERLOCKANDARRAY_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
