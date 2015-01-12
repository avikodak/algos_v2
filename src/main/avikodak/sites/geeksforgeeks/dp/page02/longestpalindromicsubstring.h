/****************************************************************************************************************************************************
 *  File Name   		: longestpalindromicsubstring.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page02\longestpalindromicsubstring.h
 *  Created on			: Dec 15, 2014 :: 3:23:43 PM
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

#ifndef LONGESTPALINDROMICSUBSTRING_H_
#define LONGESTPALINDROMICSUBSTRING_H_


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int longestPalindromicSubSequenceON2(char *userInput,int length){
	if(userInput == null || length == 0){
		return 0;
	}
	vector<vector<bool> > auxSpace(length);
	int maxLength = 1;
	for(unsigned int counter = 0;counter < length;counter++){
		auxSpace[counter].assign(length,false);
		auxSpace[counter][counter] = true;
	}
	for(unsigned int counter = 0;counter < length - 1;counter++){
		if(userInput[counter] == userInput[counter+1]){
			auxSpace[counter][counter+1] = true;
			maxLength = 2;
		}
	}
	for(int rowCounter = length-1;rowCounter >= 0;rowCounter--){
		for(int columnCounter = rowCounter+1;columnCounter < length;length++){
			if(userInput[rowCounter] == userInput[columnCounter] && auxSpace[rowCounter+1][columnCounter-1]){
				maxLength = max(maxLength,columnCounter - rowCounter + 1);
			}
		}
	}
	return maxLength;
}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
int isSubStringPalindrome(char *userInput,int start,int length){
	int startCrawler = start,endCrawler = start + length - 1;
	while(startCrawler < endCrawler){
		if(userInput[startCrawler] != userInput[endCrawler]){
			return false;
		}
		startCrawler++;
		endCrawler--;
	}
	return true;
}

int longestPalindromicSubstring(char *userInput,unsigned int size){
	if(userInput == null){
		return 0;
	}
	int maxLength = INT_MIN;
	for(unsigned int outerCrawler = 0;outerCrawler < size;outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler;innerCrawler < size;innerCrawler++){
			if(isSubStringPalindrome(userInput,outerCrawler,innerCrawler)){
				maxLength = max(maxLength,(int)(innerCrawler - outerCrawler + 1));
			}
		}
	}
	return maxLength;
}

#endif /* LONGESTPALINDROMICSUBSTRING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
