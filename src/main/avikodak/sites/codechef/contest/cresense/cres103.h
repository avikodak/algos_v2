/****************************************************************************************************************************************************
 *  File Name                   : cres103.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/contest/cresense/cres103.h
 *  Created on                  : Feb 18, 2016 :: 9:27:06 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/CRES2016/problems/CRES103
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_CRESENSE_CRES103_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_CRESENSE_CRES103_H_

//Tested
void solveProblem() {
    unsigned int testCases,size;
    long long int input,sum,totalTriplets;
    vector<long long int> userInput;
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%u",&size);
        userInput.clear();
        for(unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld",&input);
            userInput.push_back(input);
        }
        scanf("%lld",&sum);
        totalTriplets = 0;
        for(unsigned int outerCrawler = 0; outerCrawler < userInput.size()-2; outerCrawler++) {
            for(unsigned int innerCrawler = outerCrawler+1; innerCrawler < userInput.size()-1; innerCrawler++) {
                for(unsigned int counter = innerCrawler+1; counter < userInput.size(); counter++) {
                    if(userInput[outerCrawler]+userInput[innerCrawler]+userInput[counter] < sum) {
                        totalTriplets++;
                    }
                }
            }
        }
        printf("%lld\n",totalTriplets);
    }
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_CRESENSE_CRES103_H_ */
