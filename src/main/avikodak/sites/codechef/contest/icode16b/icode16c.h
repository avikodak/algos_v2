/****************************************************************************************************************************************************
 *  File Name                   : icode16c.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/contest/icode16b/icode16c.h
 *  Created on                  : Feb 18, 2016 :: 1:03:08 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/ICOD2016/problems/ICODE16C
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
#define MODN 1000000007

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_ICODE16B_ICODE16C_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_ICODE16B_ICODE16C_H_

//Tested
struct alphaBeta {
    long long int alphaValue;
    long long int betaValue;

    alphaBeta(long long int alphaValue,long long int betaValue) {
        this->alphaValue = alphaValue;
        this->betaValue = betaValue;
    }
};

//Tested
void solveProblem() {
    unsigned int testCases;
    long long int input,alphaValue,betaValue;
    scanf("%u",&testCases);
    vector<alphaBeta *> memoization;
    memoization.push_back(new alphaBeta(1,0));
    memoization.push_back(new alphaBeta(0,1));
    memoization.push_back(new alphaBeta(2,1));
    while(testCases--) {
        scanf("%lld",&input);
        if(input >= memoization.size()) {
            for(long long int counter = memoization.size(); counter <= input; counter++) {
                alphaValue = (memoization[counter-1]->alphaValue%MODN + memoization[counter-2]->alphaValue%MODN + memoization[counter-3]->alphaValue%MODN)%MODN;
                betaValue = (memoization[counter-1]->betaValue%MODN + memoization[counter-2]->betaValue%MODN + memoization[counter-3]->betaValue%MODN)%MODN;
                memoization.push_back(new alphaBeta(alphaValue,betaValue));
            }
        }
        printf("%lld %lld\n",memoization[input]->alphaValue,memoization[input]->betaValue);
    }
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_ICODE16B_ICODE16C_H_ */
