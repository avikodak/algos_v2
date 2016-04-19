/****************************************************************************************************************************************************
 *  File Name                   : arestringsanagrams.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page04\arestringsanagrams.h
 *  Created on                  : Jan 16, 2015 :: 10:06:56 AM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : TODO
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

#ifndef ARESTRINGSANAGRAMS_H_
#define ARESTRINGSANAGRAMS_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
bool areStringsAnagramsON(char *firstUserInput,char *secondUserInput) {
    if(firstUserInput == '\0' && secondUserInput == '\0') {
        return true;
    }
    int firstLength = strlen(firstUserInput),secondLength = strlen(secondUserInput);
    if(firstLength != secondLength) {
        return false;
    }
    hash_map<char,unsigned int> frequencyMap;
    hash_map<char,unsigned int>::iterator itToFrequencyMap;
    for(unsigned int counter = 0; counter < firstLength; counter++) {
        if((itToFrequencyMap = frequencyMap.find(firstUserInput[counter])) == frequencyMap.end()) {
            frequencyMap[firstUserInput[counter]] = 1;
        } else {
            frequencyMap[firstUserInput[counter]] += 1;
        }
    }
    for(unsigned int counter = 0; counter < secondLength; counter++) {
        if((itToFrequencyMap = frequencyMap.find(secondUserInput[counter])) == frequencyMap.end()) {
            return false;
        }
        if(itToFrequencyMap->second == 1) {
            frequencyMap.erase(secondUserInput[counter]);
        } else {
            itToFrequencyMap->second -= 1;
        }
    }
    return frequencyMap.size() == 0;
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
bool areStringsAnagramONLOGN(char *firstUserInput,char *secondUserInput) {
    if(firstUserInput == '\0' && secondUserInput == '\0') {
        return true;
    }
    char *firstCrawler = firstUserInput,*secondCrawler = secondUserInput;
    while(firstCrawler[0] != '\0' && secondCrawler[0] != '\0') {
        if(firstCrawler[0] != secondCrawler[0]) {
            return false;
        }
        firstCrawler++;
        secondCrawler++;
    }
    return firstCrawler[0] == '\0' && secondCrawler[0] == '\0';
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/


#endif /* ARESTRINGSANAGRAMS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
