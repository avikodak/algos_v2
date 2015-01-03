/****************************************************************************************************************************************************
 *  File Name   		: searchinrowcolumnsortedmatrix.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\searchinrowcolumnsortedmatrix.h
 *  Created on			: Dec 1, 2014 :: 12:31:00 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
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

#ifndef SEARCHINROWCOLUMNSORTEDMATRIX_H_
#define SEARCHINROWCOLUMNSORTEDMATRIX_H_

//Tested
iPair *searchInRowColumnSortedMatrix(vector<vector<int> > userInput,int key){
	if(userInput.size() == 0 || userInput[0].size() == 0){
		return null;
	}
	int rowIndex = 0,columnIndex = userInput[0].size()-1;
	while(rowIndex >= 0 && rowIndex < (int)userInput.size() && columnIndex >= 0 && columnIndex < (int)userInput[0].size()){
		if(userInput[rowIndex][columnIndex] == key){
			return new iPair(rowIndex,columnIndex);
		}else if(userInput[rowIndex][columnIndex] > key){
			columnIndex--;
		}else{
			rowIndex++;
		}
	}
	return null;
}

#endif /* SEARCHINROWCOLUMNSORTEDMATRIX_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/