/****************************************************************************************************************************************************
 *  File Name   		: partitionproblem.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\partitionproblem.h
 *  Created on			: Dec 29, 2014 :: 12:53:07 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PARTITIONPROBLEM_H_
#define PARTITIONPROBLEM_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool partitionProblemDP(vector<int> userInput){
	if(userInput.size() == 0){
		return false;
	}
	int sum = sumVector(userInput);
	if(sum % 2 == 1){
		return false;
	}
	vector<vector<bool> > auxSpace(userInput.size());
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		auxSpace[counter].assign(sum+1,false);
	}
	for(unsigned int columnCounter = 0;columnCounter < auxSpace[0].size();columnCounter++){
		auxSpace[0][columnCounter] = false;
	}
	for(unsigned int rowCounter = 0;rowCounter < auxSpace.size();rowCounter++){
		auxSpace[rowCounter][0] = true;
	}
	for(unsigned int rowCounter = 1;rowCounter < auxSpace.size();rowCounter++){
		for(unsigned int columnCounter = 1;columnCounter < auxSpace[0].size();columnCounter++){
			auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter-1][columnCounter];
			if((int)columnCounter > userInput[rowCounter]){
				auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter][columnCounter] || auxSpace[rowCounter-1][columnCounter - userInput[rowCounter]];
			}
		}
	}
	return auxSpace[userInput.size()-1][sum/2];
}

/****************************************************************************************************************************************************/
/* 																O(2^N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool partitionProblemGenerateSets(vector<int> userInput,vector<int> subset,int requiredSum,unsigned int currentIndex){
	if(currentIndex > userInput.size()){
		return false;
	}
	if(currentIndex == userInput.size()){
		return sumVector(subset) == requiredSum;
	}
	bool truthValue = partitionProblemGenerateSets(userInput,subset,requiredSum,currentIndex+1);
	subset.push_back(userInput[currentIndex]);
	return truthValue || partitionProblemGenerateSets(userInput,subset,requiredSum,currentIndex+1);
}

bool partitionProblemGenerateSetsIterative(vector<int> userInput){
	if(userInput.size() == 0){
		return false;
	}
	int limit = pow(2,userInput.size());
	int sum = sumVector(userInput),currentSum;
	vector<int> subset;
	for(int subsetCounter = 0;subsetCounter < limit;subsetCounter++){
		subset.clear();
		for(unsigned int bitCounter = 0;bitCounter < userInput.size();bitCounter++){
			if(subsetCounter & 1 << bitCounter){
				subset.push_back(userInput[bitCounter]);
			}
		}
		currentSum = sumVector(subset);
		if(currentSum == sum/2){
			return true;
		}
	}
	return false;
}

#endif /* PARTITIONPROBLEM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
