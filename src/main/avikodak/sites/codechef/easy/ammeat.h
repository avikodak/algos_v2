/****************************************************************************************************************************************************
 *  File Name                   : ammeat.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\ammeat.h
 *  Created on                  : Sep 6, 2015 :: 12:00:52 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/AMMEAT
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

#ifndef AMMEAT_H_
#define AMMEAT_H_

//Tested
void printMinPlates(vector<unsigned long long int> userInput,unsigned long long int reqSum) {
    sort(userInput.begin(),userInput.end());
    unsigned long long int sum = 0,total = 0;
    for(int counter = userInput.size()-1; counter >= 0; counter--) {
        sum += userInput[counter];
        total++;
        if(sum >= reqSum) {
            cout << total << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

//Tested
void printResults() {
    unsigned int testCases;
    unsigned long long int size,requiredSum,input;
    vector<unsigned long long int> userInput;
    cin >> testCases;
    while(testCases--) {
        cin >> size >> requiredSum;
        userInput.clear();
        for(unsigned int counter = 0; counter < size; counter++) {
            cin >> input;
            userInput.push_back(input);
        }
        printMinPlates(userInput,requiredSum);
    }
}

#endif /* AMMEAT_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
