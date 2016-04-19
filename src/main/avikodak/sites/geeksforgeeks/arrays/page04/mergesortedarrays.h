/****************************************************************************************************************************************************
 *  File Name                   : mergesortedarrays.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/arrays/page04/mergesortedarrays.h
 *  Created on                  : Jan 24, 2016 :: 10:34:45 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/merge-one-array-of-size-n-into-another-one-of-size-mn/
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
#define NA -1

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_MERGESORTEDARRAYS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_MERGESORTEDARRAYS_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
void mergeSortedArray(int fUserInput[],int fSize,int sUserInput[],int sSize) {
    if(fSize == 0 || sSize == 0) {
        return;
    }
    int fillIndex = -1,fRearCrawler,sRearCrawler;
    for(unsigned int counter = 0; counter < fSize; counter++) {
        if(fUserInput[counter] != NA) {
            fUserInput[++fillIndex] = fUserInput[counter];
        }
    }
    fRearCrawler = fillIndex;
    sRearCrawler = sSize-1;
    fillIndex = fSize;
    while(fRearCrawler >= 0 || sRearCrawler >= 0) {
        if(fRearCrawler < 0 || sRearCrawler < 0) {
            if(fRearCrawler >= 0) {
                fUserInput[--fillIndex] = fUserInput[fRearCrawler--];
            } else {
                fUserInput[--fillIndex] = sUserInput[sRearCrawler--];
            }
        } else {
            if(fUserInput[fRearCrawler] > sUserInput[sRearCrawler]) {
                fUserInput[--fillIndex] = fUserInput[fRearCrawler--];
            } else {
                fUserInput[--fillIndex] = sUserInput[sRearCrawler--];
            }
        }
    }
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void mergeSortedArrayONLOGN(int fUserInput[],int fSize,int sUserInput[],int sSize) {
    if(fSize == 0 || sSize == 0) {
        return;
    }
    unsigned int sFillIndex = 0;
    for(unsigned int counter = 0; counter < fSize; counter++) {
        if(fUserInput[counter] == NA && sFillIndex < sSize) {
            fUserInput[counter] = sUserInput[sFillIndex++];
        }
    }
    sort(fUserInput,fUserInput+fSize);
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_MERGESORTEDARRAYS_H_ */
