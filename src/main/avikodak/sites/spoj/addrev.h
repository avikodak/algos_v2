/****************************************************************************************************************************************************
 *  File Name   		: addrev.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\spoj\addrev.h
 *  Created on			: Feb 3, 2015 :: 11:01:42 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.spoj.com/problems/ADDREV/
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

#ifndef ADDREV_H_
#define ADDREV_H_

//Tested
int reverseNumber(int userInput){
	int reversedNumber = 0;
	while(userInput > 0 && userInput%10 == 0){
		userInput /= 10;
	}
	while(userInput > 0){
		reversedNumber = (((reversedNumber << 3) + (reversedNumber << 1)) + userInput%10);
		userInput /= 10;
	}
	return reversedNumber;
}

//Tested
void printAddRev(int firstUserInput,int secondUserInput){
	firstUserInput = reverseNumber(firstUserInput);
	secondUserInput = reverseNumber(secondUserInput);
	printf("%d\n",reverseNumber(firstUserInput+secondUserInput));
}


#endif /* ADDREV_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
