/****************************************************************************************************************************************************
 *  File Name   		: segregate0s1s.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\segregate0s1s.h
 *  Created on			: Nov 25, 2014 :: 11:42:21 PM
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

#ifndef SEGREGATE0S1S_H_
#define SEGREGATE0S1S_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void segregate0s1s(vector<bool> userInput){
	if(userInput.size() < 2){
		return;
	}
	unsigned int zeroFrequency = 0,oneFrequency = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(!userInput[counter]){
			zeroFrequency += 1;
		}else{
			oneFrequency += 1;
		}
	}
	int fillCounter = -1;
	while(zeroFrequency--){
		userInput[++fillCounter] = 0;
	}
	while(oneFrequency--){
		userInput[++fillCounter] = 1;
	}
}

void segregate0s1sQuickSortDivideMethod(vector<bool> userInput){
	int startIndex = 0,endIndex = userInput.size()-1;
	while(startIndex < endIndex){
		while(!userInput[startIndex]){
			startIndex++;
		}
		while(userInput[endIndex]){
			endIndex--;
		}
		if(startIndex < endIndex){
			userInput[startIndex] = false;
			userInput[endIndex] = true;
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

void merge(vector<int> &userInput,int startIndex,int middleIndex,int endIndex){
	int firstCrawler = startIndex,secondCrawler = middleIndex+1;
	vector<int> temp;
	while(firstCrawler <= middleIndex || secondCrawler <= endIndex){
		if(firstCrawler > middleIndex || secondCrawler > endIndex){
			if(firstCrawler <= middleIndex){
				temp.push_back(userInput[firstCrawler]);
				firstCrawler++;
			}else{
				temp.push_back(userInputp[secondCrawler]);
				secondCrawler++;
			}
		}else{
			if(userInput[firstCrawler] < userInput[secondCrawler]){
				temp.push_back(userInput[firstCrawler]);
				firstCrawler++;
			}else{
				temp.push_back(userInput[secondCrawler]);
				secondCrawler++;
			}
		}
	}
	for(unsigned int counter = 0;counter < temp.size();counter++){
		userInput[startIndex+counter] = temp[counter];
	}
}

void mergeSort(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	mergeSort(userInput,startIndex,middleIndex);
	mergeSort(userInput,middleIndex+1,endIndex);
	merge(userInput,startIndex,middleIndex,endIndex);
}

void segregate0s1s(vector<int> userInput){
	if(userInput.size() < 2){
		return;
	}
	mergeSort(userInput,0,userInput.size()-1);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void segregate0s1sON2(vector<bool> userInput){
	if(userInput.size() < 2){
		return;
	}
	int innerCounter;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		if(userInput[outerCounter]){
			for(innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
				if(!userInput[innerCounter]){
					break;
				}
			}
			if(innerCounter < userInput.size()){
				userInput[outerCounter] = false;
				userInput[innerCounter] = true;
			}else{
				break;
			}
		}
	}
}

#endif /* SEGREGATE0S1S_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
