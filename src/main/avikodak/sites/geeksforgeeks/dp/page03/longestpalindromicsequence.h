/****************************************************************************************************************************************************
 *  File Name   		: longestpalindromicsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\longestpalindromicsequence.h
 *  Created on			: Dec 15, 2014 :: 9:20:31 AM
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

#ifndef LONGESTPALINDROMICSEQUENCE_H_
#define LONGESTPALINDROMICSEQUENCE_H_

int longestPalindromicSubSequence(char *userInput){
	if(userInput == null){
		return 0;
	}
	int length = strlen(userInput);
	vector<vector<int> > auxSpace(length);
	for(unsigned int diagonalCounter = 0;diagonalCounter < auxSpace.size();diagonalCounter++){
		auxSpace[diagonalCounter].resize(length);
		auxSpace[diagonalCounter][diagonalCounter] = 1;
	}
	for(unsigned int counter = 0;counter < auxSpace.size()-1;counter++){
		if(userInput[counter] == userInput[counter+1]){
			auxSpace[counter][counter+1] = 2;
		}else{
			auxSpace[counter][counter+1] = 1;
		}
	}

	for(int rowCounter = auxSpace.size()-1;rowCounter  >= 0;rowCounter--){
		for(int columnCounter = auxSpace.size()-1;columnCounter > rowCounter;columnCounter--){
			if(userInput[rowCounter] == userInput[columnCounter]){
				auxSpace[rowCounter][columnCounter] = 2 + auxSpace[rowCounter+1][columnCounter-1];
			}else{
				auxSpace[rowCounter][columnCounter] = max(auxSpace[rowCounter+1][columnCounter],auxSpace[rowCounter][columnCounter-1]);
			}
		}
	}
	return auxSpace[0][auxSpace[0].size()-1];
}


int longestPalindromicSubSequence(char *userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		return 1;
	}
	if(endIndex - startIndex == 1){
		return userInput[startIndex] == userInput[endIndex]?2:0;
	}
	if(userInput[startIndex] == userInput[endIndex]){
		return 2 + longestPalindromicSubSequence(userInput,startIndex+1,endIndex-1);
	}else{
		return max(longestPalindromicSubSequence(userInput,startIndex+1,endIndex),longestPalindromicSubSequence(userInput,startIndex,endIndex-1));
	}
}

#endif /* LONGESTPALINDROMICSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
