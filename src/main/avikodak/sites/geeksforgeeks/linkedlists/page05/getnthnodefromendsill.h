/****************************************************************************************************************************************************
 *  File Name   		: getnthnodefromendsill.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\linkedlists\page05\getnthnodefromendsill.h
 *  Created on			: Oct 12, 2014 :: 11:34:01 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
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

#ifndef GETNTHNODEFROMENDSILL_H_
#define GETNTHNODEFROMENDSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
sillNode *getNthNodeFromEnd(sillNode *ptr,unsigned int &nValue){
	if(ptr == null || nValue == 0){
		return null;
	}
	sillNode *nthNode = getNthNodeFromEnd(ptr->next,nValue);
	nValue--;
	if(nValue == 0){
		return ptr;
	}
	return nthNode;
}

//Tested
sillNode *getNthNodeFromEndTwoPtrs(sillNode *ptr,unsigned int nValue){
	if(ptr == null || nValue == 0){
		return null;
	}
	sillNode *frontCrawler = ptr,*rearCrawler= ptr;
	while(nValue-- && frontCrawler != null){
		frontCrawler = frontCrawler->next;
	}
	if(frontCrawler == null){
		return null;
	}
	while(frontCrawler != null){
		frontCrawler = frontCrawler->next;
		rearCrawler = rearCrawler->next;
	}
	return rearCrawler;
}

//Tested
sillNode *getNthNodeByFindingLength(sillNode *ptr,unsigned int nValue){
	if(ptr == null || nValue == 0){
		return null;
	}
	sillutils *utils = new sillutils();
	unsigned int lengthOfSill = utils->lengthOfSill(ptr);
	if(nValue > lengthOfSill){
		return null;
	}
	lengthOfSill -= nValue;
	while(lengthOfSill--){
		ptr = ptr->next;
	}
	return ptr;
}

//Tested
sillNode *getNthNodeFromEndHashmap(sillNode *ptr,unsigned int nValue){
	if(ptr == null || nValue == 0){
		return null;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> indexNodeMap = utils->getSillAsHashmap(ptr,1)->indexNodeMap;
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	if(nValue > indexNodeMap.size()){
		return null;
	}
	return indexNodeMap.find(indexNodeMap.size()-nValue+1)->second;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
sillNode *getNthNodeFromEndON2(sillNode *ptr,unsigned int nValue){
	if(ptr == null || nValue == 0){
		return null;
	}
	sillNode *outerCrawler = ptr,*innerCrawler;
	unsigned int counter;
	while(outerCrawler != null){
		counter = 0;
		innerCrawler = outerCrawler;
		while(innerCrawler != null){
			counter += 1;
			innerCrawler = innerCrawler->next;
		}
		if(counter == nValue){
			return outerCrawler;
		}
		outerCrawler = outerCrawler->next;
	}
	return null;
}

#endif /* GETNTHNODEFROMENDSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
