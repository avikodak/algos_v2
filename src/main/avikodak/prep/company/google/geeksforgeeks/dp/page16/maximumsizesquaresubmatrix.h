/****************************************************************************************************************************************************
 *  File Name                   : maximumsizesquaresubmatrix.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/dp/page16/maximumsizesquaresubmatrix.h
 *  Created on                  : Mar 12, 2017 :: 6:34:29 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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
#include <stdexcept>
#include <limits.h>
#include <stdint.h>
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

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE16_MAXIMUMSIZESQUARESUBMATRIX_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE16_MAXIMUMSIZESQUARESUBMATRIX_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
int maxSizeSqareSubMatrix(vector<vector<int> > userInput) {
    vector<vector<int>> auxSpace(userInput.size());
    int maxValue = 0;
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        auxSpace[counter].resize(userInput[0].size());
    }
    for (unsigned int columnCounter = 0; columnCounter < userInput[0].size(); columnCounter++) {
        auxSpace[0][columnCounter] = userInput[0][columnCounter];
    }
    for (unsigned int rowCounter = 0; rowCounter < userInput.size(); rowCounter++) {
        auxSpace[rowCounter][0] = userInput[rowCounter][0];
    }
    for (unsigned int rowCounter = 1; rowCounter < userInput.size(); rowCounter++) {
        for (unsigned int columnCounter = 1; columnCounter < userInput[rowCounter].size(); columnCounter++) {
            if (userInput[rowCounter][columnCounter] == 1) {
                auxSpace[rowCounter][columnCounter] = 1
                        + min(auxSpace[rowCounter - 1][columnCounter], min(userInput[rowCounter - 1][columnCounter - 1], userInput[rowCounter][columnCounter - 1]));
                maxValue = max(maxValue, auxSpace[rowCounter][columnCounter]);
            }
        }
    }
    return maxValue;
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_DP_PAGE16_MAXIMUMSIZESQUARESUBMATRIX_H_ */
