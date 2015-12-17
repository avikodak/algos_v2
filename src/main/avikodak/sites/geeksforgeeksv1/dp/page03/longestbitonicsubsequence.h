/****************************************************************************************************************************************************
 *  File Name   		: longestbitonicsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\longestbitonicsubsequence.h
 *  Created on			: Dec 9, 2014 :: 8:03:16 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-set-15-longest-bitonic-subsequence/
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

#ifndef LONGESTBITONICSUBSEQUENCE_H_
#define LONGESTBITONICSUBSEQUENCE_H_

//Tested
vector<int> longestIncreasingSubsequence(vector<int> userInput){
	vector<int> lengths;
	if(userInput.size() == 0){
		return lengths;
	}
	lengths.push_back(1);
	int maxLength;
	for(unsigned int outerCrawler = 1;outerCrawler < userInput.size();outerCrawler++){
		maxLength = 1;
		for(unsigned int innerCrawler = 0;innerCrawler < outerCrawler;innerCrawler++){
			if(userInput[outerCrawler] > userInput[innerCrawler]){
				maxLength = max(maxLength,1+lengths[innerCrawler]);
			}
		}
		lengths.push_back(maxLength);
	}
	return lengths;
}

//Tested
vector<int> longestDecreasingSubsequence(vector<int> userInput){
	vector<int> lengths;
	if(userInput.size() == 0){
		return lengths;
	}
	lengths.assign(userInput.size(),0);
	lengths[lengths.size()-1] = 1;
	int maxLength;
	int fillCounter = lengths.size()-1;
	for(int outerCrawler = userInput.size()-2;outerCrawler >= 0;outerCrawler--){
		maxLength = 0;
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[innerCrawler] < userInput[outerCrawler]){
				maxLength = max(maxLength,lengths[innerCrawler]);
			}
		}
		lengths[--fillCounter] = 1 + maxLength;
	}
	return lengths;
}

//Tested
int longestBitonicSubsequence(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	vector<int> incLengths = longestIncreasingSubsequence(userInput);
	vector<int> decLenghts = longestDecreasingSubsequence(userInput);
	int maxLength = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		maxLength = max(maxLength,incLengths[counter]+decLenghts[counter]-1);
	}
	return maxLength;
}

#endif /* LONGESTBITONICSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
