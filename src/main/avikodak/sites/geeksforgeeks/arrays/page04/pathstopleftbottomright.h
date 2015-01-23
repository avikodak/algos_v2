/****************************************************************************************************************************************************
 *  File Name   		: pathstopleftbottomright.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\pathstopleftbottomright.h
 *  Created on			: Dec 22, 2014 :: 6:10:47 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
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

#ifndef PATHSTOPLEFTBOTTOMRIGHT_H_
#define PATHSTOPLEFTBOTTOMRIGHT_H_

//Tested
int countPathsFromTopLeftToBottomRight(int row,int column){
	if(row == 1 || column == 1){
		return 1;
	}
	return countPathsFromTopLeftToBottomRight(row-1,column) + countPathsFromTopLeftToBottomRight(row,column-1);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int countPathsFromTopLeftBottomRightMemoization(int row,int column){
	if(row == 0 || column == 0){
		return 1;
	}
	vector<vector<int> > auxSpace(row);
	for(int counter = 0;counter < row;counter++){
		auxSpace[counter].assign(column,1);
	}
	for(int rowCounter = 1;rowCounter < row;rowCounter++){
		for(int columnCounter = 1;columnCounter < column;columnCounter++){
			auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter-1][columnCounter] + auxSpace[rowCounter][columnCounter-1];
		}
	}
	return auxSpace[row-1][column-1];
}

#endif /* PATHSTOPLEFTBOTTOMRIGHT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
