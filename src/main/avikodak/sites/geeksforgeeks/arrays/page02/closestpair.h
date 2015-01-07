/****************************************************************************************************************************************************
 *  File Name   		: closestpair.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\closestpair.h
 *  Created on			: Jan 5, 2015 :: 11:29:13 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef CLOSESTPAIR_H_
#define CLOSESTPAIR_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getClosestPairSortedArrays(vector<int> firstSortedArray,vector<int> secondSortedArray,int x){
	if(firstSortedArray.size() == 0 || secondSortedArray.size() == 0){
		return null;
	}
	int frontCrawler = 0,rearCrawler = secondSortedArray.size()-1;
	int difference,minDifference = INT_MAX,firstIndex,secondIndex;
	while(frontCrawler < (int)firstSortedArray.size() && rearCrawler >= 0){
		difference = abs(firstSortedArray[frontCrawler] + secondSortedArray[rearCrawler] - x);
		if(difference < minDifference){
			minDifference = difference;
			firstIndex = frontCrawler;
			secondIndex = rearCrawler;
		}
		if(firstSortedArray[frontCrawler] + secondSortedArray[rearCrawler] < x){
			frontCrawler++;
		}else{
			rearCrawler--;
		}
	}
	return new iPair(firstSortedArray[firstIndex],secondSortedArray[secondIndex]);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iPair *getClosestPairSortedArraysON2(vector<int> firstSortedArray,vector<int> secondSortedArray,int x){
	if(firstSortedArray.size() == 0 || secondSortedArray.size() == 0){
		return null;
	}
	int minDifference = INT_MAX,firstIndex,secondIndex,currentDifference;
	for(unsigned int outerCrawler = 0;outerCrawler < firstSortedArray.size();outerCrawler++){
		for(unsigned int innerCrawler = 0;innerCrawler < secondSortedArray.size();innerCrawler++){
			currentDifference = abs(firstSortedArray[firstIndex] + secondSortedArray[secondIndex] - x);
			if(minDifference > currentDifference){
				minDifference = currentDifference;
				firstIndex = outerCrawler;
				secondIndex = innerCrawler;
			}
		}
	}
	return new iPair(firstSortedArray[firstIndex],secondSortedArray[secondIndex]);
}

#endif /* CLOSESTPAIR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
