/****************************************************************************************************************************************************
 *  File Name                   : ct03.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/peer/ct03.h
 *  Created on                  : Feb 14, 2016 :: 10:07:26 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/CT03
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_PEER_CT03_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_PEER_CT03_H_

//Tested
void solveProblem() {
    unsigned int testCases;
    long long int noOfErasers,noOfPencils;
    string userInput;
    scanf("%u",&testCases);
    while(testCases--) {
        cin >> userInput;
        noOfErasers = 0;
        noOfPencils = 0;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            if(userInput[counter] == 'E') {
                noOfErasers++;
            } else {
                noOfPencils++;
            }
        }
        printf("%lld %lld\n",min(noOfErasers,noOfPencils),abs(noOfErasers-noOfPencils));
    }
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_PEER_CT03_H_ */
