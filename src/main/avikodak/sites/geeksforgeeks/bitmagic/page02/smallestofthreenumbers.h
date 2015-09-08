/****************************************************************************************************************************************************
 *  File Name   		: smallestofthreenumbers.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\bitmagic\page02\smallestofthreenumbers.h
 *  Created on			: Jan 9, 2015 :: 12:00:24 PM
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

#ifndef SMALLESTOFTHREENUMBERS_H_
#define SMALLESTOFTHREENUMBERS_H_

unsigned int smallestOfThreeNumbers(unsigned int firstInput,unsigned int secondInput,unsigned int thirdInput){
	unsigned int counter = 0;
	while(firstInput && secondInput && thirdInput){
		counter++;
		firstInput--;
		secondInput--;
		thirdInput--;
	}
	return counter;
}

unsigned int minXY(unsigned int x,unsigned int y){
	return y ^ ((x^y)&-(x-y));
}

unsigned int minXYV2(unsigned int x,unsigned int y){
	return y + ((x-y)&((x-y) >> (sizeof(int)*sizeof(char)-1)));
}

unsigned int smallestOfThreeNumbersBitmagic(unsigned int firstInput,unsigned int secondInput,unsigned int thirdInput){
	return minXY(minXY(firstInput,secondInput),thirdInput);
}

#endif /* SMALLESTOFTHREENUMBERS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
