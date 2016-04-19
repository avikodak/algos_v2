/****************************************************************************************************************************************************
 *  File Name                   : chefsq.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/school/chefsq.h
 *  Created on                  : 09-Sep-2015 :: 10:11:13 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/CHEFSQ
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

#ifndef CHEFSQ_H_
#define CHEFSQ_H_

//Tested
void isSubSequence(vector<unsigned int> firstInput,vector<unsigned int> secondInput) {
    unsigned int firstCounter = 0,secondCounter =0;
    while(firstCounter < firstInput.size() && secondCounter < secondInput.size()) {
        if(firstInput[firstCounter] == secondInput[secondCounter]) {
            secondCounter++;
        }
        firstCounter++;
    }
    printf("%s\n",secondCounter >= secondInput.size()?"Yes":"No");
}

//Tested
void printResults() {
    unsigned int testCases,firstSeqLen,secondSeqLen,input;
    vector<unsigned int> firstUserInput,secondUserInput;
    cin >> testCases;
    while(testCases--) {
        firstUserInput.clear();
        secondUserInput.clear();
        cin >> firstSeqLen;
        for(unsigned int counter = 0; counter < firstSeqLen; counter++) {
            cin >> input;
            firstUserInput.push_back(input);
        }
        cin >> secondSeqLen;
        for(unsigned int counter = 0; counter < secondSeqLen; counter++) {
            cin >> input;
            secondUserInput.push_back(input);
        }
        isSubSequence(firstUserInput,secondUserInput);
    }
}

#endif /* CHEFSQ_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
