/****************************************************************************************************************************************************
 *  File Name   		: matrixmultiplication.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\matrixmultiplication.h
 *  Created on			: Dec 11, 2014 :: 12:32:16 AM
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
vector<vector<int> > matrixMultiplication(vector<vector<int> > firstMatrix,vector<vector<int> >secondMatrix){
	vector<vector<int> > result;
	if(firstMatrix.size() == 0 || firstMatrix[0].size() == 0 || secondMatrix.size() == 0 || secondMatrix[0].size() == 0){
		return result;
	}
	result.resize(firstMatrix.size());
	for(unsigned int counter = 0;counter < result.size();counter++){
		result[counter].resize(secondMatrix[0].size());
	}
	for(unsigned int rowCounter = 0;rowCounter < result.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < result[0].size();columnCounter++){
			result[rowCounter][columnCounter] = 0;
			for(unsigned int counter = 0;counter < result[0].size();counter++){
				result[rowCounter][columnCounter] += firstMatrix[rowCounter][counter] * secondMatrix[counter][columnCounter];
			}
		}
	}
	return result;
}

#endif /* MATRIXMULTIPLICATION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
