/****************************************************************************************************************************************************
 *  File Name   		: longestpalindromicsubstring.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page04\longestpalindromicsubstring.h
 *  Created on			: Jan 16, 2015 :: 10:59:39 AM
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

#ifndef LONGESTPALINDROMICSUBSTRING_H_
#define LONGESTPALINDROMICSUBSTRING_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int longestPalindromicSubstring(char *userInput){
	if(userInput[0] == '\0'){
		return 0;
	}
	int length = strlen(userInput);
	vector<vector<bool> > auxSpace(length);
	for(unsigned int counter = 0;counter < length;counter++){
		auxSpace[counter].assign(length,false);
		auxSpace[counter][counter] = true;
	}
	unsigned int innerCrawler;
	int maxLength = INT_MIN;
	for(unsigned int lengthCounter = 2;lengthCounter <= length;lengthCounter++){
		for(unsigned int outerCrawler = 0;outerCrawler < length - lengthCounter+1;outerCrawler++){
			if(length == 2){
				auxSpace[outerCrawler][innerCrawler] = userInput[outerCrawler] == userInput[innerCrawler];
			}else{
				auxSpace[outerCrawler][innerCrawler] = userInput[outerCrawler] == userInput[innerCrawler] && auxSpace[outerCrawler+1][innerCrawler-1];
			}
			if(auxSpace[outerCrawler][innerCrawler]){
				maxLength = max(maxLength,innerCrawler - outerCrawler + 1);
			}
		}
	}
	return maxLength;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(2^N) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* LONGESTPALINDROMICSUBSTRING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
