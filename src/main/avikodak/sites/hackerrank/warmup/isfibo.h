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

#ifndef ISFIBO_H_
#define ISFIBO_H_

//Tested
void isNumberFibonacci() {
    vector<long int> fibonacciSequence;
    fibonacciSequence.push_back(0);
    fibonacciSequence.push_back(1);
    fibonacciSequence.push_back(1);
    int testCases;
    long int input,prevVal,prevPrevVal,nextVal;
    scanf("%d",&testCases);
    while(testCases--) {
        scanf("%ld",&input);
        if(fibonacciSequence[fibonacciSequence.size()-1] >= input) {
            if(binary_search(fibonacciSequence.begin(),fibonacciSequence.end(),input)) {
                printf("IsFibo\n");
            } else {
                printf("IsNotFibo\n");
            }
        } else {
            prevVal = fibonacciSequence[fibonacciSequence.size()-1];
            prevPrevVal = fibonacciSequence[fibonacciSequence.size()-2];
            while(true) {
                nextVal = prevVal + prevPrevVal;
                prevPrevVal = prevVal;
                prevVal = nextVal;
                fibonacciSequence.push_back(nextVal);
                if(nextVal >= input) {
                    if(nextVal == input) {
                        printf("IsFibo\n");
                    } else {
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
