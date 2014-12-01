/****************************************************************************************************************************************************
 *  File Name   		: productarraypuzzle.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\productarraypuzzle.h
 *  Created on			: Nov 26, 2014 :: 1:12:53 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/a-product-array-puzzle/
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

#ifndef PRODUCTARRAYPUZZLE_H_
#define PRODUCTARRAYPUZZLE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void productArrayPuzzle(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	vector<int> leftProduct,rightProduct;
	leftProduct.reserve(userInput.size());
	rightProduct.reserve(userInput.size());
	leftProduct[0] = 1;
	rightProduct[userInput.size()-1] = 1;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		leftProduct[counter] = leftProduct[counter-1] * userInput[counter-1];
	}
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		rightProduct[counter] = rightProduct[counter+1] * userInput[counter+1];
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		userInput[counter] = leftProduct[counter] * rightProduct[counter];
	}
}

#endif /* PRODUCTARRAYPUZZLE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
