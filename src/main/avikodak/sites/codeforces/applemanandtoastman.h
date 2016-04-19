/****************************************************************************************************************************************************
 *  File Name                   : applemanandtoastman.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\applemanandtoastman.h
 *  Created on                  : Apr 8, 2015 :: 9:57:50 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://codeforces.com/problemset/status#
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

#ifndef APPLEMANANDTOASTMAN_H_
#define APPLEMANANDTOASTMAN_H_

unsigned int getVectorSum(vector<unsigned int> userInput,unsigned int startIndex,unsigned int endIndex) {
    unsigned int sum = 0;
    for(unsigned int counter = startIndex; counter <= endIndex; counter++) {
        sum += userInput[counter];
    }
    return sum;
}

unsigned int getSumDivideStep(vector<unsigned int> userInput,unsigned int startIndex,unsigned int endIndex) {
    if(startIndex > endIndex) {
        return 0;
    }
    if(startIndex == endIndex) {
        return userInput[startIndex];
    }
    long long int sum = getVectorSum(userInput,startIndex,endIndex);
    sum += getSumDivideStep(userInput,startIndex,endIndex-1);
    sum += getSumDivideStep(userInput,endIndex,endIndex);
    return sum;
}

bool compare(unsigned int first,unsigned int second) {
    return first > second?true:false;
}

void getTotalSum() {
    unsigned int testCases,input;
    vector<unsigned int> userInput;
    cin >> testCases;
    while(testCases--) {
        cin >> input;
        userInput.push_back(input);
    }
    sort(userInput.begin(),userInput.end(),compare);
    cout << getSumDivideStep(userInput,0,userInput.size()-1);
}

#endif /* APPLEMANANDTOASTMAN_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
