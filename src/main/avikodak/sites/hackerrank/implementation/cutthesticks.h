/****************************************************************************************************************************************************
 *  File Name   		: cutthesticks.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\implementation\cutthesticks.h
 *  Created on			: Feb 11, 2015 :: 11:50:19 AM
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

#ifndef CUTTHESTICKS_H_
#define CUTTHESTICKS_H_

//Tested
void printSticksUsed(){
	int size,input;
	scanf("%d",&size);
	vector<int> userInput;
	while(size--){
		scanf("%d",&input);
		userInput.push_back(input);
	}
	int minValue,cutsMade;
	while(true){
		minValue = *min_element(userInput.begin(),userInput.end());
		if(minValue == INT_MAX){
			return;
		}
		cutsMade = 0;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			if(userInput[counter] != INT_MAX){
				if(userInput[counter] == minValue){
					userInput[counter] = INT_MAX;
				}else{
					userInput[counter] -= minValue;
				}
				cutsMade++;
			}
		}
		printf("%d\n",cutsMade);
	}
}

#endif /* CUTTHESTICKS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
