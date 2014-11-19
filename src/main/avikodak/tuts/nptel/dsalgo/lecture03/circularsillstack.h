/****************************************************************************************************************************************************
 *  File Name   		: circularsill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture03\circularsill.h
 *  Created on			: Oct 20, 2014 :: 2:07:37 PM
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

#ifndef CIRCULARSILL_H_
#define CIRCULARSILL_H_

class circularsill {
private:
	sillNode *head;
public:
	circularsill(){
		head = null;
	}

	bool isEmpty(){
		return head == null;
	}

	void push(int value){
		if(head == null){
			head = new sillNode(value);
			head->next = head;
		}else{
			sillNode *newNode = new sillNode(head->value);
			newNode->next = head->next;
			head->value = value;
			head->next = newNode;
		}
	}

	void pop(){
		if(isEmpty()){
			throw "Stack is empty";
		}
		sillNode *nodeToBeDeleted = null;
		if(head->next == head){
			nodeToBeDeleted = head;
			*head = null;
		}else{
			head->value = head->next->value;
			nodeToBeDeleted = head->next;
			head->next = head->next->next;
		}
		free(nodeToBeDeleted);
	}

	int top(){
		if(isEmpty()){
			throw "Stack is empty";
		}
		return head->value;
	}

	unsigned int size(){
		sillNode *crawler = head;
		unsigned int counter = 0;
		while(crawler->next != head){
			crawler = crawler->next;
			counter++;
		}
		return counter;
	}

};


#endif /* CIRCULARSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
