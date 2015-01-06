/****************************************************************************************************************************************************
 *  File Name   		: duplicateskdistance.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page01\duplicateskdistance.h
 *  Created on			: Jan 5, 2015 :: 10:23:53 AM
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

#ifndef DUPLICATESKDISTANCE_H_
#define DUPLICATESKDISTANCE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool duplicatesAtKDistance(vector<int> userInput,int kDistance){
	if(userInput.size() == 0){
		return false;
	}
	hash_map<int,unsigned int> valIndexMap;
	hash_map<int,unsigned int>::iterator itToValIndexMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToValIndexMap = valIndexMap.find(userInput[counter])) == valIndexMap.end()){
			valIndexMap.insert(pair<int,unsigned int>(userInput[counter],counter));
		}else{
			if(counter - itToValIndexMap->second + 1 < kDistance){
				return true;
			}
			valIndexMap[userInput[counter]] = counter;
		}
	}
	return false;
}

bool duplicatesAtKDistanceSet(vector<int> userInput,int kDistance){
	if(userInput.size() == 0){
		return false;
	}
	set<int> visitedValues;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(visitedValues.find(userInput[counter]) != visitedValues.end()){
			return true;
		}
		visitedValues.insert(userInput[counter]);
		if(kDistance - counter + 1 >= 0){
			visitedValues.erase(userInput[kDistance-counter+1]);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool duplicatesAtKDistanceON2(vector<int> userInput,unsigned int kDistance){
	if(userInput.size() == 0 || kDistance){
		return false;
	}
	int innerCounter;
	for(unsigned int outerCounter = 1;outerCounter < userInput.size();outerCounter++){
		for(innerCounter = outerCounter-1;innerCounter > outerCounter - kDistance+1;innerCounter--){
			if(userInput[outerCounter] == userInput[innerCounter]){
				return true;
			}
		}
	}
	return false;
}

#endif /* DUPLICATESKDISTANCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
