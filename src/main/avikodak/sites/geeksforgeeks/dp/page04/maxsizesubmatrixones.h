/****************************************************************************************************************************************************
 *  File Name   		: maxsizesubmatrixones.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\maxsizesubmatrixones.h
 *  Created on			: Dec 9, 2014 :: 7:39:11 PM
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

#ifndef MAXSIZESUBMATRIXONES_H_
#define MAXSIZESUBMATRIXONES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int maxSizesubMatrixOnes(vector<vector<int> > userInput){
	if(userInput.size() == 0 || userInput[0].size() == 0){
		return 0;
	}
	vector<vector<int> > auxSpace(userInput.size());
	int maxSize = INT_MIN;
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		auxSpace[counter].resize(userInput[0].size());
	}
	for(unsigned int rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		auxSpace[rowCounter][0] = userInput[rowCounter][0];
	}
	for(unsigned int columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
		auxSpace[0][columnCounter] = userInput[0][columnCounter];
	}
	for(unsigned int rowCounter = 1;rowCounter < userInput.size();rowCounter++){
		for(unsigned int columnCounter = 1;columnCounter < userInput[0].size();columnCounter++){
			userInput[rowCounter][columnCounter] = 1 + min(userInput[rowCounter-1][columnCounter-1],min(userInput[rowCounter-1][columnCounter],userInput[rowCounter][columnCounter-1]));
			maxSize = max(maxSize,userInput[rowCounter][columnCounter]);
		}
	}
	return maxSize;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isMatrixUnitMatrix(vector<vector<int> > userInput,int startRowIndex,int startColumnColumnIndex,int size){
	return false;
}


#endif /* MAXSIZESUBMATRIXONES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
