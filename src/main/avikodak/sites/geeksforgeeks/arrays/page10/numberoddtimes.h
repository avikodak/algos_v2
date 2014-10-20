/****************************************************************************************************************************************************
 *  File Name   		: numberoddtimes.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\numberoddtimes.h
 *  Created on			: Oct 17, 2014 :: 4:29:56 PM
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
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef NUMBERODDTIMES_H_
#define NUMBERODDTIMES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int numberOccuringOddTimesXOR(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int xorValue = 0;
	for(unsigned int counter =0;counter < userInput.size();counter++){
		xorValue ^= userInput[counter];
	}
	return xorValue;
}

int numberOccuringOddTimesON(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(frequencyMap.find(userInput[counter]) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
		}else{
			frequencyMap[userInput[counter]] = 1;
		}
	}
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second%2 == 1){
			return itToFrequencyMap->first;
		}
	}
	return INT_MIN;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int numberOccuringOddTimesONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int outerCrawler = 0,innerCrawler,frequency;
	while(outerCrawler < userInput.size()){
		innerCrawler = outerCrawler;
		frequency = 0;
		while(innerCrawler < userInput.size() && userInput[innerCrawler] == userInput[outerCrawler]){
			frequency += 1;
			innerCrawler++;
		}
		if(frequency%2 == 1){
			return userInput[outerCrawler];
		}
		outerCrawler += innerCrawler;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int numberOccuringOddTimesON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int outerCrawler,innerCrawler,frequency;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		frequency = 0;
		for(innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[innerCrawler] == userInput[outerCrawler]){
				frequency++;
			}
		}
		if(frequency%2 == 1){
			return userInput[outerCrawler];
		}
	}
	return INT_MIN;
}

int getNumberOccuringOddNumber(iftNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->frequency % 2 == 1){
		return ptr;
	}
	int leftValue = getNumberOccuringOddNumber(ptr->left);
	if(leftValue != INT_MIN){
		return leftValue;
	}
	return getNumberOccuringOddNumber(ptr->right);
}

int numberOccuringOddTimesBST(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	treeutils *utils = new treeutils();
	iftNode *rootBST = utils->getBSTFromVector(userInput);
	return getNumberOccuringOddNumber(rootBST);
}

#endif /* NUMBERODDTIMES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
