/****************************************************************************************************************************************************
 *  File Name   		: unordereddictionary.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture08\unordereddictionary.h
 *  Created on			: Nov 19, 2014 :: 12:55:04 AM
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

#ifndef UNORDEREDDICTIONARY_H_
#define UNORDEREDDICTIONARY_H_

class unordereddict {
private:
	dillNode *head;
public:
	void insert(int value){
		if(head == null){
			head = new dillNode(value);
			return;
		}
		dillNode *crawler = head;
		while(crawler->next != null){
			if(crawler->value == value){
				return;
			}
			crawler = crawler->next;
		}
		crawler->next = new dillNode(value);
	}

	void remove(int value){
		if(head == null){
			return;
		}
		dillNode *nodeToBeDeleted,*crawler = head;
		if(head->value == value){
			nodeToBeDeleted = head;
			head = head->next;
			free(nodeToBeDeleted);
			return;
		}
		while(crawler->next != null){
			if(crawler->next->value == value){
				nodeToBeDeleted = crawler->next;
				crawler->next = crawler->next->next;
				free(nodeToBeDeleted);
				return;
			}
			crawler = crawler->next;
		}
	}

	bool search(int value){
		dillNode *crawler = head;
		while(crawler != null){
			if(crawler->value == value){
				return true;
			}
		}
		return false;
	}

	int predecessor(int value){
		dillNode *crawler = head;
		int predecessor = INT_MIN;
		while(crawler != null){
			if(crawler->value < value){
				predecessor = max(predecessor,crawler->value);
			}
			crawler = crawler->next;
		}
		return predecessor;
	}

	int successor(int value){
		dillNode *crawler = head;
		int successor = INT_MAX;
		while(crawler != null){
			if(crawler->value > value){
				successor = min(successor,crawler->value);
			}
			crawler = crawler->next;
		}
		return successor;
	}
};

#endif /* UNORDEREDDICTIONARY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
