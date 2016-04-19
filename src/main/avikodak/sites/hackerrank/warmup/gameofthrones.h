/****************************************************************************************************************************************************
 *  File Name                   : gameofthrones.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\hackerrank\warmup\gameofthrones.h
 *  Created on                  : Feb 5, 2015 :: 8:48:27 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/game-of-thrones
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
#define LOWERCASE_ENG_ALPHABET_SIZE 26
/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef GAMEOFTHRONES_H_
#define GAMEOFTHRONES_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool palindromePermutation(string userInput) {
    if(userInput.size() == 0) {
        return true;
    }
    int frequencies[LOWERCASE_ENG_ALPHABET_SIZE] = {0};
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        frequencies[userInput[counter]-'a'] += 1;
    }
    int oddFrequency = 0;
    for(unsigned int counter = 0; counter < LOWERCASE_ENG_ALPHABET_SIZE; counter++) {
        if(frequencies[counter]%2 == 1) {
            oddFrequency++;
        }
    }
    return oddFrequency <= 1;
}

#endif /* GAMEOFTHRONES_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
