/****************************************************************************************************************************************************
 *  File Name   		: fourelementsforsumon2logn.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page06\fourelementsforsumon2logn.h
 *  Created on			: Nov 30, 2014 :: 10:11:29 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/
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

#include "fourelementsforsum.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef FOURELEMENTSFORSUMON2LOGN_H_
#define FOURELEMENTSFORSUMON2LOGN_H_

/****************************************************************************************************************************************************/
/* 																O(N^2*logn) Algorithm 																*/
/****************************************************************************************************************************************************/
//Tested
iQuadruple *findFourElementsON2LogN(vector<int> userInput,int sum){
	if(userInput.size() < 3){
		return null;
	}
	vector<iValueIndex *> auxSpace;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-1;outerCounter++){
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			auxSpace.push_back(new iValueIndex(userInput[outerCounter]+userInput[innerCounter],outerCounter,innerCounter));
		}
	}
	mergeSort(auxSpace,0,auxSpace.size()-1);
	int firstCrawler = 0,secondCrawler = auxSpace.size()-1;
	int currentSum = 0;
	while(firstCrawler < secondCrawler){
		currentSum = auxSpace[firstCrawler]->value + auxSpace[secondCrawler]->value;
		if(currentSum == sum){
			return new iQuadruple(userInput[auxSpace[firstCrawler]->firstValueIndex],userInput[auxSpace[firstCrawler]->secondvalueIndex],userInput[auxSpace[secondCrawler]->firstValueIndex],userInput[auxSpace[secondCrawler]->secondvalueIndex]);
		}else if(currentSum < sum){
			firstCrawler++;
		}else{
			secondCrawler--;
		}
	}
	return null;
}

#endif /* FOURELEMENTSFORSUMON2LOGN_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
