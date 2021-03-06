/****************************************************************************************************************************************************
 *  File Name                   : maxlengthwithoutrepeating.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\maxlengthwithoutrepeating.h
 *  Created on                  : Jan 13, 2015 :: 8:17:43 PM
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

#ifndef MAXLENGTHWITHOUTREPEATING_H_
#define MAXLENGTHWITHOUTREPEATING_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
int maxLengthWithoutRepeatingON(char *userInput) {
    if(userInput == null || userInput[0] == '\0') {
        return 0;
    }
    int length = strlen(userInput);
    int maxLength = INT_MIN,currentLength = 0;
    hash_map<char,int> charIndexMap;
    hash_map<char,int>::iterator itToCharIndexMap;
    for(int counter = 0; counter < length; counter++) {
        if((itToCharIndexMap = charIndexMap.find(userInput[counter])) == charIndexMap.end() || itToCharIndexMap->second < counter - currentLength) {
            currentLength++;
        } else {
            //printf("%d\t",currentLength);
            maxLength = max(maxLength,currentLength);
            currentLength = counter - itToCharIndexMap->second;
        }
        charIndexMap[userInput[counter]] = counter;
    }
    return maxLength;
}

#endif /* MAXLENGTHWITHOUTREPEATING_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
