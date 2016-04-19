/****************************************************************************************************************************************************
 *  File Name   		: dostringsinterleave.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page04\dostringsinterleave.h
 *  Created on			: Jan 16, 2015 :: 9:31:38 AM
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

#ifndef DOSTRINGSINTERLEAVE_H_
#define DOSTRINGSINTERLEAVE_H_

bool doStringsInterleave(char *firstUserinput,char *secondUserinput,char *thirdUserinput) {
    if(firstUserinput[0] == '\0' && secondUserinput == '\0' && thirdUserinput == '\0') {
        return true;
    }
    if(thirdUserinput[0] == '\0') {
        return false;
    }
    bool truthValue = false;
    if(firstUserinput[0] != '\0') {
        truthValue = truthValue || (firstUserinput[0] == thirdUserinput[0] && doStringsInterleave(firstUserinput+1,secondUserinput,thirdUserinput+1));
    } else {
        truthValue = truthValue || (secondUserinput[0] == thirdUserinput[0] && doStringsInterleave(firstUserinput,secondUserinput+1,thirdUserinput+1));
    }
    return truthValue;
}

#endif /* DOSTRINGSINTERLEAVE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
