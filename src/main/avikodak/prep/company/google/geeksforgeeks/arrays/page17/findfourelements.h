/****************************************************************************************************************************************************
 *  File Name                   : findfourelements.h
 *  File Location               : /algos_v2/src/main/avikodak/prep/company/google/geeksforgeeks/arrays/page17/findfourelements.h
 *  Created on                  : Mar 6, 2017 :: 11:17:49 AM
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

#ifndef MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_ARRAYS_PAGE17_FINDFOURELEMENTS_H_
#define MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_ARRAYS_PAGE17_FINDFOURELEMENTS_H_

struct iQuadruple {
    int firstValue;
    int secondValue;
    int thirdValue;
    int fourthValue;
 public:
    iQuadruple() {
        this->firstValue = INT_MIN;
        this->secondValue = INT_MIN;
        this->thirdValue = INT_MIN;
        this->fourthValue = INT_MIN;
    }

    iQuadruple(int firstValue, int secondValue, int thirdValue, int fourthValue) {
        this->firstValue = firstValue;
        this->secondValue = secondValue;
        this->thirdValue = thirdValue;
        this->fourthValue = fourthValue;
    }
};

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^3) Algorithm                                                                       */
/****************************************************************************************************************************************************/
//Assuming the values are distinct
iQuadruple *getQuadrupleForSumON3(vector<int> userInput, int sum) {
    if (userInput.size() < 4) {
        return null;
    }
    hash_map<int, int> frequencyMap;
    hash_map<int, int>::iterator itToFrequencyMap;
    int frequencyForValue;
    for (unsigned int crawler = 0; crawler < userInput.size(); crawler++) {
        if ((itToFrequencyMap = frequencyMap.find(userInput[crawler])) == frequencyMap.end()) {
            frequencyMap.insert(pair<int, int>(userInput[crawler], 1));
        } else {
            frequencyForValue = itToFrequencyMap->second;
            frequencyMap.insert(pair<int, int>(userInput[crawler], frequencyForValue++));
        }
    }
    int currentSum;
    for (unsigned int firstCrawler = 0; firstCrawler < userInput.size() - 2; firstCrawler++) {
        for (unsigned int secondCrawler = firstCrawler + 1; secondCrawler < userInput.size() - 1; secondCrawler++) {
            for (unsigned int thirdCrawler = secondCrawler + 1; thirdCrawler < userInput.size(); thirdCrawler++) {
                currentSum = userInput[firstCrawler] + userInput[secondCrawler] + userInput[thirdCrawler];
                if ((itToFrequencyMap = frequencyMap.find(sum - currentSum)) != frequencyMap.end()) {
                    return new iQuadruple(userInput[firstCrawler], userInput[secondCrawler], userInput[thirdCrawler], sum - currentSum);
                }
            }
        }
    }
    return null;
}

/****************************************************************************************************************************************************/
/*                                                           O(N^4) Algorithm                                                                       */
/****************************************************************************************************************************************************/
iQuadruple *getQuadrupleForSumON4(vector<int> userInput, int sum) {
    if (userInput.size() < 4) {
        return null;
    }
    for (unsigned int firstCrawler = 0; firstCrawler < userInput.size() - 3; firstCrawler++) {
        for (unsigned int secondCrawler = firstCrawler + 1; secondCrawler < userInput.size() - 2; secondCrawler++) {
            for (unsigned int thirdCrawler = secondCrawler + 1; thirdCrawler < userInput.size() - 1; thirdCrawler++) {
                for (unsigned int fourthCrawler = thirdCrawler + 1; fourthCrawler < userInput.size(); fourthCrawler++) {
                    if (userInput[firstCrawler] + userInput[secondCrawler] + userInput[thirdCrawler] + userInput[fourthCrawler] == sum) {
                        return new iQuadruple(userInput[firstCrawler], userInput[secondCrawler], userInput[thirdCrawler], userInput[fourthCrawler]);
                    }
                }
            }
        }
    }
    return null;
}
#endif /* MAIN_AVIKODAK_PREP_COMPANY_GOOGLE_GEEKSFORGEEKS_ARRAYS_PAGE17_FINDFOURELEMENTS_H_ */
