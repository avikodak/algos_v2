/****************************************************************************************************************************************************
 *  File Name   		: minjumps.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\minjumps.h
 *  Created on			: Dec 9, 2014 :: 8:02:03 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
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

#ifndef MINJUMPS_H_
#define MINJUMPS_H_

//Tested
int minJumpsToEndMemoization(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	if(userInput[0] == INT_MAX){
		return 0;
	}
	vector<int> auxSpace(userInput.size());
	userInput[userInput.size()-1] = 0;
	int minJumps;
	for(int outerCounter = userInput.size()-2;outerCounter >= 0;outerCounter--){
		minJumps = INT_MAX;
		if(userInput[outerCounter] != 0){
			for(int innerCounter = outerCounter+1;innerCounter <= outerCounter + userInput[outerCounter] && innerCounter < (int)userInput.size();innerCounter++){
				if(auxSpace[innerCounter] != INT_MAX){
					minJumps = min(minJumps,1+auxSpace[innerCounter]);
				}
			}
		}
		auxSpace[outerCounter] = minJumps;
	}
	return auxSpace[0];
}

//Tested
int minJumpsToEnd(vector<int> userInput,unsigned int index = 0){
	if(index >= userInput.size()){
		return INT_MAX;
	}
	if(index == userInput.size()-1){
		return 0;
	}
	if(userInput[index] == 0){
		return INT_MAX;
	}
	int minJumps = INT_MAX;
	for(int counter = 1;counter <= userInput[index];counter++){
		minJumps = min(minJumps,minJumpsToEnd(userInput,index + counter));
	}
	return minJumps == INT_MAX?INT_MAX:1+minJumps;
}

#endif /* MINJUMPS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
