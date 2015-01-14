/****************************************************************************************************************************************************
 *  File Name   		: minpalindromicsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page03\minpalindromicsequence.h
 *  Created on			: Jan 14, 2015 :: 1:26:42 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/
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

#ifndef MINPALINDROMICSEQUENCE_H_
#define MINPALINDROMICSEQUENCE_H_

//Tested
bool isStringPalindrome(char *userInput,int startIndex,int endIndex){
	if(startIndex == endIndex){
		return true;
	}
	while(startIndex < endIndex){
		if(userInput[startIndex] != userInput[endIndex]){
			return false;
		}
		startIndex++;
		endIndex--;
	}
	return true;
}

//Tested
int minPalindromicPartition(char *userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return 0;
	}
	if(startIndex == endIndex || isStringPalindrome(userInput,startIndex,endIndex)){
		return 0;
	}
	int minPartitions = INT_MAX;
	for(int counter = startIndex;counter < endIndex;counter++){
		minPartitions = min(minPartitions,1+minPalindromicPartition(userInput,startIndex,counter)+minPalindromicPartition(userInput,counter+1,endIndex));
	}
	return minPartitions;
}

//Tested
int minPalindromicPartitionsMemoization(char *userInput){
	if(userInput == null){
		return 0;
	}
	int length = strlen(userInput);
	vector<vector<bool> > flag(length);
	vector<vector<int> > auxSpace(length);
	for(int rowCounter = 0;rowCounter < length;rowCounter++){
		flag[rowCounter].assign(length,false);
		flag[rowCounter][rowCounter] = true;
		auxSpace[rowCounter].assign(length,0);
	}
	int innerCrawler,minPartitions;
	for(int lengthCounter = 2;lengthCounter <= length;lengthCounter++){
		for(int outerCrawler = 0;outerCrawler < length - lengthCounter+1;outerCrawler++){
			innerCrawler = outerCrawler + lengthCounter - 1;
			if(lengthCounter == 2){
				flag[outerCrawler][innerCrawler] = userInput[outerCrawler] == userInput[innerCrawler];
			}else{
				flag[outerCrawler][innerCrawler] = userInput[outerCrawler] == userInput[innerCrawler] && flag[outerCrawler+1][innerCrawler-1];
			}
			if(flag[outerCrawler][innerCrawler]){
				auxSpace[outerCrawler][innerCrawler] = 0;
			}else{
				minPartitions = INT_MAX;
				for(int counter = outerCrawler;counter < innerCrawler;counter++){
					minPartitions = min(minPartitions,1+auxSpace[outerCrawler][counter]+auxSpace[counter+1][innerCrawler]);
				}
				auxSpace[outerCrawler][innerCrawler] = minPartitions;
			}
		}
	}
	return auxSpace[0][length-1];
}

#endif /* MINPALINDROMICSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
