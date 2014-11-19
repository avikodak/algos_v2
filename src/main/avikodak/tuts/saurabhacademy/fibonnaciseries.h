/****************************************************************************************************************************************************
 *  File Name   		: fibonnaciseries.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\fibonnaciseries.h
 *  Created on			: Oct 18, 2014 :: 12:33:46 PM
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/trieutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef FIBONNACISERIES_H_
#define FIBONNACISERIES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int getNthTermInFibonacci(unsigned int nValue){
	if(n == 0){
		return 0;
	}
	if(n == 1 || n == 2){
		return 1;
	}
	unsigned int lastValue = 1,lastSecondValue = 1,currentValue,temp;
	for(unsigned int counter = 3;counter <= nValue;counter++){
		temp = currentValue;
		currentValue = lastSecondValue + lastValue;
		lastSecondValue = lastValue;
		lastValue = temp;
	}
	return currentValue;
}

unsigned int getNthTermInFibonnaciDP(unsigned int nValue){
	if(nValue == 0){
		return 0;
	}
	static int fbValues[1024] = {0};
	fbValues[1] = 1;
	fbValues[2] = 1;
	if(fbValues[nValue] != 0){
		return fbValues;
	}
	if(fbValues[nValue-1] == 0){
		fbValues[nValue-1] = getNthTermInFibonnaciDP(nValue-1);
	}
	if(fbValues[nValue-2] == 0){
		fbValues[nValue-2] = getNthTermInFibonnaciDP(nValue-2);
	}
	fbValues[nValue] = fbValues[nValue-1] + fbValues[nValue-2];
	return fbValues[nValue];
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int getNthTermInFibonacciRecursion(unsigned int nValue){
	if(n == 0){
		return 0;
	}
	if(n == 1 || n == 2){
		return 1;
	}
	return getNthTermInFibonacciRecursion(nValue-1) + getNthTermInFibonacciRecursion(nValue-2);
}

#endif /* FIBONNACISERIES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
