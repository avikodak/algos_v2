/****************************************************************************************************************************************************
 *  File Name   		: catalannumbers.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page01\catalannumbers.h
 *  Created on			: Jan 13, 2015 :: 12:40:12 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/program-nth-catalan-number/
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

#ifndef CATALANNUMBERS_H_
#define CATALANNUMBERS_H_

//Tested
int catalanNumber(int number){
	if(number < 2){
		return 1;
	}
	int total = 0;
	for(int counter = 0;counter < number;counter++){
		total += catalanNumber(counter)*catalanNumber(number-counter-1);
	}
	return total;
}

//Tested
int catalanNumberMemoization(int number){
	if(number < 2){
		return 1;
	}
	vector<int> userInput;
	userInput.push_back(1);
	userInput.push_back(1);
	int total;
	for(int outerCounter = 2;outerCounter <= number;outerCounter++){
		total = 0;
		for(int innerCounter = 0;innerCounter < outerCounter;innerCounter++){
			total += userInput[innerCounter] * userInput[outerCounter-innerCounter-1];
		}
		userInput.push_back(total);
	}
	return userInput[userInput.size()-1];
}

#endif /* CATALANNUMBERS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
