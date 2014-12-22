/****************************************************************************************************************************************************
 *  File Name   		: numberofzeros.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\numberofzeros.h
 *  Created on			: Dec 22, 2014 :: 3:40:34 PM
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

#ifndef NUMBEROFZEROS_H_
#define NUMBEROFZEROS_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 															    	*/
/****************************************************************************************************************************************************/
int getLowerBoundForZero(vector<int> userInput,int start,int end){
	if(start > end){
		return userInput.size();
	}
	int middleIndex = (start + end)/2;
	if(userInput[middleIndex] == 0){
		if(middleIndex-1 >= start){
			return getLowerBoundForZero(userInput,start,middleIndex-1);
		}else{
			return middleIndex;
		}
	}else{
		return getLowerBoundForZero(userInput,middleIndex+1,end);
	}
}

unsigned int frequencyOfZeros(vector<int> userInput){
	return userInput.size() - getLowerBoundForZero(userInput,0,userInput.size()-1);
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int frequencyOfZeros(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int zeroFrequency = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == 0){
			zeroFrequency++;
		}
	}
	return zeroFrequency;
}
#endif /* NUMBEROFZEROS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
