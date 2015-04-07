/****************************************************************************************************************************************************
 *  File Name   		: learnfrommath.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\learnfrommath.h
 *  Created on			: Mar 1, 2015 :: 7:04:56 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/472/A
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

#ifndef LEARNFROMMATH_H_
#define LEARNFROMMATH_H_

bool isNumberPrime(unsigned int userInput){
	if(userInput < 2){
		return false;
	}
	unsigned int root = sqrt(userInput);
	for(unsigned int counter = 2;counter <= root;counter++){
		if(userInput%counter == 0){
			return false;
		}
	}
	return true;
}

void printSumUsingComposites(){
	unsigned int userInput;
	scanf("%u",&userInput);
	for(unsigned int counter = userInput-2;counter >= 0;counter--){
		if(isNumberPrime(counter) && isNumberPrime(userInput-counter)){
			printf("%u %u",counter,userInput-counter);
			return;
		}
	}
}

#endif /* LEARNFROMMATH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/