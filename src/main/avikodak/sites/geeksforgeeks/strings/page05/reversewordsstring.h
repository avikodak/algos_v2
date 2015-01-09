/****************************************************************************************************************************************************
 *  File Name   		: reversewordsstring.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page04\reversewordsstring.h
 *  Created on			: Dec 4, 2014 :: 6:33:02 PM
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

#ifndef REVERSEWORDSSTRING_H_
#define REVERSEWORDSSTRING_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void reverseWord(char *startPtr,char *endPtr){
	char tempch;
	while(startPtr != endPtr){
		tempch = startPtr[0];
		startPtr[0] = endPtr[0];
		endPtr[0] = tempch;
		if(startPtr + 1 == endPtr){
			break;
		}
		startPtr++;
		endPtr--;
	}
}

//Tested
void reverseWordsInString(char *userInput){
	if(userInput == null){
		return;
	}
	char *startCrawler = userInput,*rearCrawler;
	while(*startCrawler != '\0'){
		while(startCrawler[0] == ' '){
			startCrawler++;
		}
		rearCrawler = startCrawler;
		while(rearCrawler[1] != ' ' && rearCrawler[1] != '\0'){
			rearCrawler++;
		}
		reverseWord(startCrawler,rearCrawler);
		startCrawler = rearCrawler+1;
	}
	reverseWord(userInput,rearCrawler);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* REVERSEWORDSSTRING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
