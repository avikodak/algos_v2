/****************************************************************************************************************************************************
 *  File Name                   : nonabundantsums.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\nonabundantsums.h
 *  Created on                  : Aug 15, 2015 :: 8:15:31 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=23
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

#ifndef NONABUNDANTSUMS_H_
#define NONABUNDANTSUMS_H_

//Tested
map<long long int,long long int> primeFactorization(long long int userInput){
	long long int squareRoot = sqrtl(userInput);
	map<long long int,long long int> factorsCounter;
	map<long long int,long long int>::iterator itToFactorsCount;
	bool flag = true;
	while(flag && userInput > 1){
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
		if(!flag){
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
unsigned long long int pow(long long int base,long long int power){
	if(power == 0){
		return 1;
	}
	unsigned long long int result = 1;
	for(long long int counter = 0;counter < power;counter++){
		result *= base;
	}
	return result;
}

//Tested
unsigned long long int rhoFunction(long long int base,long long int power){
 	return ((pow(base,power+1))-1)/(base-1);
}

//Tested
unsigned long long int getSumOfDivisors(unsigned int value,bool properDivisor){
	map<long long int,long long int> primeFactors = primeFactorization(value);
	map<long long int,long long int>::iterator itToPrimeFactors;
	unsigned long long int sumOfDivisors = 1;
	for(itToPrimeFactors = primeFactors.begin();itToPrimeFactors != primeFactors.end();itToPrimeFactors++){
		sumOfDivisors *= rhoFunction(itToPrimeFactors->first,itToPrimeFactors->second);
	}
	if(!properDivisor){
		sumOfDivisors -= value;
	}
	return sumOfDivisors;
}

//Tested
//Ans : 4179871
void getTwoNonSumAbundantNumbers(){
	unsigned int sumOfDivisors;
	vector<unsigned int> abundantNumbers;
	for(unsigned int counter = 12;counter < 28124;counter++){
		sumOfDivisors = getSumOfDivisors(counter,false);
		if(sumOfDivisors > counter){
			abundantNumbers.push_back(counter);
		}
	}
	unsigned int totalSum = 0,sum;
	int rearCrawler,frontCrawler = 0;
	bool flag;
	for(unsigned long int counter = 28123;counter < 28124;counter++){
		if(counter > abundantNumbers[0]){
			frontCrawler = 0;
			flag = true;
			rearCrawler = lower_bound(abundantNumbers.begin(),abundantNumbers.end(),counter)-abundantNumbers.begin();
			if(rearCrawler == abundantNumbers.size()){
				rearCrawler--;
			}
			while(frontCrawler <= rearCrawler){
				sum = abundantNumbers[frontCrawler]+ abundantNumbers[rearCrawler];
				if(sum == counter){
					flag = false;
					break;
				}else if(sum > counter){
					rearCrawler--;
				}else{
					frontCrawler++;
				}
			}
			if(flag){
				totalSum += counter;
			}
		}else{
			totalSum += counter;
		}
	}
	cout << totalSum << endl;
}

#endif /* NONABUNDANTSUMS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
