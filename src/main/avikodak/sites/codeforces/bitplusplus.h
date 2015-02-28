/****************************************************************************************************************************************************
 *  File Name   		: bitplusplus.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\bitplusplus.h
 *  Created on			: Feb 28, 2015 :: 7:28:16 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/282/A
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
#define MAX_INPUT_SIZE 4
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef BITPLUSPLUS_H_
#define BITPLUSPLUS_H_

void printPostBitPlusPlusOperation(){
	unsigned int testCases;
	scanf("%u",&testCases);
	char userInput[MAX_INPUT_SIZE];
	int counter = 0;
	while(testCases--){
		scanf("%s",userInput);
		if(userInput[1] == '+'){
			counter++;
		}else{
			counter--;
		}
	}
}

#endif /* BITPLUSPLUS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
