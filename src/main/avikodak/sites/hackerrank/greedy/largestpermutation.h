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

#ifndef LARGESTPERMUTATION_H_
#define LARGESTPERMUTATION_H_

//Partially Tested
void largestPermutation(){
	unsigned int inputSize,noOfSwaps,input;
	scanf("%u %u",&inputSize,&noOfSwaps);
	vector<unsigned int> userInput;
	for(unsigned int counter = 0;counter < inputSize;counter++){
		scanf("%u",&input);
		userInput.push_back(input);
	}
	unsigned int maxElementIndex,innerCounter,total = 0;
	for(unsigned int outerCounter = 0;outerCounter < noOfSwaps && total < userInput.size();outerCounter++){
		innerCounter = outerCounter;
		maxElementIndex = outerCounter;
		for(;innerCounter < userInput.size();innerCounter++){
			if(userInput[maxElementIndex] < userInput[innerCounter]){
				maxElementIndex = innerCounter;
			}
		}
		if(maxElementIndex == outerCounter){
			outerCounter++;
		}else{
			swap(userInput[outerCounter],userInput[maxElementIndex]);
		}
		total++;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		printf("%u ",userInput[counter]);
	}
}

#endif /* LARGESTPERMUTATION_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
