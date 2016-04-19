/****************************************************************************************************************************************************
 *  File Name   		: chatroom.h
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\chatroom.h
 *  Created on			: Mar 3, 2015 :: 7:37:38 AM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/58/A
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

#ifndef CHATROOM_H_
#define CHATROOM_H_

//Tested
void doesVasyaSayHello() {
    char userInput[CODEFORCES_MAX_INPUT_SIZE],*ptrToUserInput;
    char pattern[] = "hello",*ptrToPattern;
    scanf("%s",userInput);
    ptrToPattern = pattern;
    ptrToUserInput = userInput;
    while(ptrToUserInput[0] != '\0' && ptrToPattern[0] != '\0') {
        if(ptrToUserInput[0] == ptrToPattern[0]) {
            ptrToPattern++;
        }
        ptrToUserInput++;
    }
    printf("%s",ptrToPattern[0] == '\0'?"YES":"NO");
}

#endif /* CHATROOM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
