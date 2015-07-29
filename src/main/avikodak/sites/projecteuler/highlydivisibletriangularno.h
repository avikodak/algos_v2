/****************************************************************************************************************************************************
 *  File Name                   : highlydivisibletriangularno.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\highlydivisibletriangularno.h
 *  Created on                  : Jul 29, 2015 :: 3:21:05 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=12
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

#ifndef HIGHLYDIVISIBLETRIANGULARNO_H_
#define HIGHLYDIVISIBLETRIANGULARNO_H_

//Tested
map<long long int,long long int> primeFactorization(long long int userInput){
	long long int squareRoot = sqrtl(userInput);
	map<long long int,long long int> factorsCounter;
	map<long long int,long long int>::iterator itToFactorsCount;
	bool flag = true;
	while(flag){
		flag = false;
		while(!(userInput&1)){
			if((itToFactorsCount = factorsCounter.find(2)) == factorsCounter.end()){
				factorsCounter[2] = 1;
			}else{
				factorsCounter[2]++;
			}
			flag = true;
			userInput /= 2;
		}
		for(long long int counter = 3;counter <= squareRoot;counter+=2){
			if(userInput%counter == 0){
				if(factorsCounter.find(counter) == factorsCounter.end()){
					factorsCounter[counter] = 1;
				}else{
					factorsCounter[counter]++;
				}
				flag = true;
				userInput /= counter;
				break;
			}
		}
		if(!flag && userInput != 1){
			if(factorsCounter.find(userInput) == factorsCounter.end()){
				factorsCounter[userInput] = 1;
			}else{
				factorsCounter[userInput]++;
			}
		}
	}
	return factorsCounter;
}

//Tested
long long int getDivisorsCount(unsigned int value,bool properDivisorCount){
	map<long long int,long long int> primeFactors = primeFactorization(value);
	long long int divisorCount = 1;
	map<long long int,long long int>::iterator itToPrimeFactors;
	for(itToPrimeFactors = primeFactors.begin();itToPrimeFactors != primeFactors.end();itToPrimeFactors++){
		divisorCount *= (itToPrimeFactors->second+1);
	}
	return !properDivisorCount?divisorCount:divisorCount-1;
}

//Tested
//Ans : 76576500
void getNumberWithFiveHundredDivisor(){
	long long int value,counter  = 1,divisorCount;
	while(true){
		value = ((counter)*(counter+1))/2;
		divisorCount = getDivisorsCount(value,false);
		if(divisorCount > 500){
			cout << value;
			break;
		}
		counter++;
	}
}

#endif /* HIGHLYDIVISIBLETRIANGULARNO_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
