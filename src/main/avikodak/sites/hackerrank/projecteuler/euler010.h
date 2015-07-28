/****************************************************************************************************************************************************
 *  File Name                   : euler010.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\projecteuler\euler010.h
 *  Created on                  : Jul 28, 2015 :: 10:29:51 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/contests/projecteuler/challenges/euler010
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

#ifndef EULER010_H_
#define EULER010_H_

//Tested
bool isNumberPrime(long long int userInput){
	long long int squareRoot = sqrtl(userInput);
	if(!(userInput&1)){
		return false;
	}
	for(long long int counter = 3;counter <= squareRoot;counter+=2){
		if(userInput%counter == 0){
			return false;
		}
	}
	return true;
}

//Tested
void printSum(long long int limit){
	if(limit < 2){
		printf("0\n");
        return;
	}
	long long int sum = 2;
	for(long long int counter = 3;counter <= limit;counter++){
		if(isNumberPrime(counter)){
			sum += counter;
		}
	}
	cout << sum << endl;
}

//Tested
void getSummationOfPrimes(){
	unsigned int testCases;
	scanf("%u",&testCases);
	long long int input;
	while(testCases--){
		cin >> input;
		printSum(input);
	}
}

#endif /* EULER010_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
