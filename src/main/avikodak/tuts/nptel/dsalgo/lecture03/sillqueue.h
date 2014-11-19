/****************************************************************************************************************************************************
 *  File Name   		: sillqueue.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture03\sillqueue.h
 *  Created on			: Oct 20, 2014 :: 2:08:14 PM
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

#ifndef SILLQUEUE_H_
#define SILLQUEUE_H_

class sillqueue {
private:
	sillNode *head,*tail;
public:
	sillqueue(){
		this->head = null;
		this->tail = null;
	}

	bool isEmpty(){
		return head == null;
	}

	void push(int value){
		if(head == null){
			head = new sillNode(value);
			tail = head;
		}else{
			tail->next = new sillNode(value);
			tail = tail->next;
		}
	}

	void pop(){
		if(isEmpty()){
			throw "Queue empty";
		}
		sillNode *temp = head;
		head = head->next;
		free(temp);
	}

	unsigned int size(){
		sillNode *crawler = head;
		unsigned int counter = 0;
		while(crawler != null){
			counter++;
			crawler = crawler->next;
		}
		return counter;
	}

	int front(){
		if(isEmpty()){
			throw "Queue empty";
		}
		return head->value;
	}
};

#endif /* SILLQUEUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
