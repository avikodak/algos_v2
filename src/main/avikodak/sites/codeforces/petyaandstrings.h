/****************************************************************************************************************************************************
 *  File Name   		: petyaandstrings.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\petyaandstrings.h
 *  Created on			: Feb 28, 2015 :: 8:59:23 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/112/A
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

#ifndef PETYAANDSTRINGS_H_
#define PETYAANDSTRINGS_H_

//Tested
void petyaStringComparison(){
	char firstUserInput[CODEFORCES_MAX_INPUT_SIZE],secondUserInput[CODEFORCES_MAX_INPUT_SIZE],*ptrToFirstUserInput,*ptrToSecondUserInput;
	scanf("%s %s",firstUserInput,secondUserInput);
	ptrToFirstUserInput = firstUserInput;
	ptrToSecondUserInput = secondUserInput;
	while(ptrToFirstUserInput[0] != '\0'){
		if(ptrToFirstUserInput[0] >= 'A' && ptrToFirstUserInput[0] <= 'Z'){
			ptrToFirstUserInput[0] = ptrToFirstUserInput[0] - 'A' + 'a';
		}
		if(ptrToSecondUserInput[0] >= 'A' && ptrToSecondUserInput[0] <= 'Z'){
			ptrToSecondUserInput[0] = ptrToSecondUserInput[0] - 'A' + 'a';
		}
		if(ptrToFirstUserInput[0] > ptrToSecondUserInput[0]){
			printf("1");
			return;
		}else if(ptrToFirstUserInput[0] < ptrToSecondUserInput[0]){
			printf("-1");
			return;
		}
		ptrToFirstUserInput++;
		ptrToSecondUserInput++;
	}
	printf("0");
}

#endif /* PETYAANDSTRINGS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
