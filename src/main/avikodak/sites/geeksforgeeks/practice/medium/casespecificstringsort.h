/****************************************************************************************************************************************************
 *  File Name                   : casespecificstringsort.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/medium/casespecificstringsort.h
 *  Created on                  : Jan 31, 2016 :: 1:19:25 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=331
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_CASESPECIFICSTRINGSORT_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_CASESPECIFICSTRINGSORT_H_

//Tested
void solveProblem() {
    unsigned int testCases,size;
    long long int input;
    vector<long long int> userInput;
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%u",&size);
        userInput.clear();
        string upperCase,lowerCase;
        while(size--) {
            scanf("%lld",&input);
            userInput.push_back(input);
        }
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(userInput[counter] >= 'A' && userInput[counter] <= 'Z') {
                upperCase.push_back(userInput[counter]);
            } else {
                lowerCase.push_back(userInput[counter]);
            }
        }
        sort(lowerCase.begin(),lowerCase.end());
        sort(upperCase.begin(),upperCase.end());
        unsigned int lowerCaseIndex = 0,upperCaseIndex = 0;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(userInput[counter] >= 'A' && userInput[counter] <= 'Z') {
                userInput[counter] = upperCase[upperCaseIndex++];
            } else {
                userInput[counter] = lowerCase[lowerCaseIndex++];
            }
        }
        cout << userInput << endl;
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_MEDIUM_CASESPECIFICSTRINGSORT_H_ */
