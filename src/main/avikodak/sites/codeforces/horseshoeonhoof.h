/****************************************************************************************************************************************************
 *  File Name   		: horseshoeonhoof.h
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\horseshoeonhoof.h
 *  Created on			: Mar 3, 2015 :: 8:48:53 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/228/A
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

#ifndef HORSESHOEONHOOF_H_
#define HORSESHOEONHOOF_H_

//Tested
void minimumHorseShoeRequired() {
    int userInput[4];
    scanf("%d %d %d %d",&userInput[0],&userInput[1],&userInput[2],&userInput[3]);
    unsigned int shoesRequired = 0;
    for(unsigned int outerCounter = 1; outerCounter < 4; outerCounter++) {
        for(unsigned int innerCounter = 0; innerCounter < outerCounter; innerCounter++) {
            if(userInput[outerCounter] == userInput[innerCounter]) {
                shoesRequired++;
                break;
            }
        }
    }
    printf("%u",shoesRequired);
}

#endif /* HORSESHOEONHOOF_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
