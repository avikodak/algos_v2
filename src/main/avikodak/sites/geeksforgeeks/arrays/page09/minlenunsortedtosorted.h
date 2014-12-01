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
