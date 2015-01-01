/****************************************************************************************************************************************************
 *  File Name   		: printmatrixinspiralorder.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\printmatrixinspiralorder.h
 *  Created on			: Nov 27, 2014 :: 7:42:39 PM
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

#ifndef PRINTMATRIXINSPIRALORDER_H_
#define PRINTMATRIXINSPIRALORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printMatrixInSpiralOrderMain(vector<vector<int> > userInput,int startRowIndex,int endRowIndex,int startColumnIndex,int endColumnIndex){
	if(startRowIndex > endRowIndex && startColumnIndex > endColumnIndex){
		return;
	}
	for(unsigned int counter = startColumnIndex;counter < endColumnIndex;counter++){
		printf("%d\t",userInput[startRowIndex][counter]);
	}
	for(unsigned int counter = startRowIndex;counter < endRowIndex;counter++){
		printf("%d\t",userInput[counter][endColumnIndex]);
	}
	for(unsigned int counter = endColumnIndex;counter > startColumnIndex;counter--){
		printf("%d\t",userInput[endRowIndex][counter]);
	}
	for(unsigned int counter = endRowIndex;counter > startRowIndex;counter--){
		printf("%d\t",userInput[counter][startColumnIndex]);
	}
	printMatrixInSpiralOrderMain(userInput,startRowIndex+1,endRowIndex-1,startColumnIndex+1,endColumnIndex-1);
}

void printMatrixInSpiralOrder(vector<vector<int> > userInput){
	printMatrixInSpiralOrderMain(userInput,0,userInput.size()-1,0,userInput[0].size()-1);
}

#endif /* PRINTMATRIXINSPIRALORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
