/****************************************************************************************************************************************************
 *  File Name                   : insertatnthplace.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\linkedlists\insertatnthplace.h
 *  Created on                  : May 24, 2015 :: 5:35:54 PM
 *  Author                      : avikodak
 *  Testing Status              : https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list
 *  URL                         : Tested
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

#ifndef INSERTATNTHPLACE_H_
#define INSERTATNTHPLACE_H_

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
Node* InsertNth(Node *head, int data, int position){
	Node *newNode = createNode(data);
	if(position == 0){
		if(head == null){
			return newNode;
		}else{
			newNode->next = head;
			return newNode;
		}
	}else{
		int counter = 0;
		Node *crawler = head;
		while(counter+1 != position && crawler != null){
			crawler = crawler->next;
			counter++;
		}
		if(crawler != null){
			newNode->next = crawler->next;
			crawler->next = newNode;
		}
	}
	return head;
}


#endif /* INSERTATNTHPLACE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
