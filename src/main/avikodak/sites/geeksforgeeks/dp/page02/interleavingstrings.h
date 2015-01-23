/****************************************************************************************************************************************************
 *  File Name   		: interleavingstrings.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page02\interleavingstrings.h
 *  Created on			: Jan 12, 2015 :: 4:09:13 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings-set-2/
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

#ifndef INTERLEAVINGSTRINGS_H_
#define INTERLEAVINGSTRINGS_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isStringInterleavedMemoization(char *firstString,char *secondString,char *thirdString){
	if(firstString[0] == '\0' && secondString[0] == '\0' && thirdString[0] == '\0'){
		return true;
	}
	int firstStringLength = strlen(firstString);
	int secondStringLength = strlen(secondString);
	int thirdStringLength = strlen(thirdString);
	vector<vector<bool> > auxSpace(firstString+1);
	for(unsigned int counter = 0;counter <= firstStringLength;counter++){
		auxSpace[counter].assign(secondStringLength+1,false);
	}
	for(unsigned int outerCounter = 0;outerCounter <= firstStringLength;outerCounter++){
		for(unsigned int innerCounter = 0;innerCounter <= secondStringLength;innerCounter++){
			if(outerCounter == 0 && innerCounter == 0){
				auxSpace[outerCounter][innerCounter] = true;
			}else if(outerCounter == 0 && secondString[innerCounter-1] == thirdString[innerCounter-1]){
				auxSpace[outerCounter][innerCounter] = auxSpace[outerCounter-1][innerCounter];
			}else if(innerCounter == 0 && firstString[innerCounter] == thirdString[innerCounter-1]){
				auxSpace[outerCounter][innerCounter] = auxSpace[outerCounter][innerCounter-1];
			}else if(firstString[outerCounter] == thirdString[outerCounter + innerCounter - 1]  && secondString[innerCounter] != thirdString[outerCounter+innerCounter-1]){
				auxSpace[outerCounter][innerCounter] = auxSpace[outerCounter-1][innerCounter];
			}else if(firstString[outerCounter] != thirdString[outerCounter + innerCounter - 1]  && secondString[innerCounter] == thirdString[outerCounter+innerCounter-1]){
				auxSpace[outerCounter][innerCounter] = auxSpace[outerCounter][innerCounter-1];
			}else{
				auxSpace[outerCounter][innerCounter] = auxSpace[outerCounter][innerCounter-1] || auxSpace[outerCounter-1][innerCounter];
			}
		}
	}
	return auxSpace[firstStringLength-1][secondStringLength-1];
}

/****************************************************************************************************************************************************/
/* 																O(2^N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isStringInterleaved(char *firstString,char *secondString,char *thirdString){
	if(firstString[0] == '\0' && secondString[0] == '\0' && thirdString[0] == '\0'){
		return true;
	}
	if(thirdString[0] == '\0'){
		return false;
	}
	bool truthValue = false;
	if(firstString[0] != '\0'){
		truthValue = truthValue || (thirdString[0] == firstString[0] && isStringInterleaved(firstString+1,secondString,thirdString+1));
	}
	if(secondString[0]  != '\0'){
		truthValue = truthValue || (thirdString[0] == secondString[0] && isStringInterleaved(firstString,secondString+1,thirdString+1));
	}
	return truthValue;
}

#endif /* INTERLEAVINGSTRINGS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
