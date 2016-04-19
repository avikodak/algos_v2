/****************************************************************************************************************************************************
 *  File Name                   : largestcontigoussubarray.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\largestcontigoussubarray.h
 *  Created on                  : Jan 20, 2015 :: 11:02:25 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/
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

#ifndef LARGESTCONTIGOUSSUBARRAY_H_
#define LARGESTCONTIGOUSSUBARRAY_H_

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int lengthOfLargestContigousSubArrayON2(vector<int> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    int maxVal,minVal,maxLength = INT_MIN;
    for(int outerCounter = 0; outerCounter < (int)userInput.size()-1; outerCounter++) {
        maxVal = userInput[outerCounter];
        minVal = userInput[outerCounter];
        for(int innerCounter = outerCounter+1; innerCounter < (int)userInput.size(); innerCounter++) {
            maxVal = max(maxVal,userInput[innerCounter]);
            minVal = min(minVal,userInput[innerCounter]);
            if(maxVal - minVal == innerCounter - outerCounter) {
                maxLength = max(maxLength,innerCounter - outerCounter + 1);
            }
        }
    }
    return maxLength;
}


/****************************************************************************************************************************************************/
/*                                                                 O(N^3) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool isVectorContigous(vector<int> userInput) {
    if(userInput.size() == 0) {
        return true;
    }
    for(unsigned int counter = 1; counter < userInput.size(); counter++) {
        if(userInput[counter] - userInput[counter-1] != 1) {
            return false;
        }
    }
    return true;
}

//Tested
int lengthOfLargestContigousSubArray(vector<int> userInput) {
    if(userInput.size() < 2) {
        return userInput.size();
    }
    vector<int> auxSpace;
    int maxLength = INT_MIN;
    for(unsigned int outerCrawler = 0; outerCrawler < userInput.size(); outerCrawler++) {
        auxSpace.clear();
        for(unsigned int innerCrawler = outerCrawler; innerCrawler < userInput.size(); innerCrawler++) {
            auxSpace.push_back(userInput[innerCrawler]);
            sort(auxSpace.begin(),auxSpace.end());//Insertion sort works better
            if(isVectorContigous(auxSpace)) {
                maxLength = max(maxLength,(int)auxSpace.size());
            }
        }
    }
    return maxLength;
}

#endif /* LARGESTCONTIGOUSSUBARRAY_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
