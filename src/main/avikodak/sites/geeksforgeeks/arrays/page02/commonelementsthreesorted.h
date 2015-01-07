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
