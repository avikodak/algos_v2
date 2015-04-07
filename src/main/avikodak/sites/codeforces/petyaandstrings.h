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