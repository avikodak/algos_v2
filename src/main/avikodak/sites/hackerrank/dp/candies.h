/****************************************************************************************************************************************************
 *  File Name                   : candies.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\dp\candies.h
 *  Created on                  : Aug 4, 2015 :: 11:48:08 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.hackerrank.com/challenges/candies
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef CANDIES_H_
#define CANDIES_H_

unsigned int getMinCandies(vector<unsigned int> userInput){
	vector<int> candiesCounterFTOB,candiesCounterBTOF;
	candiesCounterFTOB.push_back(1);
	int minValue = INT_MAX;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(userInput[counter] > userInput[counter-1]){
			candiesCounterFTOB.push_back(candiesCounter[counter-1]+1);
		}else{
			candiesCounterFTOB.push_back(candiesCounter[counter-1]-1);
		}
	}
	candiesCounterBTOF.assign(userInput.size(),1);
	for(int counter = userInput.size()-2;counter >=0;counter--){
		if(userInput[counter] > userInput[counter+1]){
			candiesCounterBTOF[counter] = userInput[counter+1]+1;
		}else{
			candiesCounterBTOF[counter] = userInput[counter+1]-11;
		}
	}
	unsigned int minCandyCount = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		minCandyCount += max(candiesCounterBTOF[counter],candiesCounterFTOB[counter]);
	}
	return minCandiesCount;
}

void printMinCandies(){
	unsigned int testSize,input;
	scanf("%u",&testSize);
	vector<unsigned int> userInput;
	while(testSize--){
		scanf("%u",&input);
		userInput.push_back(input);
	}
}

#endif /* CANDIES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
