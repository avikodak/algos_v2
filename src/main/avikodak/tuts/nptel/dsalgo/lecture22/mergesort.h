/****************************************************************************************************************************************************
 *  File Name   		: mergesort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\nptel\dsalgo\lecture22\mergesort.h
 *  Created on			: Dec 1, 2014 :: 9:36:26 PM
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef MERGESORT_H_
#define MERGESORT_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void mMerge(vector<int> &userInput,int startIndex,int middleIndex,int endIndex){
	int firstCrawler = startIndex,secondCrawler = middleIndex+1;
	vector<int> auxSpace;
	while(firstCrawler <= middleIndex || secondCrawler <= endIndex){
		if(firstCrawler > middleIndex || secondCrawler > endIndex){
			if(firstCrawler <= middleIndex){
				auxSpace.push_back(userInput[firstCrawler]);
				firstCrawler++;
			}else{
				auxSpace.push_back(userInput[secondCrawler]);
				secondCrawler++;
			}
		}else{
			if(userInput[firstCrawler] < userInput[secondCrawler]){
				auxSpace.push_back(userInput[firstCrawler]);
				firstCrawler++;
			}else{
				auxSpace.push_back(userInput[secondCrawler]);
				secondCrawler++;
			}
		}
	}
	for(unsigned int crawler = 0;crawler < auxSpace.size();crawler++){
		userInput[startIndex+crawler] = auxSpace[crawler];
	}
}

//Tested
void mMergeSort(vector<int> &userInput,int startIndex,int endIndex){
	if(startIndex > endIndex || startIndex == endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	mMergeSort(userInput,startIndex,middleIndex);
	mMergeSort(userInput,middleIndex+1,endIndex);
	mMerge(userInput,startIndex,middleIndex,endIndex);
}

#endif /* MERGESORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
