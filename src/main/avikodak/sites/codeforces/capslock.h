/****************************************************************************************************************************************************
 *  File Name   		: capslock.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\capslock.h
 *  Created on			: Feb 28, 2015 :: 12:43:09 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/131/A
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
#define MAX_INPUT_SIZE 101

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef CAPSLOCK_H_
#define CAPSLOCK_H_

//Tested
bool testForUpperCase(char *userInput){
	while(userInput[0] != '\0'){
		if(userInput[0] < 'A' || userInput[0] > 'Z'){
			return false;
		}
		userInput++;
	}
	return true;
}

//Tested
void printLetterCase(char *userInput){
	while(userInput[0] != '\0'){
		if(userInput[0] >= 'A' && userInput[0] <= 'Z'){
			printf("%c",userInput[0] - 'A' + 'a');
		}else{
			printf("%c",userInput[0] - 'a' + 'A');
		}
		userInput++;
	}
	printf("\n");
}

//Tested
void printChangedCase(){
	char userInput[MAX_INPUT_SIZE];
	scanf("%s",userInput);
	if(userInput[0] >= 'A' && userInput[0] <= 'Z'){
		if(testForUpperCase(userInput)){
			printLetterCase(userInput);
		}else{
			printf("%s\n",userInput);
		}
	}else if(userInput[0] >= 'a' && userInput[0] <= 'z'){
		if(testForUpperCase(userInput+1)){
			printLetterCase(userInput);
		}else{
			printf("%s\n",userInput);
		}

	}
}

#endif /* CAPSLOCK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
