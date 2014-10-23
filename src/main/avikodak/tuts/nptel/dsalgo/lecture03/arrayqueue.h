/****************************************************************************************************************************************************
 *  File Name   		: arrayqueue.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture03\arrayqueue.h
 *  Created on			: Oct 20, 2014 :: 2:07:02 PM
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

#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

class arrayqueue {
private:
	int *queue;
	int frontIndex=-1,rearIndex=0;
	unsigned int maxSize;
public:
	arrayqueue(){
		this->maxSize = 1024;
		this->queue = (int *)malloc(sizeof(int)*maxSize);
	}

	arrayqueue(unsigned int size){
		this->maxSize = size;
		this->queue = (int *)malloc(sizeof(int)*maxSize);
	}

	bool isFull(){
		return rearIndex+1 == frontIndex;
	}

	bool isEmpty(){
		return frontIndex == -1;
	}

	void push(int value){
		if(isFull()){
			throw "Queue is full";
		}
		if(frontIndex == -1){
			queue[rearIndex++] = value;
			frontIndex = 0;
		}else{
			queue[++frontIndex] = value;
		}
	}

	void pop(){
		if(isEmpty()){
			throw "Queue is empty";
		}
		queue[frontIndex] = 0;
		frontIndex = (frontIndex+1)%maxSize;
	}

	int front(){
		if(isEmpty()){
			throw "Queue is empty";
		}
		return queue[frontIndex];
	}

	unsigned int size(){
		return maxSize - rearIndex + frontIndex;
	}
};

#endif /* ARRAYQUEUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
