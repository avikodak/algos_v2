/****************************************************************************************************************************************************
 *  File Name                   : truncatableprimes.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\truncatableprimes.h
 *  Created on                  : Aug 15, 2015 :: 5:10:20 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=37
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

#ifndef TRUNCATABLEPRIMES_H_
#define TRUNCATABLEPRIMES_H_

//Tested
bool isNumberPrime(unsigned int userInput){
	unsigned int squareRoot = sqrtl(userInput);
	if(!(userInput&1)){
		return false;
	}
	for(unsigned int counter = 3;counter <= squareRoot;counter+=2){
		if(userInput%counter == 0){
			return false;
		}
	}
	return true;
}

//Tested
unsigned int getRevNumber(unsigned int userInput){
	unsigned int revNumber = 0;
	while(userInput){
		revNumber *= 10;
		revNumber += userInput%10;
		userInput /= 10;
	}
	return revNumber;
}

//Tested
bool isTruncatablePrime(unsigned int userInput,map<unsigned int,bool> primeNumberMap){
	if(userInput < 10){
		return false;
	}
	unsigned int revNumber = getRevNumber(userInput);
	while(userInput){
		if(primeNumberMap.find(userInput) == primeNumberMap.end()){
			return false;
		}
		userInput /= 10;
	}
	while(revNumber){
		if(primeNumberMap.find(getRevNumber(revNumber)) == primeNumberMap.end()){
			return false;
		}
		revNumber /= 10;
	}
	return true;
}

//Tested
bool hasValidDigits(unsigned int userInput){
	while(userInput){
		if(userInput!= 2 && userInput%2 == 0){
			return false;
		}
		userInput /= 10;
	}
	return true;
}

//Tested
//Ans : 748317
void printSumTruncatablePrimes(){
	map<unsigned int,bool> primeNumberMap;
	map<unsigned int,bool>::iterator itToPrimeNumberMap;
	primeNumberMap.insert(pair<unsigned int,bool>(2,true));
	vector<unsigned int> validNumber;
	validNumber.push_back(2);
	for(unsigned int counter = 3;counter < 1000000;counter+=2){
		if(isNumberPrime(counter)){
			primeNumberMap.insert(pair<unsigned int,bool>(counter,true));
			if(hasValidDigits(counter)){
				validNumber.push_back(counter);
			}
		}
	}
	unsigned int sum = 0,totalPrimeCount = 11;
	for(unsigned int counter = 0;counter < validNumber.size() && totalPrimeCount;counter++){
		if(isTruncatablePrime(validNumber[counter],primeNumberMap)){
			sum += validNumber[counter];
			totalPrimeCount--;
		}
	}
	cout << sum << endl;
}

#endif /* TRUNCATABLEPRIMES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
