/****************************************************************************************************************************************************
 *  File Name   		: tripletforsum.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\tripletforsum.h
 *  Created on			: Nov 27, 2014 :: 7:58:22 PM
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

#ifndef TRIPLETFORSUM_H_
#define TRIPLETFORSUM_H_

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
iTriplet *getTripletForSumON3(vector<int> userInput,int sum){
	if(userInput.size() < 3){
		return null;
	}
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-2;outerCounter++){
		for(unsigned int middleCounter = outerCounter+1;middleCounter < userInput.size()-1;middleCounter++){
			for(unsigned int innerCounter = middleCounter+1;innerCounter < userInput.size();innerCounter++){
				if(userInput[outerCounter] + userInput[middleCounter] + userInput[innerCounter] == sum){
					return new iTriplet(userInput[outerCounter],userInput[middleCounter],userInput[innerCounter]);
				}
			}
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
iTriplet *getTripletForSumON2(vector<int> userInput,int sum){
	if(userInput.size() < 3){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	int currentSum;
	unsigned int startCrawler,endCrawler;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-2;outerCounter++){
		startCrawler = outerCounter + 1;
		endCrawler = userInput.size()-1;
		while(startCrawler < endCrawler){
			currentSum = userInput[outerCounter] + userInput[startCrawler] + userInput[endCrawler];
			if(currentSum  == sum){
				return new iTriplet(userInput[outerCounter],userInput[startCrawler],userInput[endCrawler]);
			}else if(currentSum > sum){
				endCrawler--;
			}else{
				startCrawler++;
			}
		}
	}
	return null;
}

#endif /* TRIPLETFORSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
