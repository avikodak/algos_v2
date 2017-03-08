/****************************************************************************************************************************************************
 *  File Name                   : medianofstream.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/heap/page02/medianofstream.h
 *  Created on                  : Mar 7, 2017 :: 11:06:47 PM
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

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_HEAP_PAGE02_MEDIANOFSTREAM_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_HEAP_PAGE02_MEDIANOFSTREAM_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int getMedian(int value, int effectiveMedian, priority_queue<int> &maxHeap, priority_queue<int> &minHeap) {
    int sizeDifference = maxHeap.size() - minHeap.size();
    switch (sizeDifference) {
        case -1: {
            if (value < effectiveMedian) {
                maxHeap.push(value);
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(value);
            }
            return (maxHeap.top() + minHeap.top()) / 2;
        }
        case 0: {
            if (value < effectiveMedian) {
                maxHeap.push(value);
                return maxHeap.top();
            } else {
                minHeap.push(value);
                return minHeap.top();
            }
        }
        case 1: {
            if (value < effectiveMedian) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                minHeap.push(value);
            } else {
                maxHeap.push(value);
            }
            return (maxHeap.top() + minHeap.top()) / 2;
        }
        default:
            throw ;
    }
}

void printMedianForStream(vector<int> userInput) {
    int effectiveMedia = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, std::less<int> > minHeap;
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("%d\n", getMedian(userInput[counter], effectiveMedia, maxHeap, minHeap));
    }
}
/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_HEAP_PAGE02_MEDIANOFSTREAM_H_ */
