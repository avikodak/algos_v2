/****************************************************************************************************************************************************
 *  File Name   		: medianoftwosortedarrayssizes.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\medianoftwosortedarrayssizes.h
 *  Created on			: Jan 3, 2015 :: 10:08:46 AM
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef MEDIANOFTWOSORTEDARRAYSSIZES_H_
#define MEDIANOFTWOSORTEDARRAYSSIZES_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 															    	*/
/****************************************************************************************************************************************************/


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int medianOfTwoSortedArrayDifferentSizesON(vector<int> firstSortedArray,vector<int> secondSortedArray){
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return INT_MAX;
	}
	int size = (firstSortedArray.size() + secondSortedArray.size()),medianSize;
	int prevNumber,currentNumber,firstCrawler = 0,secondCrawler = 0;
	while(medianSize-- && (firstCrawler < firstSortedArray.size() || secondCrawler < secondSortedArray.size())){
		prevNumber = currentNumber;
		if(firstCrawler >= firstSortedArray.size() || secondCrawler >= secondSortedArray.size()){
			if(firstCrawler < firstSortedArray.size()){
				currentNumber = firstSortedArray[firstCrawler];
				firstCrawler++;
			}else{
				currentNumber = secondSortedArray[secondCrawler];
				secondCrawler++;
			}
		}else{
			if(firstSortedArray[firstCrawler] < secondSortedArray[secondCrawler]){
				currentNumber = firstSortedArray[firstCrawler];
				firstCrawler++;
			}else{
				currentNumber = secondSortedArray[secondCrawler];
				secondCrawler++;
			}
		}
	}
	return size%2  == 1?currentNumber:(currentNumber + prevNumber)/2;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int medianOfTwoSortedArrayDifferentSizesONLOGN(vector<int> firstSortedArray,vector<int> secondSortedArray){
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return INT_MIN;
	}
	vector<int> mergedArray;
	merge(firstSortedArray.begin(),firstSortedArray.end(),secondSortedArray.begin(),secondSortedArray.end(),mergedArray.begin());
	sort(mergedArray.begin(),mergedArray.end());
	int size = mergedArray.size();
	return size % 2 == 1?mergedArray[size/2]:(mergedArray[size/2] + mergedArray[size/2-1])/2;
}


#endif /* MEDIANOFTWOSORTEDARRAYSSIZES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
