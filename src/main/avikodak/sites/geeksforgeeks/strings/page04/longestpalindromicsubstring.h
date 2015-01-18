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
