/****************************************************************************************************************************************************
 *  File Name   		: commonelementsthreesorted.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page02\commonelementsthreesorted.h
 *  Created on			: Jan 5, 2015 :: 11:23:46 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/O
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

#ifndef COMMONELEMENTSTHREESORTED_H_
#define COMMONELEMENTSTHREESORTED_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> commonElementsThreeSortedArrays(vector<int> firstSortedArray,vector<int> secondSortedArray,vector<int> thirdSortedArray){
	vector<int> commonElements;
	if(firstSortedArray.size() == 0 || secondSortedArray.size() == 0 || thirdSortedArray.size() == 0){
		return commonElements;
	}
	unsigned int firstCounter = 0,secondCounter = 0,thirdCounter = 0;
	while(firstCounter < firstSortedArray.size() && secondCounter < secondSortedArray.size() && thirdCounter < thirdSortedArray.size()){
		if(firstSortedArray[firstCounter]  == secondSortedArray[secondCounter] && firstSortedArray[firstCounter] == thirdSortedArray[thirdCounter]){
			commonElements.push_back(firstSortedArray[firstCounter]);
			firstCounter++;secondCounter++;thirdCounter++;
		}else{
			if(firstSortedArray[firstCounter] < secondSortedArray[secondCounter]){
				if(firstSortedArray[firstCounter] < thirdSortedArray[thirdCounter]){
					firstCounter++;
				}else{
					thirdCounter++;
				}
			}else{
				if(secondSortedArray[secondCounter] < thirdSortedArray[thirdCounter]){
					secondCounter++;
				}else{
					thirdCounter++;
				}
			}
		}
	}
	return commonElements;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(2^N) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* COMMONELEMENTSTHREESORTED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
