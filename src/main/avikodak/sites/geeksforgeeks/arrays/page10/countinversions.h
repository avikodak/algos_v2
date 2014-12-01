/****************************************************************************************************************************************************
 *  File Name   		: countinversions.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\countinversions.h
 *  Created on			: Nov 27, 2014 :: 6:30:16 PM
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

#ifndef COUNTINVERSIONS_H_
#define COUNTINVERSIONS_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int icMerge(vector<int> &userInput,int startIndex,int midIndex,int endIndex){
	int firstCrawler = startIndex,secondCrawler = midIndex+1;
	vector<int> temp;
	unsigned int inversionCount = 0;
	while(firstCrawler <= midIndex || secondCrawler <= endIndex){
		if(firstCrawler > midIndex || secondCrawler > endIndex){
			if(firstCrawler <= midIndex){
				temp.push_back(userInput[firstCrawler]);
				firstCrawler++;
			}else{
				temp.push_back(userInput[secondCrawler]);
				secondCrawler++;
			}
		}else{
			if(userInput[firstCrawler] < userInput[secondCrawler]){
				firstCrawler++;
			}else{
				secondCrawler++;
				inversionCount += midIndex - firstCrawler;
			}
		}
	}
	return inversionCount;
}

unsigned int inversionCount(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return 0;
	}
	if(startIndex == endIndex){
		return 0;
	}
	int middleIndex = (startIndex + endIndex)/2;
	unsigned int counter = inversionCount(userInput,startIndex,middleIndex);
	counter += inversionCount(userInput,middleIndex+1,endIndex);
	counter += icMerge(userInput,startIndex,middleIndex,endIndex);
	return counter;
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int countInversionsON2(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int inversionCount = 0;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(userInput[outerCounter] > userInput[innerCounter]){
				inversionCount++;
			}
		}
	}
	return inversionCount;
}

#endif /* COUNTINVERSIONS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
