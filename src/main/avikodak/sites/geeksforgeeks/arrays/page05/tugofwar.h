/****************************************************************************************************************************************************
 *  File Name   		: tugofwar.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\tugofwar.h
 *  Created on			: Dec 25, 2014 :: 12:37:40 PM
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

#ifndef TUGOFWAR_H_
#define TUGOFWAR_H_

void tugOfWarMain(vector<int> userInput,int arraySum,int &minDifference,vector<int> &minSetIndices,vector<int> runningSet,int currentIndex,unsigned int kValue){
	if(kValue > userInput.size()){
		throw "Invalid K value";
	}
	if(kValue == 0){
		int currentSetSum = 0;
		for(unsigned int counter = 0;counter < runningSet.size();counter++){
			currentSetSum += userInput[runningSet[counter]];
		}
		if(minDifference > abs(2*currentSetSum - arraySum)){
			minSetIndices.clear();
			copy(runningSet.begin(),runningSet.end(),minSetIndices.begin());
			minDifference = abs(2*currentSetSum - arraySum);
		}
		return;
	}
	tugOfWarMain(userInput,arraySum,minDifference,minSetIndices,runningSet,currentIndex+1,kValue);
	runningSet.push_back(currentIndex);
	tugOfWarMain(userInput,arraySum,minDifference,minSetIndices,runningSet,currentIndex+1,kValue-1);
}

vector<vector<int> > tugOfWar(vector<int> userInput){
	vector<vector<int> > sets;
	if(userInput.size() == 0){
		return sets;
	}
	vector<int> firstSet,runningSet,secondSet;
	int minDifference = INT_MAX,arraySum = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		arraySum += userInput[counter];
	}
	tugOfWarMain(userInput,arraySum,minDifference,firstSet,runningSet,0,userInput.size()/2);
	unsigned int firstCrawler = 0,secondCrawler = 0;
	while(firstCrawler < userInput.size() || secondCrawler < firstSet.size()){
		if(secondCrawler > firstSet.size()){
			while(firstCrawler < userInput.size()){
				secondSet.push_back(firstCrawler++);
			}
			break;
		}else{
			if(firstSet[secondCrawler] == (int)firstCrawler){
				secondCrawler++;
				firstCrawler++;
			}else{
				secondSet.push_back(firstCrawler);
				firstCrawler++;
			}
		}
	}
	sets.push_back(firstSet);
	sets.push_back(secondSet);
	return sets;
}

#endif /* TUGOFWAR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
