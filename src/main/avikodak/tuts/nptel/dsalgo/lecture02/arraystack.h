/****************************************************************************************************************************************************
 *  File Name   		: arraystack.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture02\arraystack.h
 *  Created on			: Oct 18, 2014 :: 1:15:59 PM
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

//Tested
class arrayStack{
private:
	int sizeOfStack;
	int *stack;
	int topIndex;
public:
	arrayStack(){
		sizeOfStack = 1024;
		topIndex = -1;
		this->stack = (int *)malloc(sizeof(int)*sizeOfStack);
	}

	arrayStack(unsigned int sizeOfStack){
		this->sizeOfStack = sizeOfStack;
		this->stack = (int *)malloc(sizeof(int)*sizeOfStack);
	}

	//Tested
	bool isFull(){
		return this->topIndex >= this->sizeOfStack;
	}

	//Tested
	bool isEmpty(){
		return topIndex == -1;
	}

	//Tested
	void push(int value){
		if(isFull()){
			throw "Stack is full";
		}
		stack[++topIndex] = value;
	}

	//Tested
	int top(){
		if(isEmpty()){
			throw "Stack is empty";
		}
		return stack[this->topIndex];
	}

	//Tested
	void pop(){
		if(isEmpty()){
			throw "Stack is empty";
		}
		stack[this->topIndex] = 0;
		this->topIndex--;
	}

	//Tested
	unsigned int size(){
		return this->topIndex + 1;
	}
};

#endif /* ARRAYSTACK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
