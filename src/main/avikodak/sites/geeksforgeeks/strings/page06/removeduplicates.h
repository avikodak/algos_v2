/****************************************************************************************************************************************************
 *  File Name   		: removeduplicates.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page05\removeduplicates.h
 *  Created on			: Dec 3, 2014 :: 7:50:18 PM
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

#ifndef REMOVEDUPLICATES_H_
#define REMOVEDUPLICATES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void removeDuplicatesHashmap(char *userInput){
	if(userInput == null){
		return;
	}
	hash_map<char,unsigned int> frequencyMap;
	hash_map<char,unsigned int>::iterator itToFrequencyMap;
	char *crawler = userInput;
	while(*crawler != '\0'){
		if(frequencyMap.find(crawler[0]) == frequencyMap.end()){
			frequencyMap[crawler[0]] = 1;
		}else{
			frequencyMap[crawler[0]] += 1;
		}
		crawler++;
	}
	int fillCounter = -1;
	crawler = userInput;
	while(*crawler != '\0'){
		itToFrequencyMap = frequencyMap.find(crawler[0]);
		if(itToFrequencyMap->second > 1){
			itToFrequencyMap->second--;
		}else{
			userInput[++fillCounter] = crawler[0];
		}
		crawler++;
	}
	userInput[++fillCounter] = '\0';
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* REMOVEDUPLICATES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
