/****************************************************************************************************************************************************
 *  File Name   		: insertionheapon.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture21\insertionheapon.h
 *  Created on			: Dec 1, 2014 :: 10:15:06 PM
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

#ifndef INSERTIONHEAPON_H_
#define INSERTIONHEAPON_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void heapify(vector<int> &userInput,int index){
	int temp;
	while(2*index + 1 < userInput.size()){
		if(2*index + 2 < userInput.size()){
			if(userInput[index] > userInput[2*index + 1] || userInput[index] > userInput[2*index+2]){
				if(userInput[2*index+1] < userInput[2*index+2]){
					temp = userInput[2*index+1];
					userInput[2*index+1] = userInput[index];
					userInput[index] = temp;
					index = 2*index+1;
				}else{
					temp = userInput[2*index+2];
					userInput[2*index+2] = userInput[index];
					userInput[index] = temp;
					index = 2*index+2;
				}
			}
		}else{
			temp = userInput[2*index+1];
			userInput[2*index+1] = userInput[index];
			userInput[index] = temp;
			index = 2*index+1;
		}

	}
}

void insertionHeapON(vector<int> &userInput){
	for(int counter = userInput.size()/2;counter >= 0;counter--){
		heapify(userInput,counter);
	}
}

#endif /* INSERTIONHEAPON_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
