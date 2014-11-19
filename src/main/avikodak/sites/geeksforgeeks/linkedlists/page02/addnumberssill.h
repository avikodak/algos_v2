/****************************************************************************************************************************************************
 *  File Name   		: addnumberssill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page02\addnumberssill.h
 *  Created on			: Oct 30, 2014 :: 11:46:58 AM
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

#ifndef ADDNUMBERSSILL_H_
#define ADDNUMBERSSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *addNumbersSill(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null && secondPtr == null){
		return null;
	}
	if(firstPtr == null || secondPtr == null){
		return firstPtr == null?secondPtr:firstPtr;
	}
	sillNode *resultHead,*resultCrawler,*newNode;
	unsigned int carry = 0;
	unsigned int currentSum;
	while(firstPtr != null && secondPtr != null){
		currentSum = firstPtr->value + secondPtr->value + carry;
		carry = currentSum/10;
		if(resultHead == null){
			resultHead = new sillNode(currentSum%10);
			resultCrawler = resultHead;
		}else{
			resultCrawler->next = new sillNode(currentSum % 10);
			resultCrawler = resultCrawler->next;
		}
		firstPtr = firstPtr->next;
		secondPtr = secondPtr->next;
	}
	while(firstPtr != null){
		currentSum = firstPtr->value + carry;
		carry = currentSum/10;
		if(resultHead == null){
			resultHead = new sillNode(currentSum%10);
			resultCrawler = resultHead;
		}else{
			resultCrawler->next = new sillNode(currentSum % 10);
			resultCrawler = resultCrawler->next;
		}
		firstPtr = firstPtr->next;
	}
	while(secondPtr != null){
		currentSum = secondPtr->value + carry;
		carry = currentSum/10;
		if(resultHead == null){
			resultHead = new sillNode(currentSum%10);
			resultCrawler = resultHead;
		}else{
			resultCrawler->next = new sillNode(currentSum % 10);
			resultCrawler = resultCrawler->next;
		}
		secondPtr = secondPtr->next;
	}
	return resultCrawler;
}

#endif /* ADDNUMBERSSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
