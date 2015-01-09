/****************************************************************************************************************************************************
 *  File Name   		: nextpower2.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\bitmagic\page03\nextpower2.h
 *  Created on			: Jan 8, 2015 :: 7:12:54 PM
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

#ifndef NEXTPOWER2_H_
#define NEXTPOWER2_H_

int nextPowerOf2(int number){
	int setBitPosition = log2(number);
	return pow(2,setBitPosition);
}

int nextPowerOf2BitCount(int number){
	if(number && !(number & (number-1))){
		return number;
	}
	int bitCounter = 0;
	while(number > 0){
		number = number >> 1;
		bitCounter++;
	}
	return pow(2,bitCounter);
}

int nextPowerOf2Increment(int number){
	if(number && !(number & (number-1))){
		return number;
	}
	unsigned int nextPower = 1;
	while(nextPower < number){
		nextPower = nextPower << 1;
	}
	return nextPower;
}

int nextPowerOf2BySettingBits(int number){
	number -= 1;
	number = number | number >> 1;
	number = number | number >> 2;
	number = number | number >> 4;
	number = number | number >> 8;
	number = number | number >> 16;
	return number + 1;
}

#endif /* NEXTPOWER2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
