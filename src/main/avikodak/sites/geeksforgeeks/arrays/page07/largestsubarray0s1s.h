/****************************************************************************************************************************************************
 *  File Name   		: largestsubarray0s1s.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\largestsubarray0s1s.h
 *  Created on			: Dec 29, 2014 :: 4:21:37 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
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

#ifndef LARGESTSUBARRAY0S1S_H_
#define LARGESTSUBARRAY0S1S_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int largestEqualSubarray0s1s(vector<int> userInput){
	if(userInput.size() < 2){
		return 0;
	}
	int maxSize = INT_MIN;
	int startIndex;
	hash_map<int,unsigned int> valueIndexMap;
	hash_map<int,unsigned int>::iterator itToValueIndexMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(counter != 0){
			userInput[counter] = userInput[counter-1] + (userInput[counter] == 0?-1:1);
		}else{
			userInput[counter] = userInput[counter] == 0?-1:1;
		}
		if(userInput[counter] == 0){
			maxSize = max(maxSize,(int)(counter+1));
			startIndex = 0;
		}else {
			if((itToValueIndexMap = valueIndexMap.find(userInput[counter])) == valueIndexMap.end()){
				valueIndexMap.insert(pair<int,unsigned int>(userInput[counter],counter));
			}else{
				startIndex = itToValueIndexMap->second;
				maxSize = max(maxSize,(int)(counter - startIndex));
			}
		}
	}
	return maxSize;
}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int largestEqualSubarray0s1sON3(vector<int> userInput){
	if(userInput.size() < 2){
		return 0;
	}
	int maxSize = INT_MIN;
	int zeroCounter,oneCounter;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		for(unsigned int middleCounter = outerCounter+1;middleCounter < userInput.size();middleCounter++){
			zeroCounter = 0;
			oneCounter = 0;
			for(unsigned int innerCounter = outerCounter;innerCounter <= middleCounter;innerCounter++){
				if(userInput[innerCounter] == 0){
					zeroCounter++;
				}else{
					oneCounter++;
				}
			}
			if(zeroCounter == oneCounter){
				maxSize = max(maxSize,(int)(middleCounter - outerCounter + 1));
			}
		}
	}
	return maxSize;
}

#endif /* LARGESTSUBARRAY0S1S_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
