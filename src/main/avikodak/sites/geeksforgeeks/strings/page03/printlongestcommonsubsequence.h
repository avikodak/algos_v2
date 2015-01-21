/****************************************************************************************************************************************************
 *  File Name   		: printlongestcommonsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page03\printlongestcommonsubsequence.h
 *  Created on			: Jan 20, 2015 :: 7:32:09 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/printing-longest-common-subsequence/
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

#ifndef PRINTLONGESTCOMMONSUBSEQUENCE_H_
#define PRINTLONGESTCOMMONSUBSEQUENCE_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
//This prints the subsequence in reverse
void printLongestCommonSubsequence(char *firstUserInput,char *secondUserInput,int firstStringLength,int secondStringLength){
	if(firstStringLength == 0 || secondStringLength == 0){
		return;
	}
	vector<vector<int> > auxSpace(firstStringLength+1);
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		auxSpace[counter].assign(secondStringLength+1,0);
	}
	for(unsigned int outerCrawler = 1;outerCrawler < auxSpace.size();outerCrawler++){
		for(unsigned int innerCrawler = 1;innerCrawler < auxSpace[0].size();innerCrawler++){
			if(firstUserInput[outerCrawler-1] == secondUserInput[innerCrawler-1]){
				auxSpace[outerCrawler][innerCrawler] = 1 + auxSpace[outerCrawler-1][innerCrawler-1];
			}else{
				auxSpace[outerCrawler][innerCrawler] = max(auxSpace[outerCrawler-1][innerCrawler],auxSpace[outerCrawler][innerCrawler-1]);
			}
		}
	}
	int firstCrawler = auxSpace.size()-1,secondCrawler = auxSpace[0].size()-1;
	while(firstCrawler > 0 && secondCrawler > 0 && auxSpace[firstCrawler][secondCrawler] > 0){
		if(firstUserInput[firstCrawler-1] == secondUserInput[secondCrawler-1]){
			printf("%c",firstUserInput[firstCrawler-1]);
			firstCrawler -= 1;
			secondCrawler -= 1;
		}else{
			if(auxSpace[firstCrawler-1][secondCrawler] > auxSpace[firstCrawler][secondCrawler-1]){
				firstCrawler -= 1;
			}else{
				secondCrawler -= 1;
			}
		}
	}
}

#endif /* PRINTLONGESTCOMMONSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
