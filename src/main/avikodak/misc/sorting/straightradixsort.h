/****************************************************************************************************************************************************
 *  File Name   		: straightradixsort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\misc\sorting\straightradixsort.h
 *  Created on			: Dec 11, 2014 :: 1:01:05 PM
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

#ifndef STRAIGHTRADIXSORTV2_H_
#define STRAIGHTRADIXSORTV2_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void reorgansizeArray(vector<int> &userInput,int bitPosition){
	if(userInput.size() < 2){
		return;
	}
	queue<int> zeroBucket,oneBucket;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] & 1 << bitPosition){
			oneBucket.push(userInput[counter]);
		}else{
			zeroBucket.push(userInput[counter]);
		}
	}
	int fillCounter = -1;
	while(!zeroBucket.empty()){
		userInput[++fillCounter] = zeroBucket.front();
		zeroBucket.pop();
	}
	while(!oneBucket.empty()){
		userInput[++fillCounter] = oneBucket.front();
		oneBucket.pop();
	}
}

//Tested
void straightRadixSortV2(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	int maxVal = *max_element(userInput.begin(),userInput.end());
	int noOfBits = log2(maxVal) + 1;
	for(int counter = 0;counter < noOfBits;counter++){
		reorgansizeArray(userInput,counter);
	}
}

#endif /* STRAIGHTRADIXSORTV2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
