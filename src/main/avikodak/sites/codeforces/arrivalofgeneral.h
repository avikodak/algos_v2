/****************************************************************************************************************************************************
 *  File Name   		: arrivalofgeneral.h 
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\arrivalofgeneral.h
 *  Created on			: Mar 22, 2015 :: 8:22:54 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/144/A
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

#ifndef ARRIVALOFGENERAL_H_
#define ARRIVALOFGENERAL_H_

//Tested
void noOfSwapsForLines(){
	vector<unsigned int> userInput;
	unsigned int testCases,heights;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%d",&heights);
		userInput.push_back(heights);
	}
	unsigned int maxVal = 0,minVal = UINT_MAX;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		maxVal = max(maxVal,userInput[counter]);
		minVal = min(minVal,userInput[counter]);
	}
	unsigned int maxValIndex,minValueIndex;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == maxVal){
			maxValIndex = counter;
			break;
		}
	}
	for(int counter = userInput.size()-1;counter >= 0;counter--){
		if(userInput[counter] == minVal){
			minValueIndex = counter;
			break;
		}
	}
	if(minValueIndex > maxValIndex){
		printf("%d",userInput.size() - minValueIndex + maxValIndex - 1);
	}else{
		printf("%d",userInput.size() - minValueIndex + maxValIndex - 2);
	}
}

#endif /* ARRIVALOFGENERAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
