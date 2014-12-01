/****************************************************************************************************************************************************
 *  File Name   		: fourelementsforsum.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\fourelementsforsum.h
 *  Created on			: Nov 27, 2014 :: 8:00:32 PM
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

#ifndef FOURELEMENTSFORSUM_H_
#define FOURELEMENTSFORSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N^2*LogN) Algorithm 															*/
/****************************************************************************************************************************************************/
bool sortFucnValueIndex(iValueIndex *firstPtr,iValueIndex *secondPtr){
	return firstPtr->value > secondPtr->value?true:false;
}

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
	sort(auxSpace.begin(),auxSpace.end(),sortFucnValueIndex);
	unsigned int startCrawler = 0,endCrawler = userInput.size()-1;
	while(startCrawler < endCrawler){
		currentSum = userInput[startCrawler] + userInput[endCrawler];
		if(currentSum == sum){
			return new iQuadruple(auxSpace[startCrawler]->firstValueIndex,auxSpace[startCrawler]->secondvalueIndex,auxSpace[endCrawler]->firstValueIndex,auxSpace[endCrawler]->secondvalueIndex);
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
iQuadruple *findFourValuesForON3(vector<int> userInput,int sum){
	if(userInput.size() < 3){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int thirdCounter,fourthCounter;
	int currentSum;
	for(unsigned int firstCounter = 0;firstCounter < userInput.size()-3;firstCounter++){
		for(unsigned int secondCounter = firstCounter;secondCounter < userInput.size()-2;secondCounter++){
			thirdCounter = secondCounter+1;
			fourthCounter = userInput.size()-1;
			while(thirdCounter < fourthCounter){
				currentSum = userInput[firstCounter] + userInput[secondCounter] + userInput[thirdCounter] + userInput[fourthCounter];
				if(currentSum == currentSum){
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
