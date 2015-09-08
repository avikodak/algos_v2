/****************************************************************************************************************************************************
 *  File Name                   : largestpermutation.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\greedy\largestpermutation.h
 *  Created on                  : Jul 17, 2015 :: 2:10:36 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/largest-permutation
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

#ifndef LARGESTPERMUTATION_H_
#define LARGESTPERMUTATION_H_

//Tested
void largestPermutation(){
	unsigned int inputSize,noOfSwaps,input;
	scanf("%u %u",&inputSize,&noOfSwaps);
	vector<unsigned int> userInput;
	for(unsigned int counter = 0;counter < inputSize;counter++){
		scanf("%u",&input);
		userInput.push_back(input);
	}
	unsigned int maxElementIndex,innerCounter,swapCount = 0;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size() && swapCount < noOfSwaps;outerCounter++){
		innerCounter = outerCounter;
		maxElementIndex = outerCounter;
		for(;innerCounter < userInput.size();innerCounter++){
			if(userInput[maxElementIndex] < userInput[innerCounter]){
				maxElementIndex = innerCounter;
			}
		}
		if(maxElementIndex != outerCounter){
			swap(userInput[outerCounter],userInput[maxElementIndex]);
			swapCount++;
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		printf("%u ",userInput[counter]);
	}
}

#endif /* LARGESTPERMUTATION_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
