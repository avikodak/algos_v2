/****************************************************************************************************************************************************
 *  File Name                   : sncht2.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/peer/sncht2.h
 *  Created on                  : Apr 27, 2016 :: 7:41:12 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SNCHT2
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_PEER_SNCHT2_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_PEER_SNCHT2_H_

//Tested
void solveProblem() {
    unsigned int size, noOfQueries;
    long long int input, leftIndex, rightIndex;
    vector<long long int> userInput, leftSums, rightSums;
    scanf("%u %u", &size, &noOfQueries);
    int runningSum = 0;
    for (unsigned int counter = 0; counter < size; counter++) {
        leftSums.push_back(runningSum);
        scanf("%lld", &input);
        userInput.push_back(input);
        runningSum += input;
    }
    rightSums.assign(size, 0);
    for (int counter = userInput.size() - 2; counter >= 0; counter--) {
        rightSums[counter] = rightSums[counter + 1] + userInput[counter+1];
    }
    while (noOfQueries--) {
        scanf("%lld %lld", &leftIndex, &rightIndex);
        printf("%lld\n", leftSums[leftIndex - 1] + rightSums[rightIndex - 1]);
    }
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_PEER_SNCHT2_H_ */
