/****************************************************************************************************************************************************
 *  File Name   		: runlengthencoding.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page04\runlengthencoding.h
 *  Created on			: Dec 4, 2014 :: 6:36:08 PM
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/
#define RUN_LENGTH_ENCODING_MAX_DIGIT_COUNT 5

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef RUNLENGTHENCODING_H_
#define RUNLENGTHENCODING_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
char *runLengthEncoding(char *userInput) {
    if(userInput == null) {
        return null;
    }
    char *encodedString = (char *)malloc(sizeof(char)*(2*strlen(userInput)+1));
    int frequency;
    int fillCounter = -1;
    int innerCounter = 0;
    char countInChar[RUN_LENGTH_ENCODING_MAX_DIGIT_COUNT];
    while(*userInput != '\0') {
        frequency = 1;
        while(userInput[1] != '\0' && userInput[0] == userInput[1]) {
            frequency++;
            userInput++;
        }
        encodedString[++fillCounter] = userInput[0];
        sprintf(countInChar,"%d",frequency);
        for(innerCounter = 0; countInChar[innerCounter] != '\0'; innerCounter++) {
            encodedString[++fillCounter] = countInChar[innerCounter];
        }
        userInput++;
    }
    return encodedString;
}

#endif /* RUNLENGTHENCODING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
