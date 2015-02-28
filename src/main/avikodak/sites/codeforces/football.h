/****************************************************************************************************************************************************
 *  File Name   		: football.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\football.h
 *  Created on			: Feb 28, 2015 :: 1:11:19 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/96/A
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

#ifndef FOOTBALL_H_
#define FOOTBALL_H_

//Tested
void isCombinationDangerous(){
	char *ptrToUserInput,userInput[MAX_INPUT_SIZE];
	scanf("%s",userInput);
	unsigned int frequency;
	bool isDangerous = false;
	ptrToUserInput = userInput;
	while(ptrToUserInput[0] != '\0'){
		frequency = 1;
		while(ptrToUserInput[1] != '\0' && ptrToUserInput[0] == ptrToUserInput[1]){
			ptrToUserInput++;
			frequency++;
			if(frequency >= 7){
				isDangerous = true;
				break;
			}
		}
		if(isDangerous){
			break;
		}
		ptrToUserInput++;
	}
	printf("%s",isDangerous?"YES":"NO");
}

#endif /* FOOTBALL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
