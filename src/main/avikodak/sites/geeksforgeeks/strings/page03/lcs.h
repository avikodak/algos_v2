/****************************************************************************************************************************************************
 *  File Name   		: lcs.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page03\lcs.h
 *  Created on			: Jan 16, 2015 :: 11:59:06 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
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

#ifndef LCS_H_
#define LCS_H_

//Tested
int longestCommonSubSequence(char firstUserInput[],char secondUserInput[],int firstCurrentIndex,int secondCurrentIndex){
	if(firstCurrentIndex < 0 || secondCurrentIndex < 0){
		return 0;
	}
	if(firstUserInput[firstCurrentIndex] == secondUserInput[secondCurrentIndex]){
		return 1 + longestCommonSubSequence(firstUserInput,secondUserInput,firstCurrentIndex-1,secondCurrentIndex-1);
	}else{
		return max(longestCommonSubSequence(firstUserInput,secondUserInput,firstCurrentIndex-1,secondCurrentIndex),longestCommonSubSequence(firstUserInput,secondUserInput,firstCurrentIndex,secondCurrentIndex-1));
	}
}

//Tested
int longestCommonSubSequenceMemoization(char firstUserInput[],char secondUserInput[],int firstStringLength,int secondStringLength){
	if(firstStringLength == 0 || secondStringLength == 0){
		return 0;
	}
	vector<vector<int> > auxSpace(firstStringLength+1);
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		auxSpace[counter].assign(secondStringLength+1,0);
	}
	for(int outerCrawler = 1;outerCrawler <= firstStringLength;outerCrawler++){
		for(int innerCrawler = 1;innerCrawler <= secondStringLength;innerCrawler++){
			if(firstUserInput[outerCrawler-1] == secondUserInput[innerCrawler-1]){
				auxSpace[outerCrawler][innerCrawler] = 1 + auxSpace[outerCrawler-1][innerCrawler-1];
			}else{
				auxSpace[outerCrawler][innerCrawler] = max(auxSpace[outerCrawler-1][innerCrawler],auxSpace[outerCrawler][innerCrawler-1]);
			}
		}
	}
	return auxSpace[auxSpace.size()-1][auxSpace[0].size()-1];
}

#endif /* LCS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/