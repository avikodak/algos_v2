/****************************************************************************************************************************************************
 *  File Name                   : wordbreak.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page02\wordbreak.h
 *  Created on                  : Jan 12, 2015 :: 7:05:51 PM
 *  Author                      : avikodak
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

#ifndef WORDBREAK_H_
#define WORDBREAK_H_

bool checkWordDictionary(string word) {
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for(unsigned int counter = 0; counter < size; counter++) {
        if(word.compare(dictionary[counter]) == 0) {
            return true;
        }
    }
    return false;
}

bool wordBreakMain(string userInput) {
    if(userInput.size() == 0) {
        return false;
    }
    for(unsigned int lengths = 1; lengths <= userInput.size(); lengths++) {
        if(checkWordDictionary(userInput.substr(0,lengths)) && wordBreakMain(userInput.substr(lengths,userInput.size() - lengths))) {
            return true;
        }
    }
    return false;
}

bool wordBreakDP(string userInput) {
    if(userInput.size() == 0) {
        return true;
    }
    vector<bool> auxSpace(userInput.size()+1,false);
    for(unsigned int lengthCounter = 1; lengthCounter <= userInput.size(); lengthCounter++) {
        if(!auxSpace[lengthCounter] && checkWordDictionary(userInput.substr(0,lengthCounter))) {
            auxSpace[lengthCounter] = true;
        }
        if(auxSpace[lengthCounter]) {
            for(unsigned int innerCounter = lengthCounter+1; innerCounter <= userInput.size(); innerCounter++) {
                if(!auxSpace[innerCounter] && checkWordDictionary(userInput.substr(lengthCounter,innerCounter-lengthCounter))) {
                    auxSpace[innerCounter] = true;
                }
                if(innerCounter == userInput.size() && auxSpace[innerCounter]) {
                    return true;
                }
            }
        }
    }
    return false;
}

#endif /* WORDBREAK_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
