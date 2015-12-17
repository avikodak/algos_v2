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
