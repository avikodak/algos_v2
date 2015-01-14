/****************************************************************************************************************************************************
 *  File Name   		: decodingsdigitsequence.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page01\decodingsdigitsequence.h
 *  Created on			: Jan 12, 2015 :: 11:11:56 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/
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

#ifndef DECODINGSDIGITSEQUENCE_H_
#define DECODINGSDIGITSEQUENCE_H_

//Tested
int noOfDecodingsDigitSequence(char *userInput,int length){
	if(length <= 1){
		return 1;
	}
	int counter = 0;
	if(userInput[length-1] != '0'){
		counter += noOfDecodingsDigitSequence(userInput,length-1);
	}
	if(userInput[length-2] < '2' || (userInput[length-2] == '2' && userInput[length-1] <'7')){
		counter += noOfDecodingsDigitSequence(userInput,length-2);
	}
	return counter;
}

//Tested
int noOfDecodingsDigitSequenceMemoization(char *userInput,int length){
	if(length <= 1){
		return 1;
	}
	vector<int> auxSpace;
	auxSpace.push_back(1);
	auxSpace.push_back(1);
	int total = 0;
	for(int counter = 2;counter <= length;counter++){
		total = 0;
		if(userInput[counter-1] != '0'){
			total += auxSpace[counter-1];
		}
		if(userInput[counter-2] < '2' || (userInput[counter-2] == '2' && userInput[counter-1] < '7')){
			total += auxSpace[counter-2];
		}
		auxSpace.push_back(total);
	}
	return auxSpace[auxSpace.size()-1];
}

#endif /* DECODINGSDIGITSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/