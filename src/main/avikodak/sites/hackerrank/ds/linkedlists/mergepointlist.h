/****************************************************************************************************************************************************
 *  File Name                   : mergepointlist.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\linkedlists\mergepointlist.h
 *  Created on                  : May 24, 2015 :: 4:15:06 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MERGEPOINTLIST_H_
#define MERGEPOINTLIST_H_

struct Node{
	int data;
	Node* next;
};

//Tested
int lengthOfSill(Node *head){
	if(head == null){
		return 0;
	}
	if(head->next == null){
		return 1;
	}
	return 1 + lengthOfSill(head->next);
}

//Tested
int FindMergeNode(Node *headA, Node *headB){
    int firstLength = lengthOfSill(headA);
    int secondLength = lengthOfSill(headB);
    if(firstLength > secondLength){
    	while(firstLength != secondLength){
    		headA = headA->next;
    		firstLength--;
    	}
    }else if(secondLength > firstLength){
    	while(secondLength != firstLength){
    		headB = headB->next;
    		secondLength--;
    	}
    }
    while(headA != headB){
    	headA = headA->next;
    	headB = headB->next;
    }
    return headA != null?headA->data:0;
}

#endif /* MERGEPOINTLIST_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
