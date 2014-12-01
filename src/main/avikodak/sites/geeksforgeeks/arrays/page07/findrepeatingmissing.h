/****************************************************************************************************************************************************
 *  File Name   		: findrepeatingmissing.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\findrepeatingmissing.h
 *  Created on			: Nov 27, 2014 :: 7:47:09 PM
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

#ifndef FINDREPEATINGMISSING_H_
#define FINDREPEATINGMISSING_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
iPair *findRepeatingAndMissingNumber(vector<int> userInput){
	if(userInput.size() == 0){
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
	iPair *result = new iPair(0,0);
	for(unsigned int counter = 1;counter <= userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) == frequencyMap.end()){
			result->secondValue = userInput[counter];
		}else{
			if(itToFrequencyMap->second > 1){
				result->firstValue = userInput[counter];
			}
		}
	}
	return result;
}

iPair *findMissingRepeatingElementsArray(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	iPair *result = new iPair(0,0);
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] < 0){
			result->secondValue = counter+1;
		}else{
			userInput[abs(userInput[counter])-1] *= -1;
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] > 0){
			result->firstValue = counter+1;
		}
	}
	return result;
}

iPair *findMissingRepeatingElementEquations(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	int sequenceSum = 0,arraySum = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		sequenceSum += counter+1;
		arraySum += userInput[counter];
	}
	iPair *result = new iPair(0,0);
	result->firstValue = (sequenceSum + arraySum)/3;
	result->secondValue = (3*sequenceSum - result->firstValue)/3;
	return result;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
iPair *findMissingRepeatingSorting(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	iPair *result = new iPair(0,0);
	sort(userInput.begin(),userInput.end());
	if(userInput[0] != 1){
		result->firstValue = 1;
	}
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		if(userInput[counter] == userInput[counter+1]){
			result->secondValue = userInput[counter];
			counter++;
		}else if(userInput[counter+1] - userInput[counter] > 1){
			result->firstValue = userInput[counter] + 1;
		}
	}
	if(result->secondValue == 0){
		result->firstValue = userInput.size();
	}
	return result;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
iPair *findMissingRepeatingON2(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	iPair *result = new iPair(0,0);
	unsigned int frequency;
	for(unsigned int outerCounter = 1;outerCounter <= userInput.size();outerCounter++){
		frequency = 0;
		for(unsigned int innerCounter = 0;innerCounter < userInput.size();innerCounter++){
			if(userInput[innerCounter] == (int)outerCounter){
				frequency++;
			}
		}
		if(frequency == 0){
			result->firstValue = outerCounter;
		}else if(frequency > 1){
			result->secondValue = outerCounter;
		}
	}
	return result;
}
#endif /* FINDREPEATINGMISSING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
