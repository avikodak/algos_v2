/****************************************************************************************************************************************************
 *  File Name                   : printmiddlesill.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/linkedlists/page04/printmiddlesill.h
 *  Created on                  : Feb 6, 2016 :: 1:34:45 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
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
#include <stdexcept>
#include <limits.h>
#include <stdint.h>
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_LINKEDLISTS_PAGE04_PRINTMIDDLESILL_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_LINKEDLISTS_PAGE04_PRINTMIDDLESILL_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
sillNode *getMiddleTwoPtrs(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *fastPtr = ptr,*slowPtr = ptr;
	while(fastPtr != null && fastPtr->next != null){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	return slowPtr;
}

unsigned int lengthOfSill(sillNode *ptr){
	return ptr == null?0:1+lengthOfSill(ptr->next);
}

sillNode *getMiddleBySillLength(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	unsigned int length = lengthOfSill(ptr);
	sillNode *crawler = ptr;
	length /= 2;
	while(length){
		crawler = crawler->next;
		length--;
	}
	return crawler;
}

sillNode *getMiddleSill(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	unsigned int counter = 0;
	sillNode *middlePtr = ptr,*crawler = ptr;
	while(ptr != null){
		if(counter%2 == 1){
			middlePtr = middlePtr->next;
		}
		counter++;
		crawler = crawler->next;
	}
	return middlePtr;
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
sillNode *getMiddleSillON2(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return ptr;
	}
	sillNode *outerCrawler = ptr,*innerCrawler;
	unsigned int firstHalfLength,secondHalfLength;
	while(outerCrawler != null){
		firstHalfLength = 0;
		secondHalfLength = 0;
		innerCrawler = ptr;
		while(innerCrawler != outerCrawler){
			firstHalfLength++;
			innerCrawler = innerCrawler->next;
		}
		innerCrawler = outerCrawler->next;
		while(innerCrawler != null){
			secondHalfLength++;
			innerCrawler = innerCrawler->next;
		}
		if(abs(firstHalfLength-secondHalfLength) < 2){
			return outerCrawler;
		}
		outerCrawler = outerCrawler->next;
	}
	return null;
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_LINKEDLISTS_PAGE04_PRINTMIDDLESILL_H_ */
