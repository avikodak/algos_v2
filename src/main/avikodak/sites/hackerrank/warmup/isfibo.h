/****************************************************************************************************************************************************
 *  File Name   		: isfibo.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\warmup\isfibo.h
 *  Created on			: Feb 10, 2015 :: 9:39:28 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: https://www.hackerrank.com/challenges/is-fibo
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

#ifndef ISFIBO_H_
#define ISFIBO_H_

//Tested
void isNumberFibonacci(){
	vector<long int> fibonacciSequence;
	fibonacciSequence.push_back(0);
	fibonacciSequence.push_back(1);
	fibonacciSequence.push_back(1);
	int testCases;
	long int input,prevVal,prevPrevVal,nextVal;
	scanf("%d",&testCases);
	while(testCases--){
		scanf("%ld",&input);
		if(fibonacciSequence[fibonacciSequence.size()-1] >= input){
			if(binary_search(fibonacciSequence.begin(),fibonacciSequence.end(),input)){
				printf("IsFibo\n");
			}else{
				printf("IsNotFibo\n");
			}
		}else{
			prevVal = fibonacciSequence[fibonacciSequence.size()-1];
			prevPrevVal = fibonacciSequence[fibonacciSequence.size()-2];
			while(true){
				nextVal = prevVal + prevPrevVal;
				prevPrevVal = prevVal;
				prevVal = nextVal;
				fibonacciSequence.push_back(nextVal);
				if(nextVal >= input){
					if(nextVal == input){
						printf("IsFibo\n");
					}else{
						printf("IsNotFibo\n");
					}
					break;
				}
			}
		}
	}
}

#endif /* ISFIBO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
