/****************************************************************************************************************************************************
 *  File Name                   : kingship.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/kingship.h
 *  Created on                  : 11-Sep-2015 :: 11:24:14 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/KINGSHIP
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

#ifndef KINGSHIP_H_
#define KINGSHIP_H_

//Tested
void getMinCost(vector<long long int> userInput) {
    long long int minValue = *min_element(userInput.begin(),userInput.end());
    bool flag = false;
    long long int product = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(minValue != userInput[counter] || flag) {
            product += (minValue *userInput[counter]);
        }
        if(minValue == userInput[counter]) {
            flag = true;
        }
    }
    cout << product << endl;
}

//Tested
void printResults() {
    long long int testCases,input,size;
    scanf("%lld",&testCases);
    vector<long long int> userInput;
    while(testCases--) {
        scanf("%lld",&size);
        userInput.clear();
        for(unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld",&input);
            userInput.push_back(input);
        }
        getMinCost(userInput);
    }
}

#endif /* KINGSHIP_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
