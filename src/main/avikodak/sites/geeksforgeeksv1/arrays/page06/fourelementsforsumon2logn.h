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

#include "../../../geeksforgeeksv1/arrays/page06/fourelementsforsum.h"
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
