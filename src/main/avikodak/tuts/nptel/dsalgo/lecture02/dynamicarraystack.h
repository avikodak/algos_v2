/****************************************************************************************************************************************************
 *  File Name   		: dynamicarraystack.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture02\dynamicarraystack.h
 *  Created on			: Oct 19, 2014 :: 8:17:55 PM
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
#include <algorithm/utils/trieutil.h>
#include <algorithm/utils/twofourtreeutil.h>

#include "tightstrategy.h"
#include "doublingstrategy.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef DYNAMICARRAYSTACK_H_
#define DYNAMICARRAYSTACK_H_

//Tested
class dynamicarraystack{
private:
	int maxSize;
	int *dynStack;
	int topIndex;
public:
	dynamicarraystack(){
		dynStack = (int *)malloc(sizeof(int));
		maxSize = 1;
		topIndex  = -1;
	}

	//Tested
	void push(int value){
		if(topIndex+1 == maxSize){
			maxSize = incrementByDoublingStrategy(&dynStack,maxSize);
		}
		dynStack[++topIndex] = value;

	}

	//Tested
	void pop(){
		if(topIndex == -1){
			throw "Stack is empty";
		}
		dynStack[topIndex] = 0;
		topIndex--;
	}

	//Tested
	unsigned int size(){
		return topIndex+1;
	}

	//Tested
	int top(){
		if(topIndex == -1){
			throw "Stack is empty";
		}
		return dynStack[topIndex];
	}

	//Tested
	int getMaxsize(){
		return maxSize;
	}

	//Tested
	bool isEmpty(){
		return topIndex == -1;
	}
};

#endif /* DYNAMICARRAYSTACK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
