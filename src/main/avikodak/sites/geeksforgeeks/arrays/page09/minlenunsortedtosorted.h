/****************************************************************************************************************************************************
 *  File Name   		: minlenunsortedtosorted.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\minlenunsortedtosorted.h
 *  Created on			: Nov 27, 2014 :: 5:10:49 PM
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

#ifndef MINLENUNSORTEDTOSORTED_H_
#define MINLENUNSORTEDTOSORTED_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int minimumLengthUnsortedToSorted(vector<int> userInput){
	if(userInput.size() < 2){
		return 0;
	}
	int frontCrawler = 1,rearCrawler = userInput.size()-2,startIndex = 0,endIndex = userInput.size()-1;
	while(frontCrawler < userInput.size() && userInput[frontCrawler] > userInput[frontCrawler-1]){
		frontCrawler++;
	}
	if(frontCrawler >= userInput.size()){
		return 0;
	}
	while(rearCrawler > 0 && userInput[rearCrawler] < userInput[rearCrawler+1]){
		rearCrawler--;
	}
	int maxElement = INT_MIN,minElement = INT_MAX;
	for(unsigned int counter = frontCrawler;counter <= rearCrawler;counter++){
		maxElement = max(maxElement,userInput[counter]);
		minElement = min(minElement,userInput[counter]);
	}
	while(userInput[startIndex] < minElement){
		startIndex++;
	}
	while(userInput[endIndex] > maxElement){
		rearCrawler--;
	}
	return rearCrawler - frontCrawler + 1;
}


/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int minLengthUnsortedToSorted(vector<int> userInput){
	if(userInput.size() < 2){
		return 0;
	}
	vector<int> auxSpace;
	copy(userInput.begin(),userInput.end(),auxSpace.begin());
	sort(auxSpace.begin(),auxSpace.end());
	int frontIndex = 0,rearIndex = userInput.size()-1;
	while(frontIndex < auxSpace.size() && userInput[frontIndex] == auxSpace[frontIndex]){
		frontIndex++;
	}
	if(frontIndex >= userInput.size()){
		return 0;
	}
	while(rearIndex >= 0 && userInput[rearIndex] == auxSpace[rearIndex]){
		rearIndex--;
	}
	return rearIndex - frontIndex + 1;
}

#endif /* MINLENUNSORTEDTOSORTED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
