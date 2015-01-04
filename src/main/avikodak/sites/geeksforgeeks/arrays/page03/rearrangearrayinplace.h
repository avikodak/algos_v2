/****************************************************************************************************************************************************
 *  File Name   		: rearrangearrayinplace.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\rearrangearrayinplace.h
 *  Created on			: Jan 4, 2015 :: 1:22:19 PM
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

#ifndef REARRANGEARRAYINPLACE_H_
#define REARRANGEARRAYINPLACE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void rearrangeArray(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		userInput[counter] += (userInput[userInput[counter]]%userInput.size())*(userInput.size());
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		userInput[counter] /= userInput.size();
	}
}

void rearrangeArrayAuxSpace(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	vector<int> auxSpace(userInput.size());
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		auxSpace[counter] = userInput[userInput[counter]];
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		userInput[counter] = auxSpace[counter];
	}
}

#endif /* REARRANGEARRAYINPLACE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
