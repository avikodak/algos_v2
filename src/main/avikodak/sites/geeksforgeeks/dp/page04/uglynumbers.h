/****************************************************************************************************************************************************
 *  File Name   		: uglynumbers.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\uglynumbers.h
 *  Created on			: Dec 5, 2014 :: 12:33:47 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/ugly-numbers/
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

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef UGLYNUMBERS_H_
#define UGLYNUMBERS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getUglyNumber(int userInput){
	if(userInput == 1){
		return 1;
	}
	vector<int> uglyNumbers;
	uglyNumbers.push_back(1);
	int twoPtr = 0,threePtr = 0,fivePtr = 0;
	int nextUglyNumber;
	userInput -= 1;
	while(userInput--){
		nextUglyNumber = min(uglyNumbers[twoPtr] * 2,uglyNumbers[threePtr] *3,uglyNumbers[fivePtr] *5);
		if(nextUglyNumber == uglyNumbers[twoPtr] * 2){
			twoPtr++;
		}
		if(nextUglyNumber == uglyNumbers[threePtr] * 3){
			threePtr++;
		}
		if(nextUglyNumber == uglyNumbers[fivePtr] * 5){
			fivePtr++;
		}
		uglyNumbers.push_back(nextUglyNumber);
	}
	return uglyNumbers[uglyNumbers.size()-1];
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maxDivide(int userInput,int divideBy){
	if(userInput == 0){
		return 0;
	}
	if(userInput == 1){
		return 1;
	}
	while(userInput%divideBy == 0){
		userInput /= divideBy;
	}
	return userInput;
}

//Tested
bool isUglyNumber(int userInput){
	userInput = maxDivide(userInput,2);
	userInput = maxDivide(userInput,3);
	userInput = maxDivide(userInput,5);
	return userInput == 1;
}

//Tested
int getUglyNumberIterative(int userInput){
	if(userInput < 0){
		return INT_MIN;
	}
	if(userInput == 1){
		return 1;
	}
	userInput -= 1;
	int counter = 2;
	while(userInput--){
		while(true){
			if(!isUglyNumber(counter)){
				counter++;
			}else{
				break;
			}
		}
		counter++;
	}
	return counter-1;
}

#endif /* UGLYNUMBERS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
