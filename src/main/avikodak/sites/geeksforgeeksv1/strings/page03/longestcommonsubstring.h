/****************************************************************************************************************************************************
 *  File Name                   : longestcommonsubstring.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page03\longestcommonsubstring.h
 *  Created on                  : Jan 20, 2015 :: 7:44:24 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/longest-common-substring/
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef LONGESTCOMMONSUBSTRING_H_
#define LONGESTCOMMONSUBSTRING_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int longestCommonSubstring(char *firstUserInput,char *secondUserInput,int firstStringLength,int secondStringLength) {
    if(firstStringLength == 0 || secondStringLength == 0) {
        return 0;
    }
    vector<vector<int> > auxSpace(firstStringLength+1);
    for(unsigned int counter = 0; counter < auxSpace.size(); counter++) {
        auxSpace[counter].assign(secondStringLength+1,0);
    }
    int maxLength = INT_MIN;
    for(int outerCrawler = 1; outerCrawler <= firstStringLength; outerCrawler++) {
        for(int innerCrawler = 1; innerCrawler <= secondStringLength; innerCrawler++) {
            if(firstUserInput[outerCrawler-1] == secondUserInput[innerCrawler-1]) {
                auxSpace[outerCrawler][innerCrawler] = 1 + auxSpace[outerCrawler-1][innerCrawler-1];
                maxLength = max(maxLength,auxSpace[outerCrawler][innerCrawler]);
            }
        }
    }
    return maxLength;
}

#endif /* LONGESTCOMMONSUBSTRING_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
