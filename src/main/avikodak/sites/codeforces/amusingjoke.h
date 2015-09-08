/****************************************************************************************************************************************************
 *  File Name   		: amusingjoke.h 
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\amusingjoke.h
 *  Created on			: Mar 23, 2015 :: 10:10:48 PM
 *  Author				: avikodak
 *  Testing Status 		: TODO
 *  URL 				: http://codeforces.com/problemset/problem/141/A
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

#ifndef AMUSINGJOKE_H_
#define AMUSINGJOKE_H_

void areStringPermutations(){
	char firstUserInput[CODEFORCES_MAX_INPUT_SIZE],secondUserInput[CODEFORCES_MAX_INPUT_SIZE];
	char thirdUserInput[CODEFORCES_MAX_INPUT_SIZE];
	scanf("%s %s %s",firstUserInput,secondUserInput,thirdUserInput);
	int frequency[26] = {0};
	unsigned int firstStringLength = strlen(firstUserInput),secondStringLength = strlen(secondUserInput),thirdStringLength = strlen(thirdUserInput);
	for(unsigned int counter = 0;counter < firstStringLength;counter++){
		frequency[firstUserInput[counter] - 'A']++;
	}
	for(unsigned int counter = 0;counter < secondStringLength;counter++){
		frequency[secondUserInput[counter] - 'A']++;
	}
	for(unsigned int counter = 0;counter < thirdStringLength;counter++){
		if(frequency[thirdUserInput[counter] - 'A'] == 0){
			printf("NO");
			return;
		}
		frequency[thirdUserInput[counter] - 'A']--;
	}
	for(unsigned int counter = 0;counter < 26;counter++){
		if(frequency[counter] != 0){
			printf("NO");
			return;
		}
	}
	printf("YES");
}


#endif /* AMUSINGJOKE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
