/****************************************************************************************************************************************************
 *  File Name   		: closestpairs.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\sorting\closestpairs.h
 *  Created on			: Feb 12, 2015 :: 4:41:37 PM
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

#ifndef CLOSESTPAIRS_H_
#define CLOSESTPAIRS_H_

//Tested
long int min(long int firstVal,long int secondVal){
	return firstVal < secondVal?firstVal:secondVal;
}

//Tested
void printClosestPairs(){
	long int size,input;
	vector<long int> userInput;
	scanf("%ld",&size);
	while(size--){
		scanf("%ld",&input);
		userInput.push_back(input);
	}
	stable_sort(userInput.begin(),userInput.end());
	long int minVal = INT_MAX;
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		minVal = min(minVal,abs(userInput[counter+1] - userInput[counter]));
	}
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		if(abs(userInput[counter+1] - userInput[counter]) == minVal){
			printf("%ld %ld ",userInput[counter],userInput[counter+1]);
		}
	}
}

#endif /* CLOSESTPAIRS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
