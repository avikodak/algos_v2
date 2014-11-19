/****************************************************************************************************************************************************
 *  File Name   		: permutation.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\permutation.h
 *  Created on			: Oct 29, 2014 :: 10:22:41 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
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

#ifndef PERMUTATION_H_
#define PERMUTATION_H_

//Tested
void printPermutation(char *userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex == endIndex){
		printf("%s",userInput);
		PRINT_NEW_LINE;
		return;
	}
	for(unsigned int counter = startIndex;counter <= endIndex;counter++){
		swap(userInput[startIndex],userInput[counter]);
		printPermutation(userInput,startIndex+1,endIndex);
		swap(userInput[startIndex],userInput[counter]);
	}
}

//Tested
void permutationOfVector(vector<int> userInput,unsigned int startIndex){
	if(startIndex == userInput.size()){
		printIVector(userInput,false);
		PRINT_NEW_LINE;
		return;
	}
	for(unsigned int counter = startIndex;counter < userInput.size();counter++){
		swap(userInput[startIndex],userInput[counter]);
		permutationOfVector(userInput,startIndex+1);
		swap(userInput[startIndex],userInput[counter]);
	}
}

#endif /* PERMUTATION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
