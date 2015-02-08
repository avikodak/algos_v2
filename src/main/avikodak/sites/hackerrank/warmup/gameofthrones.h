/****************************************************************************************************************************************************
 *  File Name   		: gameofthrones.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\warmup\gameofthrones.h
 *  Created on			: Feb 5, 2015 :: 8:48:27 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: https://www.hackerrank.com/challenges/game-of-thrones
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
#define LOWERCASE_ENG_ALPHABET_SIZE 26
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef GAMEOFTHRONES_H_
#define GAMEOFTHRONES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool palindromePermutation(string userInput){
	if(userInput.size() == 0){
		return true;
	}
	int frequencies[LOWERCASE_ENG_ALPHABET_SIZE] = {0};
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		frequencies[userInput[counter]-'a'] += 1;
	}
	int oddFrequency = 0;
	for(unsigned int counter = 0;counter < LOWERCASE_ENG_ALPHABET_SIZE;counter++){
		if(frequencies[counter]%2 == 1){
			oddFrequency++;
		}
	}
	return oddFrequency <= 1;
}

#endif /* GAMEOFTHRONES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
