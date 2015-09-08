/****************************************************************************************************************************************************
 *  File Name                   : equal.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\dp\equal.h
 *  Created on                  : Aug 5, 2015 :: 10:14:09 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.hackerrank.com/challenges/equal
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

#ifndef EQUAL_H_
#define EQUAL_H_

unsigned int getMinNumberOperations(vector<unsigned int> userInput){
	sort(userInput.begin(),userInput.end());
	unsigned int prevIndex = 1;
	while(prevIndex < userInput.size() && userInput[prevIndex] == userInput[0]){
		prevIndex++;
	}
	unsigned int minOperations = 0;
	if(prevIndex >= userInput.size()){
		return minOperations;
	}
	unsigned int difference,crawler = prevIndex;
	prevIndex = 0;
	unsigned int cummulativeIncrement = 0;
	while(crawler < userInput.size()){
		difference = (cummulativeIncrement + userInput[crawler]) - userInput[prevIndex];
		cummulativeIncrement = difference;
		minOperations += difference/5;
		difference = difference%5;
		minOperations += difference/2;
		difference = difference%2;
		minOperations += difference;
		prevIndex = crawler;
		crawler++;
	}
	return minOperations;
}

void printMinNumberOperations(){
	unsigned int testCases,inputSize,input;
	scanf("%u",&testCases);
	vector<unsigned int> userInput;
	while(testCases--){
		scanf("%u",&inputSize);
		userInput.clear();
		while(inputSize--){
			scanf("%u",&input);
			userInput.push_back(input);
		}
		cout << getMinNumberOperations(userInput) << endl;
	}
}


#endif /* EQUAL_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
