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
