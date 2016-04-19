/****************************************************************************************************************************************************
 *  File Name                   : longestsubstringwithoutrepeatingchar.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page05\longestsubstringwithoutrepeatingchar.h
 *  Created on                  : Jan 16, 2015 :: 9:05:23 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
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

#ifndef LONGESTSUBSTRINGWITHOUTREPEATINGCHAR_H_
#define LONGESTSUBSTRINGWITHOUTREPEATINGCHAR_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int longestSubstringWithoutRepeatingCharsON(char *userInput) {
    if(userInput == null || userInput[0] == '\0') {
        return 0;
    }
    hash_map<char,unsigned int> charIndexMap;
    hash_map<char,unsigned int>::iterator itToCharIndexMap;
    int maxLength = 0,currentLength = 0;
    for(unsigned int counter = 0; counter < strlen(userInput); counter++) {
        itToCharIndexMap = charIndexMap.find(userInput[counter]);
        if(itToCharIndexMap == charIndexMap.end() || itToCharIndexMap->second < counter - currentLength) {
            currentLength++;
        } else {
            maxLength = max(maxLength,currentLength);
            currentLength = counter - itToCharIndexMap->second;
        }
        charIndexMap[userInput[counter]] = counter;
    }
    return maxLength;
}

//Tested
int longestSubstringWithoutRepeatingCharsONV2(char *userInput) {
    if(userInput == null || userInput[0] == '\0') {
        return 0;
    }
    hash_map<char,unsigned int> charIndexMap;
    hash_map<char,unsigned int>::iterator itToCharIndexMap;
    int maxLength = 0;
    unsigned int startIndex = 0;
    for(unsigned int counter = 0; counter < strlen(userInput); counter++) {
        itToCharIndexMap = charIndexMap.find(userInput[counter]);
        if(itToCharIndexMap != charIndexMap.end() && itToCharIndexMap->second >= startIndex) {
            maxLength = max(maxLength,(int)(counter - startIndex));
            startIndex = itToCharIndexMap->second + 1;
        }
        charIndexMap[userInput[counter]] = counter;
    }
    return maxLength;
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/

#endif /* LONGESTSUBSTRINGWITHOUTREPEATINGCHAR_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
