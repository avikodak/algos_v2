/****************************************************************************************************************************************************
 *  File Name   		: fourelementsforsum.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\fourelementsforsum.h
 *  Created on			: Nov 27, 2014 :: 8:00:32 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
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

#ifndef FOURELEMENTSFORSUM_H_
#define FOURELEMENTSFORSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N^2*LogN) Algorithm 															*/
/****************************************************************************************************************************************************/
//Tested
void mergeStep(vector<iValueIndex *> &userInput,int startIndex,int middleIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int firstCrawler = startIndex,secondCrawler = middleIndex + 1;
	vector<iValueIndex *> auxSpace;
	while(firstCrawler <= middleIndex || secondCrawler <= endIndex){
		if(firstCrawler > middleIndex || secondCrawler > endIndex){
			if(firstCrawler <= middleIndex){
				auxSpace.push_back(userInput[firstCrawler++]);
			}else{
				auxSpace.push_back(userInput[secondCrawler++]);
			}
		}else{
			if(userInput[firstCrawler]->value < userInput[secondCrawler]->value){
				auxSpace.push_back(userInput[firstCrawler++]);
			}else{
				auxSpace.push_back(userInput[secondCrawler++]);
			}
		}
	}
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		userInput[startIndex + counter] = auxSpace[counter];
	}
}

//Tested
void mergeSort(vector<iValueIndex *> &userInput,int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	mergeSort(userInput,startIndex,middleIndex);
	mergeSort(userInput,middleIndex+1,endIndex);
	mergeStep(userInput,startIndex,middleIndex,endIndex);
}

//Tested
iQuadruple *findFourValuesForON2LogN(vector<int> userInput,int sum){
	if(userInput.size() < 3){
		return null;
	}
	vector<iValueIndex *> auxSpace;
	int currentSum;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-1;outerCounter++){
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			auxSpace.push_back(new iValueIndex(userInput[outerCounter]+userInput[innerCounter],outerCounter,innerCounter));
		}
	}
	mergeSort(auxSpace,0,auxSpace.size()-1);
	unsigned int startCrawler = 0,endCrawler = auxSpace.size()-1;
	while(startCrawler < endCrawler){
		currentSum = auxSpace[startCrawler]->value + auxSpace[endCrawler]->value;
		if(currentSum == sum){
			return new iQuadruple(userInput[auxSpace[startCrawler]->firstValueIndex],userInput[auxSpace[startCrawler]->secondvalueIndex],userInput[auxSpace[endCrawler]->firstValueIndex],userInput[auxSpace[endCrawler]->secondvalueIndex]);
		}else if(currentSum < sum){
			startCrawler++;
		}else{
			endCrawler--;
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iQuadruple *findFourValuesForON3(vector<int> userInput,int sum){
	if(userInput.size() < 3){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int thirdCounter,fourthCounter;
	int currentSum;
	for(unsigned int firstCounter = 0;firstCounter < userInput.size()-3;firstCounter++){
		for(unsigned int secondCounter = firstCounter+1;secondCounter < userInput.size()-2;secondCounter++){
			thirdCounter = secondCounter+1;
			fourthCounter = userInput.size()-1;
			while(thirdCounter < fourthCounter){
				currentSum = userInput[firstCounter] + userInput[secondCounter] + userInput[thirdCounter] + userInput[fourthCounter];
				if(currentSum == sum){
					return new iQuadruple(userInput[firstCounter],userInput[secondCounter],userInput[thirdCounter],userInput[fourthCounter]);
				}else if(currentSum < sum){
					thirdCounter++;
				}else{
					fourthCounter--;
				}
			}
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^4) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
iQuadruple *findFourValuesForSum(vector<int> userInput,int sum){
	if(userInput.size() < 4){
		return null;
	}
	for(unsigned firstCounter = 0;firstCounter < userInput.size()-3;firstCounter++){
		for(unsigned int secondCounter = firstCounter+1;secondCounter < userInput.size()-2;secondCounter++){
			for(unsigned int thirdCounter = secondCounter+1;thirdCounter < userInput.size()-1;thirdCounter++){
				for(unsigned int fourthCounter = thirdCounter+1;fourthCounter < userInput.size();fourthCounter++){
					if(userInput[firstCounter] +  userInput[secondCounter] + userInput[thirdCounter] + userInput[fourthCounter] == sum){
						return new iQuadruple(userInput[firstCounter],userInput[secondCounter],userInput[thirdCounter],userInput[fourthCounter]);
					}
				}
			}
		}
	}
	return null;
}

#endif /* FOURELEMENTSFORSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
