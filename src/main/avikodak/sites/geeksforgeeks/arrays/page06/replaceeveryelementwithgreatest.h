/****************************************************************************************************************************************************
 *  File Name   		: replaceeveryelementwithgreatest.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\replaceeveryelementwithgreatest.h
 *  Created on			: Nov 27, 2014 :: 8:00:16 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/replace-every-element-with-the-greatest-on-right-side/
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

#ifndef REPLACEEVERYELEMENTWITHGREATEST_H_
#define REPLACEEVERYELEMENTWITHGREATEST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void replaceEveryElementON(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	int maxTillNow = userInput[userInput.size()-1],temp;
	userInput[userInput.size()-1] = -1;
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		temp = userInput[counter];
		userInput[counter] = maxTillNow;
		maxTillNow = max(maxTillNow,temp);
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void replaceEveryElementON2(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	unsigned int innerCounter;
	int maxElement;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-1;outerCounter++){
		maxElement = userInput[outerCounter+1];
		for(innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			maxElement = max(maxElement,userInput[innerCounter]);
		}
		userInput[outerCounter] = maxElement;
	}
	userInput[userInput.size()-1] = -1;
}

#endif /* REPLACEEVERYELEMENTWITHGREATEST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
