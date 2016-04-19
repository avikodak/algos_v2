/****************************************************************************************************************************************************
 *  File Name                   : sbank.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/spoj/sbank.h
 *  Created on                  : 22-Sep-2015 :: 5:39:47 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.spoj.com/problems/SBANK/
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

#ifndef SBANK_H_
#define SBANK_H_

//Tested
void printResults() {
    int testCases,size;
    string input;
    vector<string> userInput;
    map<string,unsigned int> presenceMap;
    getline(cin,input);
    testCases = atoi(input.c_str());
    while(testCases--) {
        getline(cin,input);
        userInput.clear();
        size = atoi(input.c_str());
        presenceMap.clear();
        while(size--) {
            getline(cin,input);
            if(presenceMap.find(input) == presenceMap.end()) {
                userInput.push_back(input);
                presenceMap[input] = 1;
            } else {
                presenceMap[input]++;
            }
        }
        getline(cin,input);
        sort(userInput.begin(),userInput.end());
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            cout << userInput[counter] << " " << presenceMap[userInput[counter]] << endl;
        }
        cout << endl;
    }
}

#endif /* SBANK_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
