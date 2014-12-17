/****************************************************************************************************************************************************
 *  File Name   		: detectcycledirected.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\graph\page04\detectcycledirected.h
 *  Created on			: Dec 15, 2014 :: 6:22:37 PM
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

#ifndef DETECTCYCLEDIRECTED_H_
#define DETECTCYCLEDIRECTED_H_

bool isGraphAcyclic(vector<vector<int> > adjacencyList,unsigned int currentIndex = 0){
	if(adjacencyList.size() == 0){
		return true;
	}
	static vector<int> arrivalTimes(adjacencyList.size(),INT_MIN);
	static int timeCounter = -1;
	arrivalTimes[currentIndex] = ++timeCounter;
	for(unsigned int counter = 0;counter < adjacencyList.size();counter++){
		if(arrivalTimes[adjacencyList[currentIndex][counter]] == INT_MIN){
			if(!isGraphAcyclic(adjacencyList,adjacencyList[currentIndex][counter])){
				return false;
			}
		}else if(arrivalTimes[adjacencyList[currentIndex][counter]] < arrivalTimes[currentIndex]){
			return false;
		}
	}
	return true;
}

#endif /* DETECTCYCLEDIRECTED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
