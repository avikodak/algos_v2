/****************************************************************************************************************************************************
 *  File Name                   : reversearray.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/arrays/page04/reversearray.h
 *  Created on                  : Jan 24, 2016 :: 1:52:59 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_REVERSEARRAY_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_REVERSEARRAY_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
void reverseArray(int userInput[],int size) {
    if(size < 2) {
        return;
    }
    unsigned int frontCrawler = 0,rearCrawler = size-1;
    while(frontCrawler < rearCrawler) {
        swap(userInput[frontCrawler++],userInput[rearCrawler--]);
    }
}

void reverseArray(int userInput[],unsigned int frontCrawler,unsigned int rearCrawler) {
    if(frontCrawler > rearCrawler) {
        return;
    }
    swap(userInput[frontCrawler],userInput[rearCrawler]);
    reverseArray(userInput,frontCrawler+1,rearCrawler-1);
}

void reverseArrayAuxSpace(int userInput[],int size) {
    if(size < 2) {
        return;
    }
    stack<int> auxSpace;
    for(unsigned int counter = 0; counter < size; counter++) {
        auxSpace.push(userInput[counter]);
    }
    int temp;
    for(unsigned int counter = 0; counter < size; counter++) {
        temp = auxSpace.top();
        auxSpace.pop();
        userInput[counter] = temp;
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_REVERSEARRAY_H_ */
