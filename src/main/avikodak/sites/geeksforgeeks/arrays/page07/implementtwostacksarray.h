/****************************************************************************************************************************************************
 *  File Name   		: implementtwostacksarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\implementtwostacksarray.h
 *  Created on			: Nov 27, 2014 :: 7:51:34 PM
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
#define SIZE_OF_STACK_ARRAY 10

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef IMPLEMENTTWOSTACKSARRAY_H_
#define IMPLEMENTTWOSTACKSARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
class twostacksv2 {
private:
	int *userInput;
	int sizeOfArray;
	int firstStackTop,secondStackTop;
public:
	twostacksv2(){
		userInput = (int *)malloc(sizeof(int) * SIZE_OF_STACK_ARRAY);
		firstStackTop = -1;
		secondStackTop = SIZE_OF_STACK_ARRAY;
	}

	twostacksv2(int size){
		this->sizeOfArray = size;
		userInput = (int *)malloc(sizeof(int)*this->sizeOfArray);
		firstStackTop = -1;
		secondStackTop = size - 1;
	}

	void push(int value,bool firstStack = true){
		if(firstStackTop+1 == secondStackTop){
			throw "Stack full";
		}
		if(firstStack){
			userInput[++firstStackTop] = value;
		}else{
			userInput[--secondStackTop] = value;
		}
	}

	bool empty(bool firstStack = true){
		if(firstStack){
			return firstStackTop == -1;
		}else{
			return secondStackTop == sizeOfArray;
		}
	}

	void pop(bool firstStack = true){
		if(firstStack){
			if(this->empty()){
				throw "Stack empty";
			}
			firstStackTop--;
		}else{
			if(this->empty(false)){
				throw "Stack empty";
			}
			secondStackTop++;
		}
	}

	int size(bool firstStack){
		if(firstStack){
			return firstStackTop == -1?0:firstStackTop+1;
		}else{
			return sizeOfArray - secondStackTop;
		}
	}
};

#endif /* IMPLEMENTTWOSTACKSARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
