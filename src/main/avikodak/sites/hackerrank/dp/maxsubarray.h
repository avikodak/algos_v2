/****************************************************************************************************************************************************
 *  File Name                   : maxsubarray.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\dp\maxsubarray.h
 *  Created on                  : Jun 13, 2015 :: 10:39:20 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/maxsubarray
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

#ifndef MAXSUBARRAY_H_
#define MAXSUBARRAY_H_

//Tested
void getMaxSubArray(vector<int> userInput){
	int currentSum = 0,maxSubArraySum=INT_MIN,maxNegVal = INT_MIN,maxNonSubArraySum = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		currentSum = max(userInput[counter],currentSum+userInput[counter]);
		maxSubArraySum = max(maxSubArraySum,currentSum);
		if(userInput[counter] > 0){
			maxNonSubArraySum += userInput[counter];
		}else{
			maxNegVal = max(maxNegVal,userInput[counter]);
		}
	}
	printf("%d %d\n",maxSubArraySum,maxNonSubArraySum == 0?maxNegVal:maxNonSubArraySum);
}

//Tested
void printMaxSubArray(){
	unsigned int testCases,noOfElements;
	int input;
	scanf("%u",&testCases);
	vector<int> userInput;
	while(testCases--){
		scanf("%u",&noOfElements);
		userInput.clear();
		while(noOfElements--){
			scanf("%d",&input);
			userInput.push_back(input);
		}
		getMaxSubArray(userInput);
	}
}

#endif /* MAXSUBARRAY_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
