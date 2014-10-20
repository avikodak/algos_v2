/****************************************************************************************************************************************************
 *  File Name   		: dynamicarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture02\dynamicarray.h
 *  Created on			: Oct 18, 2014 :: 1:16:17 PM
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
#ifndef DYNAMICSTACK_H_
#define DYNAMICSTACK_H_

//Tested
class dynamicstack{
private:
	sillNode *topNode;
	unsigned int counter;
public:
	dynamicstack(){
		topNode = null;
		counter = 0;
	}

	//Tested
	bool isEmpty(){
		return topNode == null;
	}

	//Tested
	unsigned int size(){
		return counter;
	}

	//Tested
	void push(int value){
		if(topNode == null){
			topNode = new sillNode(value);
		}else{
			sillNode *temp = new sillNode(value);
			temp->next = topNode;
			topNode = temp;
		}
		counter++;
	}

	//Tested
	void pop(){
		if(topNode == null){
			throw "Stack is empty";
		}
		sillNode *temp = topNode;
		topNode = topNode->next;
		free(temp);
		counter--;
	}

	//Tested
	int top(){
		if(isEmpty()){
			throw "Stack is empty";
		}
		return topNode->value;
	}
};

#endif /* DYNAMICSTACK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

