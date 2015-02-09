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
