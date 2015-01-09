/****************************************************************************************************************************************************
 *  File Name   		: countbitstoflippedatob.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\bitmagic\page03\countbitstoflippedatob.h
 *  Created on			: Jan 9, 2015 :: 9:36:55 AM
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

#ifndef COUNTBITSTOFLIPPEDATOB_H_
#define COUNTBITSTOFLIPPEDATOB_H_

int countBitsToFlipAToB(int firstUserInput,int secondUserInput){
	int xorResult = firstUserInput ^ secondUserInput;
	int counter;
	while(xorResult > 0){
		xorResult &= (xorResult - 1);
		counter++;
	}
	return counter;
}

int countBitsToFlipAToBCounter(int firstUserInput,int secondUserInput){
	int counter = 0;
	while(firstUserInput > 0 && secondUserInput > 0){
		firstUserInput = firstUserInput >> 1;
		secondUserInput = secondUserInput >> 1;
		counter += (firstUserInput & 1) ^ (secondUserInput & 1);
	}
	return counter;
}

#endif /* COUNTBITSTOFLIPPEDATOB_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
