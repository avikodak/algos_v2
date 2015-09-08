/****************************************************************************************************************************************************
 *  File Name   		: candle.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\easy\candle.h
 *  Created on			: Feb 9, 2015 :: 3:54:27 PM
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

#ifndef CANDLE_H_
#define CANDLE_H_

void getSmallestPositiveInteger(){
	int testCases,minValue;
	int frequency[10];
	scanf("%d",&testCases);
	while(testCases--){
		minValue = 0;
		for(unsigned int counter = 0;counter < 10;counter++){
			scanf("%d",&frequency[counter]);
			if(frequency[minValue] > frequency[counter]){
				minValue = counter;
			}
		}
		if(minValue == 0){
			printf("1");
			while(frequency[minValue] >= 0){
				printf("0");
				frequency[minValue]--;
			}
		}else{
			while(frequency[minValue] >= 0){
				printf("%d",minValue);
				frequency[minValue]--;
			}
		}
	}
}

#endif /* CANDLE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
