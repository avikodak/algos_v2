/****************************************************************************************************************************************************
 *  File Name   		: arestringsanagrams.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page04\arestringsanagrams.h
 *  Created on			: Jan 16, 2015 :: 10:06:56 AM
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

#ifndef ARESTRINGSANAGRAMS_H_
#define ARESTRINGSANAGRAMS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool areStringsAnagramsON(char *firstUserInput,char *secondUserInput){
	if(firstUserInput == '\0' && secondUserInput == '\0'){
		return true;
	}
	int firstLength = strlen(firstUserInput),secondLength = strlen(secondUserInput);
	if(firstLength != secondLength){
		return false;
	}
	hash_map<char,unsigned int> frequencyMap;
	hash_map<char,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < firstLength;counter++){
		if((itToFrequencyMap = frequencyMap.find(firstUserInput[counter])) == frequencyMap.end()){
			frequencyMap[firstUserInput[counter]] = 1;
		}else{
			frequencyMap[firstUserInput[counter]] += 1;
		}
	}
	for(unsigned int counter = 0;counter < secondLength;counter++){
		if((itToFrequencyMap = frequencyMap.find(secondUserInput[counter])) == frequencyMap.end()){
			return false;
		}
		if(itToFrequencyMap->second == 1){
			frequencyMap.erase(secondUserInput[counter]);
		}else{
			itToFrequencyMap->second -= 1;
		}
	}
	return frequencyMap.size() == 0;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
bool areStringsAnagramONLOGN(char *firstUserInput,char *secondUserInput){
	if(firstUserInput == '\0' && secondUserInput == '\0'){
		return true;
	}
	char *firstCrawler = firstUserInput,*secondCrawler = secondUserInput;
	while(firstCrawler[0] != '\0' && secondCrawler[0] != '\0'){
		if(firstCrawler[0] != secondCrawler[0]){
			return false;
		}
		firstCrawler++;
		secondCrawler++;
	}
	return firstCrawler[0] == '\0' && secondCrawler[0] == '\0';
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* ARESTRINGSANAGRAMS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
