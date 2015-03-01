/****************************************************************************************************************************************************
 *  File Name   		: boyorgirl.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\boyorgirl.h
 *  Created on			: Mar 1, 2015 :: 9:52:09 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/236/A
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
#define ALPHABET_SIZE 26

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef BOYORGIRL_H_
#define BOYORGIRL_H_

//Tested
void isUserBoyOrGirl(){
	char userInput[CODEFORCES_MAX_INPUT_SIZE],*ptrToUserInput;
	scanf("%s",userInput);
	bool flags[ALPHABET_SIZE] = {false};
	unsigned int uniqueCharCount = 0;
	ptrToUserInput = userInput;
	while(ptrToUserInput[0] != '\0'){
		flags[ptrToUserInput[0]-'a'] = true;
		ptrToUserInput++;
	}
	for(unsigned int counter = 0;counter < ALPHABET_SIZE;counter++){
		if(flags[counter]){
			uniqueCharCount++;
		}
	}
	if(uniqueCharCount&1){
		printf("IGNORE HIM!");
	}else{
		printf("CHAT WITH HER!");
	}
}


#endif /* BOYORGIRL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
