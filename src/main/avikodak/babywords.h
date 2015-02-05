/****************************************************************************************************************************************************
 *  File Name   		: babywords.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\babywords.h
 *  Created on			: Feb 4, 2015 :: 12:56:40 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef BABYWORDS_H_
#define BABYWORDS_H_

bool existsInDictionary(vector<string> baby_words,string userInput){
    for(unsigned int counter = 0;counter < baby_words.size();counter++){
        if(baby_words[counter].compare(userInput) == 0){
            return true;
        }
    }
    return false;
}

bool doesExists(vector<string> baby_words,queue<string> breakedWords,string garbled_text){
    if(garbled_text.size() == 0){
        while(!breakedWords.empty()){
            cout << breakedWords.front() + " ";
            breakedWords.pop();
        }
        return true;
    }
    int counter = 1;
    while(counter <= garbled_text.size()){
        string subString = garbled_text.substr(0,counter);
        if(existsInDictionary(baby_words,subString)){
            breakedWords.push(subString);
            if(doesExists(baby_words,breakedWords,garbled_text.substr(counter,garbled_text.size() - (counter)))){
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
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
