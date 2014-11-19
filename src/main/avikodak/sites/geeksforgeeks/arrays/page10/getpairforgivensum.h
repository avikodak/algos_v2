/****************************************************************************************************************************************************
 *  File Name   		: getpairforgivensum.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\getpairforgivensum.h
 *  Created on			: Oct 10, 2014 :: 4:13:13 PM
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/trieutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef GETPAIRFORGIVENSUM_H_
#define GETPAIRFORGIVENSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
iPair *getPairForGivenSum(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	hash_map<int,unsigned int> frequencyMap = getFrequencyMapFromVector(userInput);
	hash_map<int,unsigned int> itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(sum - userInput[counter])) != frequencyMap.end()){
			iPair *result = new iPair();
			result->firstValue = userInput[counter];
			result->secondValue = sum - userInput[counter];
			return result;
		}
	}
	return null;
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
iPair *getPairForGivenSum(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int frontCrawler = 0,rearCrawler = userInput.size()-1;
	int currentSum;
	while(frontCrawler < rearCrawler){
		currentSum = userInput[frontCrawler] + userInput[rearCrawler];
		if(currentSum == sum){
			iPair *result = new iPair();
			result->firstValue = userInput[frontCrawler];
			result->secondValue = userInput[rearCrawler];
			return result;
		}
		if(currentSum > sum){
			rearCrawler--;
		}else{
			frontCrawler++;
		}
 	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
iPair *getPairForGivenSumON2(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] + userInput[innerCrawler] == sum){
				iPair *result = new iPair();
				result->firstValue = userInput[outerCrawler];
				result->secondValue = userInput[innerCrawler];
				return result;
			}
		}
	}
}

iPair *getPairForGivenSumBST(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	treeutils *utils = new treeutils();
	itNode *rootBST = utils->getBSTFromVector(userInput);
	itNode *temp;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		temp = utils->searchForValueBST(rootBST,sum-userInput[counter]);
		if(temp != null){
			iPair *result = new iPair();
			result->firstValue = userInput[counter];
			result->secondValue = sum - userInput[counter];
			return result;
		}
	}
	return null;
}

#endif /* GETPAIRFORGIVENSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
