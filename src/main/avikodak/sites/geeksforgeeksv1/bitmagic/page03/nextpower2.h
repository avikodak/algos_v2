/****************************************************************************************************************************************************
 *  File Name   		: nextpower2.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\bitmagic\page03\nextpower2.h
 *  Created on			: Jan 8, 2015 :: 7:12:54 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/next-power-of-2/
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
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
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

#ifndef NEXTPOWER2_H_
#define NEXTPOWER2_H_

//Tested
int nextPowerOf2(int number){
	int setBitPosition = log2(number);
	return pow(2,setBitPosition+1);
}

//Tested
int nextPowerOf2BitCount(int number){
	int bitCounter = 0;
	while(number > 0){
		number = number >> 1;
		bitCounter++;
	}
	return pow(2,bitCounter);
}

//Tested
int nextPowerOf2Increment(int number){
	int nextPower = 1;
	while(nextPower <= number){
		nextPower = nextPower << 1;
	}
	return nextPower;
}

//Tested
int nextPowerOf2BySettingBits(int number){
	number -= 1;
	for(unsigned int counter = 0;counter < sizeof(int);counter++){
		number = number | (number >> (int)pow(2,counter));
	}
	return number + 1;
}

#endif /* NEXTPOWER2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
