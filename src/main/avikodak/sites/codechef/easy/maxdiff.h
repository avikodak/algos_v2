/****************************************************************************************************************************************************
 *  File Name                   : maxdiff.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\maxdiff.h
 *  Created on                  : Sep 4, 2015 :: 8:53:47 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/MAXDIFF
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

#ifndef MAXDIFF_H_
#define MAXDIFF_H_

//Tested
void printMinDifference(vector<unsigned int> userInput,int kValue,int sum) {
    int firstKSum=0,lastKSum = 0;
    sort(userInput.begin(),userInput.end());
    for(int counter = 0; counter < kValue; counter++) {
        firstKSum += userInput[counter];
    }
    for(int counter = userInput.size()-1; kValue--; counter--) {
        lastKSum += userInput[counter];
    }
    cout << max(abs(firstKSum - (sum-firstKSum)),abs(lastKSum-(sum-lastKSum))) << endl;
}

//Tested
void printResults() {
    unsigned int testCases,input,size;
    int kValue,sum;
    scanf("%u",&testCases);
    vector<unsigned int> userInput;
    while(testCases--) {
        scanf("%u %u",&size,&kValue);
        userInput.clear();
        sum = 0;
        while(size--) {
            scanf("%u",&input);
            sum += input;
            userInput.push_back(input);
        }
        printMinDifference(userInput,kValue,sum);
    }
}

#endif /* MAXDIFF_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
