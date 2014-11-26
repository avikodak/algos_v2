/****************************************************************************************************************************************************
 *  File Name   		: sortarray0s1s2s.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\sortarray0s1s2s.h
 *  Created on			: Nov 26, 2014 :: 12:55:15 AM
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

#ifndef SORTARRAY0S1S2S_H_
#define SORTARRAY0S1S2S_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Dutch national flag problem
void sortArray0s1s2s(vector<int> &userInput){
	int startIndex = 0,midIndex = 0,endIndex = userInput.size()-1;
	while(midIndex < endIndex){
		switch (userInput[midIndex]) {
		case 0:
			swap(userInput.begin() + startIndex,userInput.begin() + midIndex);
			startIndex++;
			break;
		case 2:
			swap(userInput.begin() + midIndex,userInput.begin() + endIndex);
			endIndex--;
			break;
		}
		midIndex++;
	}
}

void sortArray0s1s2s(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	unsigned int zeroFrequency = 0,oneFrequency = 0,twoFrequency = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == 0){
			zeroFrequency++;
		}else if(userInput[counter] == 1){
			oneFrequency++;
		}else{
			twoFrequency++;
		}
	}
	int fillCounter = -1;
	while(zeroFrequency--){
		userInput[++fillCounter] = 0;
	}
	while(oneFrequency--){
		userInput[++fillCounter] = 1;
	}
	while(twoFrequency--){
		userInput[++fillCounter] = 2;
	}
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void sortArray0s1s2s(vector<int> userInput){
	sort(userInput.begin(),userInput.end());
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* SORTARRAY0S1S2S_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
