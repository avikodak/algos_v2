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
