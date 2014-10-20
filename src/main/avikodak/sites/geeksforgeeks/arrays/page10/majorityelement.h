/****************************************************************************************************************************************************
 *  File Name   		: majorityelement.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\majorityelement.h
 *  Created on			: Oct 11, 2014 :: 11:20:57 AM
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

#ifndef MAJORITYELEMENT_H_
#define MAJORITYELEMENT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int majorityElementMooreVotingAlgo(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int frequency = 0,index = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == userInput[index]){
			frequency++;
		}else{
			if(frequency == 1){
				index = counter;
			}else{
				frequency--;
			}
		}
	}
	frequency = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == userInput[index]){
			frequency++;
		}
	}
	return frequency > userInput.size()/2?userInput[index]:INT_MIN;
}

int majorityElementONHashmap(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(frequencyMap.find(userInput[counter]) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
		}else{
			frequency[userInput[counter]] = 1;
		}
	}
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second > userInput.size()/2){
			return itToFrequencyMap->first;
		}
	}
	return INT_MIN;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int majorityElementONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	sort(userInput.begin(),userInput.end());
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int majorityElementON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	unsigned int outerCrawler,innerCrawler,frequency = 0;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		frequency = 0;
		for(innerCrawler = outerCrawler;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				frequency++;
			}
		}
		if(frequency > userInput.size()/2){
			return userInput[outerCrawler];
		}
	}
	return INT_MIN;
}

int getMajorityElementPreOrderBST(iftNode *ptr,unsigned int vectorSize){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->frequency > vectorSize/2){
		return ptr->value;
	}
	int leftResult = getMajorityElementPreOrderBST(ptr->left,vectorSize);
	if(leftResult == INT_MIN){
		return leftResult;
	}
	return getMajorityElementPreOrderBST(ptr->right,vectorSize);
}

int getMajorityElementON2BST(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	treeutils *utils = new treeutils();
	iftNode *rootBST = utils->getBSTFromVector(userInput);
	return getMajorityElementPreOrderBST(ptr,userInput.size());
}

#endif /* MAJORITYELEMENT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
