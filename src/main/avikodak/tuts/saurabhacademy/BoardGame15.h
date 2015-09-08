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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
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
