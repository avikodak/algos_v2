/****************************************************************************************************************************************************
 *  File Name   		: maxproductcutting.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page01\maxproductcutting.h
 *  Created on			: Jan 12, 2015 :: 8:25:17 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-set-36-cut-a-rope-to-maximize-product/
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

#ifndef MAXPRODUCTCUTTING_H_
#define MAXPRODUCTCUTTING_H_

//Tested
int maxProductCutting(int rodLength){
	if(rodLength < 0){
		return INT_MIN;
	}
	if(rodLength < 2){
		return 0;
	}
	int maxProduct = INT_MIN;
	for(int counter = 1;counter < rodLength;counter++){
		maxProduct = max(maxProduct,max(counter * (rodLength-counter),counter * maxProductCutting(rodLength - counter)));
	}
	return maxProduct;
}

//Tested
int maxProductCuttingMemoization(int rodLength){
	if(rodLength < 2){
		return 0;
	}
	vector<int> auxSpace;
	auxSpace.push_back(0);
	auxSpace.push_back(0);
	int maxProduct;
	for(int outerCounter = 2;outerCounter <= rodLength;outerCounter++){
		maxProduct = INT_MIN;
		for(int innerCounter = 1;innerCounter <= outerCounter/2;innerCounter++){
			maxProduct = max(maxProduct,max(innerCounter * (outerCounter-innerCounter),innerCounter * auxSpace[outerCounter - innerCounter]));
		}
		auxSpace.push_back(maxProduct);
	}
	return auxSpace[auxSpace.size()-1];
}

#endif /* MAXPRODUCTCUTTING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
