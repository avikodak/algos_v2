/****************************************************************************************************************************************************
 *  File Name   		: lexicographicpermutation.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page04\lexicographicpermutation.h
 *  Created on			: Jan 20, 2015 :: 5:47:34 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/lexicographic-permutations-of-string/
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

#ifndef LEXICOGRAPHICPERMUTATION_H_
#define LEXICOGRAPHICPERMUTATION_H_

//Tested
void printLexicographicPermutation(vector<char> userInput){
	if(userInput.size() == 0){
		return;
	}
	sort(userInput.begin(),userInput.end());
	int outerCounter,innerCounter;
	while(true){
		printCVector(userInput);
		PRINT_NEW_LINE;
		for(outerCounter = userInput.size()-2;outerCounter >= 0;outerCounter--){
			if(userInput[outerCounter] < userInput[outerCounter+1]){
				break;
			}
		}
		if(outerCounter < 0){
			break;
		}
		for(innerCounter = userInput.size()-1;innerCounter > outerCounter;innerCounter--){
			if(userInput[innerCounter] > userInput[outerCounter]){
				break;
			}
		}
		swap(userInput[outerCounter],userInput[innerCounter]);
		sort(userInput.begin()+outerCounter+1,userInput.end());
	}
}

#endif /* LEXICOGRAPHICPERMUTATION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
