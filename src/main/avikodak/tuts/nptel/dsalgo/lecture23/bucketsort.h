/****************************************************************************************************************************************************
 *  File Name   		: bucketsort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture23\bucketsort.h
 *  Created on			: Dec 2, 2014 :: 12:19:58 PM
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

#ifndef BUCKETSORT_H_
#define BUCKETSORT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void bucketSort(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	map<int,unsigned int> frequencyMap;
	map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			itToFrequencyMap->second += 1;
		}else{
			frequencyMap.insert(pair<int,unsigned int>(userInput[counter],1));
		}
	}
	unsigned int counter = 0;
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		while(itToFrequencyMap->second--){
			userInput[counter++] = itToFrequencyMap->first;
		}
	}
}

#endif /* BUCKETSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
