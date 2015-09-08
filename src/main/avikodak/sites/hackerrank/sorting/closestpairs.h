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
