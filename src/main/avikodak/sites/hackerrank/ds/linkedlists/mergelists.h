/****************************************************************************************************************************************************
 *  File Name                   : mergelists.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\linkedlists\mergelists.h
 *  Created on                  : May 24, 2015 :: 3:59:13 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MERGELISTS_H_
#define MERGELISTS_H_

struct Node{
	int data;
	struct Node *next;
};

//Tested
Node *createNode(int data){
	Node *nHead = (Node *)malloc(sizeof(Node));
	nHead->data = data;
	nHead->next = null;
	return nHead;
}

//Tested
Node* MergeLists(Node *headA, Node* headB){
	Node *head = null,*crawler;
	if(headA == null || headB == null){
		if(headA != null){
			head = createNode(headA->data);
			headA = headA->next;
		}else{
			head = createNode(headB->data);
			headB = headB->next;
		}
	}else{
		if(headA->data < headB->data){
			head = createNode(headA->data);
			headA = headA->next;
		}else{
			head = createNode(headB->data);
			headB = headB->next;
		}
	}
	crawler = head;
	while(headA != null || headB != null){
		if(headA == null || headB == null){
			if(headA != null){
				crawler->next = createNode(headA->data);
				crawler = crawler->next;
				headA = headA->next;
			}else{
				crawler->next = createNode(headB->data);
				crawler = crawler->next;
				headB = headB->next;
			}
		}else{
			if(headA->data < headB->data){
				crawler->next = createNode(headA->data);
				crawler = crawler->next;
				headA = headA->next;
			}else{
				crawler->next = createNode(headB->data);
				crawler = crawler->next;
				headB = headB->next;
			}
		}
	}
	return head;
}
#endif /* MERGELISTS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
