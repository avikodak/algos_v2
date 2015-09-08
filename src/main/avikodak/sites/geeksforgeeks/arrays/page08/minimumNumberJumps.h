/****************************************************************************************************************************************************
 *  File Name   		: minimumNumberJumps.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\minimumNumberJumps.h
 *  Created on			: Nov 28, 2014 :: 2:04:27 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef MINIMUMNUMBERJUMPS_H_
#define MINIMUMNUMBERJUMPS_H_

//Tested
int minimumNumberOfJumps(vector<unsigned int> userInput,unsigned int currentIndex = 0){
	if(currentIndex == userInput.size()-1){
		return 0;
	}
	if(currentIndex >= userInput.size()){
		return INT_MAX;
	}
	int minJumps = INT_MAX,result;
	for(unsigned int counter = 1;counter <= userInput[currentIndex];counter++){
		if((result = minimumNumberOfJumps(userInput,currentIndex+counter)) != INT_MAX){
			minJumps = min(minJumps,1+result);
		}
	}
	return minJumps;
}

#endif /* MINIMUMNUMBERJUMPS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
