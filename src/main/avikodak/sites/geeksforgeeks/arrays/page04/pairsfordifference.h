/****************************************************************************************************************************************************
 *  File Name   		: pairsfordifference.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page03\pairsfordifference.h
 *  Created on			: Dec 22, 2014 :: 8:16:10 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/count-pairs-difference-equal-k/
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

#ifndef PAIRSFORDIFFERENCE_H_
#define PAIRSFORDIFFERENCE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getCountForDifferenceKON(vector<int> userInput,int difference){
	if(userInput.size() == 0){
		return 0;
	}
	hash_map<int,bool> visitedFlags;
	hash_map<int,bool>::iterator itToVisitedFlags;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		visitedFlags.insert(pair<int,bool>(userInput[counter],true));
	}
	int pairCounter = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		itToVisitedFlags = visitedFlags.find(difference - userInput[counter]);
		if(itToVisitedFlags != visitedFlags.end()){
			pairCounter++;
			visitedFlags.erase(difference - userInput[counter]);
			visitedFlags.erase(itToVisitedFlags->first);
		}else{
			itToVisitedFlags = visitedFlags.find(userInput[counter] - difference);
			if(itToVisitedFlags != visitedFlags.end()){
				pairCounter++;
				visitedFlags.erase(userInput[counter] - difference);
				visitedFlags.erase(itToVisitedFlags->first);
			}
		}
	}
	return pairCounter;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getCountForDifferenceKONLOGN(vector<int> userInput,int difference){
	if(userInput.size() < 2){
		return 0;
	}
	sort(userInput.begin(),userInput.end());
	int currentDifference,pairCounter = 0;
	unsigned int frontCrawler = 0,rearCrawler = 0;
	while(frontCrawler < userInput.size() && rearCrawler < userInput.size()){
		currentDifference = userInput[rearCrawler] - userInput[frontCrawler];
		if(currentDifference == difference){
			pairCounter += 1;
			frontCrawler++;
			rearCrawler++;
		}else if(currentDifference > difference){
			frontCrawler++;
		}else{
			rearCrawler++;
		}
	}
	return pairCounter;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getCountForDifferenceKON2(vector<int> userInput,int difference){
	if(userInput.size() < 2){
		return 0;
	}
	int pairCounter = 0;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-1;outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(abs(userInput[outerCrawler] - userInput[innerCrawler]) == abs(difference)){
				pairCounter++;
			}
		}
	}
	return pairCounter;
}

#endif /* PAIRSFORDIFFERENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
