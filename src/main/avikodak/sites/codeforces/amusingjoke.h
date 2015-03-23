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
