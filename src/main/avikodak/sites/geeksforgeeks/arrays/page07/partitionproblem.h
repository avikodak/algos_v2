/****************************************************************************************************************************************************
 *  File Name   		: partitionproblem.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\partitionproblem.h
 *  Created on			: Dec 29, 2014 :: 12:53:07 PM
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
	int requiredSum = sum/2;
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
			if(columnCounter > userInput[rowCounter]){
				auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter][columnCounter] || auxSpace[rowCounter-1][columnCounter - userInput[rowCounter]];
			}
		}
	}
	return auxSpace[userInput.size()-1][sum/2];
}

/****************************************************************************************************************************************************/
/* 																O(2^N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool partitionProblemGenerateSets(vector<int> userInput,vector<int> subset,int requiredSum,int currentIndex){
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
