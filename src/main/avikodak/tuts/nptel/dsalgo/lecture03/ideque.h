/****************************************************************************************************************************************************
 *  File Name   		: ideque.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture03\ideque.h
 *  Created on			: Oct 20, 2014 :: 2:08:05 PM
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

#ifndef IDEQUE_H_
#define IDEQUE_H_

class ideque {
private:
	dillNode *front,*rear;
public:
	ideque(){
		front = null;
		rear = null;
	}

	bool isEmpty(){
		return front == null || rear == null;
	}

	int get_front(){
		if(isEmpty()){
			throw "Deque is empty";
		}
		return front->value;
	}

	int get_rear(){
		if(isEmpty()){
			throw "Deque is empty";
		}
		return rear->value;
	}

	void push_front(int value){
		dillNode *newNode = new dillNode(value);
		newNode->next = front;
		if(front != null){
			front->prev = newNode;
		}
		front = newNode;
		if(rear == null){
			rear = front;
		}
	}

	void push_back(int value){
		dillNode *newNode = new dillNode(value);
		newNode->prev = rear;
		if(rear != null){
			rear->next = newNode;
			rear = newNode;
		}
		if(front == null){
			front = rear;
		}
	}

	void pop_front(){
		if(isEmpty()){
			throw "Deque is empty";
		}
		dillNode *temp = front;
		if(front == rear){
			rear  = null;
		}
		front = front->next;
		free(temp);
	}

	void pop_back(){
		if(isEmpty()){
			throw "Deque is empty";
		}
		dillNode *temp = rear;
		if(front == rear){
			front = null;
		}
		rear = rear->prev;
		free(temp);
	}

	unsigned int size(){
		unsigned int counter = 0;
		dillNode *crawler = front;
		while(crawler != null){
			counter++;
			crawler = crawler->next;
		}
		return counter;
	}
};



#endif /* IDEQUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
