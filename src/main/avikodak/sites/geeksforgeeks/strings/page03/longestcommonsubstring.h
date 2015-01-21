/****************************************************************************************************************************************************
 *  File Name   		: longestcommonsubstring.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page03\longestcommonsubstring.h
 *  Created on			: Jan 20, 2015 :: 7:44:24 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/longest-common-substring/
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

#ifndef LONGESTCOMMONSUBSTRING_H_
#define LONGESTCOMMONSUBSTRING_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int longestCommonSubstring(char *firstUserInput,char *secondUserInput,int firstStringLength,int secondStringLength){
	if(firstStringLength == 0 || secondStringLength == 0){
		return 0;
	}
	vector<vector<int> > auxSpace(firstStringLength+1);
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		auxSpace[counter].assign(secondStringLength+1,0);
	}
	int maxLength = INT_MIN;
	for(int outerCrawler = 1;outerCrawler <= firstStringLength;outerCrawler++){
		for(int innerCrawler = 1;innerCrawler <= secondStringLength;innerCrawler++){
			if(firstUserInput[outerCrawler-1] == secondUserInput[innerCrawler-1]){
				auxSpace[outerCrawler][innerCrawler] = 1 + auxSpace[outerCrawler-1][innerCrawler-1];
				maxLength = max(maxLength,auxSpace[outerCrawler][innerCrawler]);
			}
		}
	}
	return maxLength;
}

#endif /* LONGESTCOMMONSUBSTRING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
