/****************************************************************************************************************************************************
 *  File Name   		: straightradixsort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture23\straightradixsort.h
 *  Created on			: Dec 2, 2014 :: 12:24:49 PM
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

#ifndef STRAIGHTRADIXSORT_H_
#define STRAIGHTRADIXSORT_H_

/****************************************************************************************************************************************************/
/* 																	O(B*N) Algorithm 																*/
/****************************************************************************************************************************************************/
void reorganizeStraightRadixSort(vector<int> &userInput,int bitPosition){
	if(userInput.size() == 0){
		return;
	}
	queue<int> unsetBitBucket,setBitBucket;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] & 1 << bitPosition){
			setBitBucket.push(userInput[counter]);
		}else{
			unsetBitBucket.push(userInput[counter]);
		}
	}
	userInput.clear();
	while(!unsetBitBucket.empty()){
		userInput.push_back(unsetBitBucket.front());
		unsetBitBucket.pop();
	}
	while(!setBitBucket.empty()){
		userInput.push_back(setBitBucket.front());
		setBitBucket.pop();
	}
}

void  straightRadixSort(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	int totalBits = log2(max_element(userInput.begin(),userInput.end()))+1;
	for(int counter = 0;counter < totalBits;counter++){
		reorganizeStraightRadixSort(userInput,counter);
	}
}

#endif /* STRAIGHTRADIXSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
