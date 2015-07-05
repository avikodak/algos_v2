/****************************************************************************************************************************************************
 *  File Name                   : detectcycle.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\linkedlists\detectcycle.h
 *  Created on                  : Jul 5, 2015 :: 6:44:05 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle
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

#ifndef DETECTCYCLE_H_
#define DETECTCYCLE_H_

/*struct Node{
	int data;
	struct Node *next;
};*/

//Tested
int HasCycle(Node* head){
	if(head == NULL || head->next == NULL){
		return 0;
	}
	Node *fastPtr = head->next->next,*slowPtr = head;
	while(fastPtr != NULL && fastPtr->next != NULL){
		if(fastPtr == slowPtr ){
			return 1;
		}
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	return 0;
}

#endif /* DETECTCYCLE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
