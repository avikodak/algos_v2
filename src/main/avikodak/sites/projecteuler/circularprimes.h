/****************************************************************************************************************************************************
 *  File Name                   : circularprimes.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\circularprimes.h
 *  Created on                  : Aug 15, 2015 :: 12:05:08 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=35
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

#ifndef CIRCULARPRIMES_H_
#define CIRCULARPRIMES_H_

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
unsigned int totalDigitCount(unsigned int userInput,unsigned int &multiplier){
	unsigned int digitCounter = 0;
	while(userInput){
		digitCounter++;
		userInput /= 10;
		multiplier *= 10;
	}
	return digitCounter;
}

//Tested
unsigned int shiftRight(unsigned int userInput,unsigned int multiplier){
	unsigned int lastDigit = userInput%10;
	userInput/=10;
	unsigned int sum = multiplier*lastDigit;
	userInput = userInput + sum;
	return userInput;
}

//Tested
bool isNumberCircular(unsigned int userInput,map<unsigned int,bool> primeNumberMap){
	unsigned int multiplier = 1;
	unsigned int digitCount = totalDigitCount(userInput,multiplier);
	if(digitCount == 1){
		return true;
	}
	for(unsigned int counter = 0;counter < digitCount;counter++){
		userInput = shiftRight(userInput,multiplier/10);
		if(primeNumberMap.find(userInput) == primeNumberMap.end()){
			return false;
		}
	}
	return true;
}

//Tested
bool hasValidDigits(unsigned int userInput){
	if(userInput == 5 || userInput == 2){
		return true;
	}
	while(userInput){
		if(userInput%2 == 0 || userInput%10 == 5){
			return false;
		}
		userInput /= 10;
	}
	return true;
}

//Tested
//Ans : 55
void getCircularPrimeCount(){
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
	unsigned int totalCount = 0;
	for(unsigned int counter = 0;counter < validNumber.size();counter++){
		if(isNumberCircular(validNumber[counter],primeNumberMap)){
			totalCount++;
		}
	}
	cout << totalCount << endl;
}

#endif /* CIRCULARPRIMES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
