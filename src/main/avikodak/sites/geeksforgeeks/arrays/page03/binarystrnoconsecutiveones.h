/****************************************************************************************************************************************************
 *  File Name   		: binarystrnoconsecutiveones.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\binarystrnoconsecutiveones.h
 *  Created on			: Jan 19, 2015 :: 8:47:30 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
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

#ifndef BINARYSTRNOCONSECUTIVEONES_H_
#define BINARYSTRNOCONSECUTIVEONES_H_

int countBinaryStringsNoConsecutiveOnes(unsigned int nValue){
	if(nValue == 0){
		return 1;
	}
	vector<int> endingWithZero,endingWithOne;
	endingWithOne.push_back(1);
	endingWithZero.push_back(1);
	for(unsigned int counter = 1;counter <= nValue;counter++){
		endingWithZero.push_back(endingWithZero[counter-1] + endingWithOne[counter-1]);
		endingWithOne.push_back(endingWithZero[counter-1]);
	}
	return endingWithZero[endingWithZero.size()-1] + endingWithOne[endingWithOne.size()-1];
}

#endif /* BINARYSTRNOCONSECUTIVEONES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
