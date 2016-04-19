/****************************************************************************************************************************************************
 *  File Name                   : cdmn1602.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/contest/codemania2016/cdmn1602.h
 *  Created on                  : Feb 22, 2016 :: 9:26:37 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/COMA2016/problems/CDMN1602
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_CODEMANIA2016_CDMN1602_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_CODEMANIA2016_CDMN1602_H_

void solveProblem() {
    unsigned int testCases,size;
    long long int input,mValue,total;
    vector<long long int> fUserInput,sUserInput;
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%u",&size);
        fUserInput.clear();
        sUserInput.clear();
        for(unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld",&input);
            fUserInput.push_back(input);
        }
        for(unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld",&input);
            sUserInput.push_back(input);
        }
        scanf("%lld",&mValue);
        sort(sUserInput.begin(),sUserInput.end());
        total = 0;
        if(mValue != 0) {
            for(unsigned int counter = 0; counter < size; counter++) {
                if(fUserInput[counter] != 0 && ((float)mValue/(float)fUserInput[counter] == mValue/fUserInput[counter])) {
                    if(binary_search(sUserInput.begin(),sUserInput.end(),mValue/fUserInput[counter])) {
                        total++;
                    }
                }
            }
        } else {
            long long int zerosCount;
            for(unsigned int counter = 0; counter < size; counter++) {
                if(fUserInput[counter] == 0) {
                    zerosCount++;
                }
                if(sUserInput[counter] == 0) {
                    zerosCount++;
                }
            }
            total += zerosCount * size;
        }
        printf("%lld\n",total);
    }
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_CODEMANIA2016_CDMN1602_H_ */
