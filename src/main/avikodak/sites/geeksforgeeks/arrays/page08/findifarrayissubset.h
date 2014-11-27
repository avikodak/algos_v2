/****************************************************************************************************************************************************
 *  File Name   		: findifarrayissubset.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\findifarrayissubset.h
 *  Created on			: Nov 26, 2014 :: 8:48:11 PM
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

#ifndef FINDIFARRAYISSUBSET_H_
#define FINDIFARRAYISSUBSET_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isArraySubsetOfAnother(vector<int> largeArray,vector<int> smallArray){
	if(smallArray.size() == 0){
		return true;
	}
	if(largeArray.size() == 0){
		return false;
	}
	hash_map<int,unsigned int> valueFrequencyMap;
	hash_map<int,unsigned int>::iterator itToValueFrequencyMap;
	for(unsigned int counter = 0;counter < largeArray.size();counter++){
		if((itToValueFrequencyMap = valueFrequencyMap.find(largeArray[counter])) == valueFrequencyMap.end()){
			valueFrequencyMap[largeArray[counter]] = 1;
		}else{
			valueFrequencyMap[largeArray[counter]] += 1;
		}
	}
	for(unsigned int counter = 0;counter < smallArray.size();counter++){
		itToValueFrequencyMap = valueFrequencyMap.find(smallArray[counter]);
		if(itToValueFrequencyMap == valueFrequencyMap.end()){
			return false;
		}
		if(itToValueFrequencyMap->second == 1){
			valueFrequencyMap.erase(smallArray[counter]);
		}else{
			valueFrequencyMap[smallArray[counter]]--;
		}
	}
}


/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//works if unique
bool isArraySubsetOfAnotherON2(vector<int> largeArray,vector<int> smallArray){
	if(smallArray.size() == 0){
		return true;
	}
	if(largeArray.size() == 0){
		return false;
	}
	bool valueFound;
	for(unsigned int outerCounter = 0;outerCounter < smallArray.size();outerCounter++){
		valueFound = false;
		for(unsigned int innerCounter = 0;innerCounter < largeArray.size();innerCounter++){
			if(smallArray[outerCounter] == largeArray[innerCounter]){
				valueFound = true;
			}
		}
		if(!valueFound){
			return false;
		}
	}
	return true;
}

#endif /* FINDIFARRAYISSUBSET_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
