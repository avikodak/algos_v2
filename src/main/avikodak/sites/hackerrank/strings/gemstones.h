/****************************************************************************************************************************************************
 *  File Name   		: gemstones.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\strings\gemstones.h
 *  Created on			: Feb 13, 2015 :: 9:17:08 AM
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

#ifndef GEMSTONES_H_
#define GEMSTONES_H_

//Tested
void printLettersInAllGemStones() {
    long int testSize;
    string userInput;
    scanf("%ld",&testSize);
    vector<bool> flags;
    vector<long int> alphaCounter(26,0);
    for(long int counter = 0; counter < testSize; counter++) {
        cin >> userInput;
        flags.clear();
        flags.assign(26,false);
        for(unsigned int strCounter = 0; strCounter < userInput.size(); strCounter++) {
            if(!flags[userInput[strCounter]-'a']) {
                flags[userInput[strCounter]-'a'] = true;
                alphaCounter[userInput[strCounter]-'a'] += 1;
            }
        }
    }
    int total = 0;
    for(unsigned int counter = 0; counter < 26; counter++) {
        if(alphaCounter[counter] == testSize) {
            total+=1;
        }
    }
    printf("%d",total);
}

#endif /* GEMSTONES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
