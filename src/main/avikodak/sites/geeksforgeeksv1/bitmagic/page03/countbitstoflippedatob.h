/****************************************************************************************************************************************************
 *  File Name   		: countbitstoflippedatob.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\bitmagic\page03\countbitstoflippedatob.h
 *  Created on			: Jan 9, 2015 :: 9:36:55 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/
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

#ifndef COUNTBITSTOFLIPPEDATOB_H_
#define COUNTBITSTOFLIPPEDATOB_H_

//Tested
int countBitsToFlipAToB(int firstUserInput,int secondUserInput) {
    int xorResult = firstUserInput ^ secondUserInput;
    int counter;
    while(xorResult > 0) {
        xorResult &= (xorResult - 1);
        counter++;
    }
    return counter;
}

//Tested
int countBitsToFlipAToBCounter(int firstUserInput,int secondUserInput) {
    int counter = 0;
    while(firstUserInput > 0 && secondUserInput > 0) {
        counter += (firstUserInput & 1) ^ (secondUserInput & 1);
        firstUserInput = firstUserInput >> 1;
        secondUserInput = secondUserInput >> 1;
    }
    while(firstUserInput > 0) {
        counter += firstUserInput & 1;
        firstUserInput = firstUserInput >> 1;
    }
    while(secondUserInput > 0) {
        counter += secondUserInput & 1;
        secondUserInput = secondUserInput >> 1;
    }
    return counter;
}

#endif /* COUNTBITSTOFLIPPEDATOB_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
