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
