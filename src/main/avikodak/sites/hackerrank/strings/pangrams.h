/****************************************************************************************************************************************************
 *  File Name   		: pangrams.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\strings\pangrams.h
 *  Created on			: Feb 12, 2015 :: 8:51:55 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PANGRAMS_H_
#define PANGRAMS_H_

//Tested
void isStringPangram() {
    string userInput;
    getline(cin, userInput);
    vector<bool> flags(26,false);
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] >= 'a' && userInput[counter] <= 'z') {
            flags[userInput[counter] - 'a'] = true;
        } else if(userInput[counter] >= 'A' && userInput[counter] <= 'Z') {
            flags[userInput[counter] - 'A'] = true;
        }
    }

    bool allAlphaUsed = true;
    for(unsigned int counter = 0; counter < flags.size(); counter++) {
        if(!flags[counter]) {
            allAlphaUsed = false;
            break;
        }

    }
    printf("%s",allAlphaUsed?"pangram":"not pangram");
}

#endif /* PANGRAMS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
