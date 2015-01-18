/****************************************************************************************************************************************************
 *  File Name   		: nextgreaternumbersetdigits.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\nextgreaternumbersetdigits.h
 *  Created on			: Jan 18, 2015 :: 9:53:02 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-next-greater-number-set-digits/
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

#ifndef NEXTGREATERNUMBERSETDIGITS_H_
#define NEXTGREATERNUMBERSETDIGITS_H_

//Tested
vector<char> nextGreaterNumberSetDigits(vector<char> userInput){
	if(userInput.size() < 2){
		return userInput;
	}
	int outerCounter,innerCounter;
	for(outerCounter = userInput.size() - 2;outerCounter >= 0;outerCounter--){
		if(userInput[outerCounter] < userInput[outerCounter+1]){
			break;
		}
	}
	if(outerCounter < 0){
		return userInput;
	}
	int minDigit = INT_MIN;
	for(innerCounter = userInput.size()-1;innerCounter > outerCounter;innerCounter--){
		if(userInput[innerCounter] > userInput[outerCounter]){
			if(minDigit == INT_MIN){
				minDigit = innerCounter;
			}else{
				if(userInput[minDigit] > userInput[innerCounter]){
					minDigit = innerCounter;
				}
			}
		}
	}
	swap(userInput[outerCounter],userInput[minDigit]);
	sort(userInput.begin()+outerCounter+1,userInput.end());
	return userInput;
}

#endif /* NEXTGREATERNUMBERSETDIGITS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
