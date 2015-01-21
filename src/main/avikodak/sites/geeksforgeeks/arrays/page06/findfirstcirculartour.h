/****************************************************************************************************************************************************
 *  File Name   		: findfirstcirculartour.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\findfirstcirculartour.h
 *  Created on			: Jan 21, 2015 :: 9:29:44 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
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

#ifndef FINDFIRSTCIRCULARTOUR_H_
#define FINDFIRSTCIRCULARTOUR_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int getFirstStartingPoint(vector<petrolPump *> userInput){
	if(userInput.size() == 0){
		return -1;
	}
	int startIndex = 0;
	int endIndex = 1;
	int currentDistance = userInput[0]->petrol - userInput[0]->nextDistance;
	while(startIndex != endIndex || currentDistance < 0){
		while(currentDistance < 0 && endIndex != startIndex){
			currentDistance = currentDistance - userInput[startIndex]->petrol + userInput[startIndex]->nextDistance;
			startIndex = (startIndex + 1)%(userInput.size());
			if(startIndex == 0){
				return -1;
			}
		}
		currentDistance += userInput[endIndex]->petrol - userInput[endIndex]->nextDistance;
		endIndex = (endIndex+1)%(userInput.size());
	}
	return startIndex;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* FINDFIRSTCIRCULARTOUR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
