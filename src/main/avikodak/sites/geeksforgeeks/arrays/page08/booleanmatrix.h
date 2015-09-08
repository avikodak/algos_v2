/****************************************************************************************************************************************************
 *  File Name   		: booleanmatrix.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\booleanmatrix.h
 *  Created on			: Nov 28, 2014 :: 1:37:18 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/a-boolean-matrix-question/
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

#ifndef BOOLEANMATRIX_H_
#define BOOLEANMATRIX_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void booleanMatrixAuxspace(vector<vector<bool> > &userInput){
	if(userInput.size() == 0 || userInput[0].size() == 0){
		return;
	}
	vector<bool> columnFlags(userInput[0].size(),false);
	vector<bool> rowFlags(userInput.size(),false);
	for(unsigned int rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
			if(userInput[rowCounter][columnCounter]){
				columnFlags[columnCounter] = true;
				rowFlags[rowCounter] = true;
			}
		}
	}
	for(unsigned int rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
			userInput[rowCounter][columnCounter] = rowFlags[rowCounter] || columnFlags[columnCounter];
		}
	}
}

//Tested
void booleanMatrix(vector<vector<bool> > &userInput){
	if(userInput.size() == 0 || userInput[0].size() == 0){
		return;
	}
	for(unsigned int rowCounter = 1;rowCounter < userInput.size();rowCounter++){
		for(unsigned int columnCounter = 1;columnCounter < userInput[0].size();columnCounter++){
			if(userInput[rowCounter][columnCounter]){
				userInput[rowCounter][0] = true;
				userInput[0][columnCounter] = true;
			}
		}
	}
	for(int rowCounter = userInput.size()-1;rowCounter >= 0;rowCounter--){
		for(int columnCounter = userInput[0].size()-1;columnCounter >= 0;columnCounter--){
			userInput[rowCounter][columnCounter] = userInput[rowCounter][0] || userInput[0][columnCounter];
		}
	}

}


#endif /* BOOLEANMATRIX_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
