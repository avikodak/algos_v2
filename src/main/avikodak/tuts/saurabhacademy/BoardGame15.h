/****************************************************************************************************************************************************
 *  File Name   		: BoardGame15.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\BoardGame15.h
 *  Created on			: Dec 18, 2014 :: 6:35:07 PM
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

#ifndef BOARDGAME15_H_
#define BOARDGAME15_H_

bool isGoalReached(vector<vector<int> > currentConfiguration){
	if(currentConfiguration.size() || currentConfiguration[0].size() == 0){
		return true;
	}
	for(unsigned int rowCounter = 0;rowCounter < currentConfiguration.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < currentConfiguration[0].size();columnCounter++){
			if(rowCounter*columnCounter + columnCounter + 1 != currentConfiguration[rowCounter][columnCounter]){
				return false;
			}
		}
	}
	return true;
}

int minNumberOfSteps(vector<vector<int> > currentConfiguration,int esRow,int esColumn){
	if(esRow < 0 || esColumn < 0 || esRow >= currentConfiguration.size() || esColumn >= currentConfiguration[0].size()){
		return INT_MAX;
	}
	if(esRow == currentConfiguration.size()-1 && esColumn == currentConfiguration.size() - 1){
		if(isGoalReached(currentConfiguration)){
			return 0;
		}
	}
	int minSteps = INT_MAX;
	if(esRow-1 >= 0){
		swap(currentConfiguration[esRow][esColumn],currentConfiguration[esRow-1][esColumn]);
		minSteps = min(minSteps,1+minNumberOfSteps(currentConfiguration,esRow-1,esColumn));
		swap(currentConfiguration[esRow][esColumn],currentConfiguration[esRow-1][esColumn]);
	}
	if(esRow+1 < currentConfiguration.size()){
		swap(currentConfiguration[esRow][esColumn],currentConfiguration[esRow+1][esColumn]);
		minSteps = min(minSteps,1+minNumberOfSteps(currentConfiguration,esRow+1,esColumn));
		swap(currentConfiguration[esRow][esColumn],currentConfiguration[esRow+1][esColumn]);
	}
	if(esColumn-1 >= 0){
		swap(currentConfiguration[esRow][esColumn],currentConfiguration[esRow][esColumn-1]);
		minSteps = min(minSteps,1+minNumberOfSteps(currentConfiguration,esRow,esColumn-1));
		swap(currentConfiguration[esRow][esColumn],currentConfiguration[esRow][esColumn-1]);
	}
	if(esColumn+1 < currentConfiguration.size()){
		swap(currentConfiguration[esRow][esColumn],currentConfiguration[esRow][esColumn+1]);
		minSteps = min(minSteps,1+minNumberOfSteps(currentConfiguration,esRow,esColumn+1));
		swap(currentConfiguration[esRow][esColumn],currentConfiguration[esRow][esColumn+1]);
	}
	return minSteps;
}

#endif /* BOARDGAME15_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
