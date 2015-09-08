/****************************************************************************************************************************************************
 *  File Name   		: pairforgivendifference.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\pairforgivendifference.h
 *  Created on			: Nov 30, 2014 :: 10:39:18 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
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

#ifndef PAIRFORGIVENDIFFERENCE_H_
#define PAIRFORGIVENDIFFERENCE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getPairForGivenDifferenceON(vector<int> userInput,int difference){
	if(userInput.size() < 2){
		return null;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) == frequencyMap.end()){
			frequencyMap[userInput[counter]] = 1;
		}else{
			frequencyMap[userInput[counter]] += 1;
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(difference + userInput[counter])) != frequencyMap.end()){
			return new iPair(userInput[counter],difference+userInput[counter]);
		}
		if((itToFrequencyMap = frequencyMap.find(userInput[counter] - difference)) != frequencyMap.end()){
			return new iPair(userInput[counter],userInput[counter] - difference);
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getPairForGivenDifferenceONLOGN(vector<int> userInput,int difference){
	if(userInput.size() < 2){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int firstCrawler = 0,secondCrawler = 1;
	while(firstCrawler < userInput.size() && secondCrawler < userInput.size()){
		if(firstCrawler != secondCrawler && userInput[secondCrawler] - userInput[firstCrawler] == difference){
			return new iPair(userInput[firstCrawler],userInput[secondCrawler]);
		}else if(userInput[secondCrawler] - userInput[firstCrawler] < difference){
			secondCrawler++;
		}else{
			firstCrawler++;
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getPairForGivenDifferenceON2(vector<int> userInput,int difference){
	if(userInput.size() < 2){
		return null;
	}
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-1;outerCounter++){
		for(unsigned int innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
			if(abs(userInput[outerCounter] - userInput[innerCounter]) == abs(difference)){
				return new iPair(userInput[outerCounter],userInput[innerCounter]);
			}
		}
	}
	return null;
}

#endif /* PAIRFORGIVENDIFFERENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
