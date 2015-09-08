/****************************************************************************************************************************************************
 *  File Name   		: xorsillutils.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page04\xorsillutils.h
 *  Created on			: Oct 16, 2014 :: 10:59:59 AM
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

#ifndef XORSILLUTILS_H_
#define XORSILLUTILS_H_

void insertIntoXORSill(xorSillNode **head,int value){
	if(*head == null){
		(*head) = new xorSillNode(value);
		return;
	}
	xorSillNode *prevNode = null,*crawler = *head,*temp;
	while(crawler->addressesXor ^ (intptr_t)prevNode){
		temp = crawler;
		crawler = crawler->addressesXor ^ (intptr_t)prevNode;
		prevNode = temp;
	}
	temp = new xorSillNode(value);
	crawler->addressesXor = (intptr_t)prevNode ^ (intptr_t)temp;
}

void printXorList(xorSillNode *head){
	if(head == null){
		return;
	}
	xorSillNode *prevNode = null,*crawler = head;
	while(crawler != null){
		printf("%d",crawler->value);
		prevNode = crawler;
		crawler = (xorSillNode *)(crawler->addressesXor ^ (intptr_t)prevNode);
	}
}

#endif /* XORSILLUTILS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
