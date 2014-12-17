/****************************************************************************************************************************************************
 *  File Name   		: longestcommonsubsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\longestcommonsubsequence.h
 *  Created on			: Dec 9, 2014 :: 7:39:32 PM
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

#ifndef LONGESTCOMMONSUBSEQUENCE_H_
#define LONGESTCOMMONSUBSEQUENCE_H_

int longestCommonSubSequence(char *firstUserInput,char *secondUserInput){
	if(firstUserInput == null || secondUserInput == null){
		return 0;
	}
	int firstUserInputLength,secondUserInputLength;
	firstUserInputLength = strlen(firstUserInput);
	secondUserInputLength = strlen(secondUserInput);
	vector<vector<int> > auxSpace(firstUserInputLength+1);
	for(unsigned int counter = 0;counter < auxSpace.size();counter++){
		auxSpace[counter].resize(secondUserInputLength+1);
	}
	for(unsigned int rowCounter = 0;rowCounter < auxSpace.size();rowCounter++){
		auxSpace[rowCounter][0] = 0;
	}
	for(unsigned int columnCounter = 0;columnCounter < auxSpace[0].size();columnCounter++){
		auxSpace[0][columnCounter] = 0;
	}
	for(unsigned int rowCounter = 1;rowCounter < auxSpace.size();rowCounter++){
		for(unsigned int columnCounter = 1;columnCounter < auxSpace[0].size();columnCounter++){
			if(firstUserInput[rowCounter-1] == secondUserInput[columnCounter-1]){
				auxSpace[rowCounter][columnCounter] = 1 + auxSpace[rowCounter-1][columnCounter-1];
			}else{
				auxSpace[rowCounter][columnCounter] = max(auxSpace[rowCounter-1][columnCounter],auxSpace[rowCounter][columnCounter-1]);
			}
		}
	}
	return auxSpace[auxSpace.size()-1][auxSpace[0].size()-1];
}

int longestCommonSubSequence(char *firstUserInput,char *secondUserInput){
	if(firstUserInput == null || secondUserInput == null){
		return 0;
	}
	if(firstUserInput[0] == secondUserInput[0]){
		return 1 + longestCommonSubSequence(firstUserInput+1,secondUserInput+1);
	}else{
		return max(longestCommonSubSequence(firstUserInput+1,secondUserInput),longestCommonSubSequence(firstUserInput,secondUserInput+1));
	}
}

#endif /* LONGESTCOMMONSUBSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
