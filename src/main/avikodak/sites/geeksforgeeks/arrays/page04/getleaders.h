/****************************************************************************************************************************************************
 *  File Name                   : getleaders.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/arrays/page04/getleaders.h
 *  Created on                  : Jan 24, 2016 :: 2:45:02 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/leaders-in-an-array/
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_GETLEADERS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_GETLEADERS_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
void printLeaders(int userInput[],int size) {
    if(size == 0) {
        return;
    }
    int maxTillNow = INT_MIN;
    for(int counter = size-1; counter >= 0; counter--) {
        if(userInput[counter] > maxTillNow) {
            printf("%d\t",userInput[counter]);
            maxTillNow = userInput[counter];
        }
    }
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
void printLeadersON2(int userInput[],int size) {
    if(size == 0) {
        return;
    }
    int maxTillNow;
    for(int outerCrawler = size-1; outerCrawler >= 0; outerCrawler--) {
        maxTillNow = userInput[outerCrawler];
        for(int innerCrawler = size-1; innerCrawler > outerCrawler; innerCrawler--) {
            if(userInput[innerCrawler] > maxTillNow) {
                maxTillNow = userInput[innerCrawler];
                break;
            }
        }
        if(maxTillNow == userInput[outerCrawler]) {
            printf("%d\t",maxTillNow);
        }
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_GETLEADERS_H_ */
