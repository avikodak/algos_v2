/****************************************************************************************************************************************************
 *  File Name                   : wdtbam.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/contest/octoberchallenge2015/wdtbam.h
 *  Created on                  : 12-Oct-2015 :: 12:10:00 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/OCT15/problems/WDTBAM
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

#ifndef WDTBAM_H_
#define WDTBAM_H_

//Tested
void printResults() {
    unsigned int testCases,size,input,rightAnsCount;
    scanf("%u",&testCases);
    string rightAns,ans;
    vector<unsigned int> weights;
    unsigned int result;
    while(testCases--) {
        scanf("%u",&size);
        cin >> rightAns >> ans;
        weights.clear();
        for(unsigned int counter = 0; counter <= size; counter++) {
            scanf("%u",&input);
            weights.push_back(input);
        }
        result = weights[0];
        rightAnsCount = 0;
        for(unsigned int counter = 0; counter < size; counter++) {
            if(ans[counter] == rightAns[counter]) {
                rightAnsCount++;
            }
        }
        if(rightAnsCount == ans.length()) {
            result = weights[ans.length()];
        } else {
            for(unsigned int counter = 0; counter <= rightAnsCount; counter++) {
                result = max(result,weights[counter]);
            }
        }
        printf("%u\n",result);
    }
}


#endif /* WDTBAM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
