/****************************************************************************************************************************************************
 *  File Name   		: longestbitonicsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\longestbitonicsubsequence.h
 *  Created on			: Dec 9, 2014 :: 8:03:16 PM
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

#ifndef LONGESTBITONICSUBSEQUENCE_H_
#define LONGESTBITONICSUBSEQUENCE_H_

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
			if(userInput[outerCrawler] >= userInput[innerCrawler]){
				maxLength = max(maxLength,1+lengths[innerCrawler]);
			}
		}
		lengths.push_back(maxLength);
	}
	return lengths;
}

vector<int> longestDecreasingSubsequence(vector<int> userInput){
	vector<int> lengths;
	if(userInput.size() == 0){
		return lengths;
	}
	lengths.reserve(userInput.size());
	lengths[userInput.size()-1] = 1;
	int maxLength;
	for(int outerCrawler = userInput.size()-2;outerCrawler >= 0;outerCrawler--){
		maxLength = 1;
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[innerCrawler] < userInput[outerCrawler]){
				maxLength = max(maxLength,1+userInput[innerCrawler]);
			}
		}
		lengths[outerCrawler] = maxLength;
	}
	return lengths;
}

int longestBitonicSubsequence(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	vector<int> incLengths = longestIncreasingSubsequence(userInput);
	vector<int> decLenghts = longestDecreasingSubsequence(userInput);
	int maxLength = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		maxLength = max(maxLength,1+incLengths[counter]+decLenghts[counter]);
	}
	return maxLength;
}

#endif /* LONGESTBITONICSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
