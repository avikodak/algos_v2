/****************************************************************************************************************************************************
 *  File Name   		: nearlyluckynumber.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\nearlyluckynumber.h
 *  Created on			: Mar 1, 2015 :: 10:39:07 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/110/A
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

#ifndef NEARLYLUCKYNUMBER_H_
#define NEARLYLUCKYNUMBER_H_

//Tested
bool isNumberLucky(long long int userInput){
	if(userInput == 0){
		return false;
	}
	long long int lastDigit;
	while(userInput > 0){
		lastDigit = userInput%10;
		if(lastDigit != 4 && lastDigit != 7){
			return false;
		}
		userInput /= 10;
	}
	return true;
}

//Tested
void isNumberNearlyLuckyNumber(){
	long long int userInput,lastDigit,luckyDigitCounter = 0;
	cin >> userInput;
	while(userInput > 0){
		lastDigit = userInput%10;
		if(lastDigit == 4 || lastDigit == 7){
			luckyDigitCounter++;
		}
		userInput /= 10;
	}
	if(isNumberLucky(luckyDigitCounter)){
		printf("YES");
	}else{
		printf("NO");
	}
}

#endif /* NEARLYLUCKYNUMBER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
