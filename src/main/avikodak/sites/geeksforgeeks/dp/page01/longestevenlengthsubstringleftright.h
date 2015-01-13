/****************************************************************************************************************************************************
 *  File Name   		: longestevenlengthsubstringleftright.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page01\longestevenlengthsubstringleftright.h
 *  Created on			: Jan 13, 2015 :: 9:06:42 AM
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

#ifndef LONGESTEVENLENGTHSUBSTRINGLEFTRIGHT_H_
#define LONGESTEVENLENGTHSUBSTRINGLEFTRIGHT_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
int longestEvenLengthSubStringLeftRightSum(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size()%2 != 0){
		return 0;
	}
	int currentSubstringLength,leftSum,rightSum;
	int maxLength = INT_MIN;
	for(int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		for(int middleCounter = outerCounter+1;middleCounter < userInput.size();middleCounter++){
			currentSubstringLength = middleCounter - outerCounter + 1;
			leftSum = 0;
			rightSum = 0;
			for(int innerCounter = 0;innerCounter < currentSubstringLength/2;innerCounter++){
				leftSum += userInput[outerCounter + innerCounter];
				rightSum += userInput[outerCounter + currentSubstringLength/2 + innerCounter];
			}
			if(leftSum == rightSum){
				maxLength = max(maxLength,middleCounter - outerCounter + 1);
			}
		}
	}
	return maxLength;
}

#endif /* LONGESTEVENLENGTHSUBSTRINGLEFTRIGHT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
