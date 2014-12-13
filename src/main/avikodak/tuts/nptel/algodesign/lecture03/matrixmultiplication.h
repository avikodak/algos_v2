/****************************************************************************************************************************************************
 *  File Name   		: matrixmultiplication.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\algodesign\lecture03\matrixmultiplication.h
 *  Created on			: Dec 12, 2014 :: 1:58:00 AM
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

#ifndef MATRIXMULTIPLICATION_H_
#define MATRIXMULTIPLICATION_H_

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<vector<int> > matrixMultiplication(vector<vector<int> > firstUserinput,vector<vector<int> > secondUserinput){
	vector<vector<int> > result;
	if(firstUserinput.size() == 0 || secondUserinput.size() == 0){
		return result;
	}
	if(firstUserinput[0].size() != secondUserinput.size()){
		throw "Invalid input";
	}
	result.resize(firstUserinput.size());
	for(unsigned int counter = 0;counter < result.size();counter++){
		result[counter].resize(secondUserinput[0].size());
	}
	for(unsigned int rowCounter = 0;rowCounter < firstUserinput.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < secondUserinput[0].size();columnCounter++){
			result[rowCounter][columnCounter] = 0;
		}
	}
	for(unsigned int rowCounter = 0;rowCounter < firstUserinput.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < secondUserinput[0].size();columnCounter++){
			for(unsigned int counter = 0;counter < secondUserinput.size();counter++){
				result[rowCounter][columnCounter] += firstUserinput[rowCounter][counter] * secondUserinput[counter][columnCounter];
			}
		}
	}
	return result;
}

#endif /* MATRIXMULTIPLICATION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
