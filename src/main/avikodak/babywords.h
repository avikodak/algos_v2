/****************************************************************************************************************************************************
 *  File Name                   : babywords.h
 *  File Location               : \algos_v2\src\main\avikodak\babywords.h
 *  Created on                  : Feb 4, 2015 :: 12:56:40 PM
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

#ifndef BABYWORDS_H_
#define BABYWORDS_H_

bool existsInDictionary(vector<string> baby_words,string userInput) {
    for(unsigned int counter = 0; counter < baby_words.size(); counter++) {
        if(baby_words[counter].compare(userInput) == 0) {
            return true;
        }
    }
    return false;
}

bool doesExists(vector<string> baby_words,queue<string> breakedWords,string garbled_text) {
    if(garbled_text.size() == 0) {
        while(!breakedWords.empty()) {
            cout << breakedWords.front() + " ";
            breakedWords.pop();
        }
        return true;
    }
    int counter = 1;
    while(counter <= garbled_text.size()) {
        string subString = garbled_text.substr(0,counter);
        if(existsInDictionary(baby_words,subString)) {
            breakedWords.push(subString);
            if(doesExists(baby_words,breakedWords,garbled_text.substr(counter,garbled_text.size() - (counter)))) {
                return true;
            }
            breakedWords.pop();
        }
        counter++;
    }
    return false;
}

void findBabyWords(vector < string > baby_words, string garbled_text) {
    queue<string> auxSpace;
    doesExists(baby_words,auxSpace,garbled_text);
}

#endif /* BABYWORDS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
