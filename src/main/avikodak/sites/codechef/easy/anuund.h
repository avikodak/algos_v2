/****************************************************************************************************************************************************
 *  File Name                   : anuund.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\anuund.h
 *  Created on                  : Aug 30, 2015 :: 1:18:11 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/ANUUND
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

#ifndef ANUUND_H_
#define ANUUND_H_

//Tested
void waveSort(vector<unsigned int> userInput) {
    if(userInput.size() == 0) {
        return;
    }
    sort(userInput.begin(),userInput.end());
    for(unsigned int counter = 1; counter < userInput.size()-1; counter+=2) {
        swap(userInput[counter],userInput[counter+1]);
    }
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        cout << userInput[counter] << " ";
    }
    cout << endl;
}

//Tested
void printResults() {
    unsigned int testCases,size,input;
    scanf("%u",&testCases);
    vector<unsigned int> userInput;
    while(testCases--) {
        scanf("%u",&size);
        userInput.clear();
        while(size--) {
            scanf("%u",&input);
            userInput.push_back(input);
        }
        waveSort(userInput);
    }
}

#endif /* ANUUND_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
