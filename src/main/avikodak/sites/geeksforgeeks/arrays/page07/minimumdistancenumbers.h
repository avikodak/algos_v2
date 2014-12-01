/****************************************************************************************************************************************************
 *  File Name   		: minimumdistancenumbers.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\minimumdistancenumbers.h
 *  Created on			: Nov 27, 2014 :: 7:47:50 PM
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

#ifndef MINIMUMDISTANCENUMBERS_H_
#define MINIMUMDISTANCENUMBERS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int minDistanceBetweenNumbersON(vector<int> userInput,int firstNumber,int secondNumber){
	if(userInput.size() < 2){
		return 0;
	}
	int prevIndex = -1;
	int minDistance = INT_MAX;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == firstNumber || userInput[counter] == secondNumber){
			if(prevIndex == -1){
				prevIndex = counter;
			}else{
				if(userInput[counter] != userInput[prevIndex]){
					minDistance = min(minDistance,counter - prevIndex);
				}
				prevIndex = counter;
			}
		}
	}
	return minDistance;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int minDistanceBetweenNumbersON2(vector<int> userInput,int firstNumber,int secondNumber){
	if(userInput.size() < 2){
		return 0;
	}
	int minDistance = INT_MAX;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-1;outerCounter++){
		if(userInput[outerCounter] == firstNumber || userInput[outerCounter] == secondNumber){
			for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
				if(userInput[innerCounter] == userInput[outerCounter] ^ firstNumber ^ secondNumber){
					minDistance = min(minDistance,innerCounter - outerCounter);
				}
			}
		}
	}
	return minDistance;
}

#endif /* MINIMUMDISTANCENUMBERS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
