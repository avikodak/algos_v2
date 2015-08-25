/****************************************************************************************************************************************************
 *  File Name   		: mathutil.h 
 *	File Location		: D:\algos\algos_v2\src\lib\utils\mathutil.h
 *  Created on			: Oct 9, 2014 :: 12:39:05 PM
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef MATHUTIL_H_
#define MATHUTIL_H_

void isPrimeNumber(unsigned int userInput){
	for(unsigned int counter = 2;counter <= userInput/2;counter++){
		if(userInput%counter == 0){
			return false;
		}
	}
	return true;
}

void printPrimeNumbersBruteForce(unsigned int number){
	for(unsigned int counter = 2;counter <= number;counter++){
		if(isPrimeNumber(counter)){
			printf("%d,",counter);
		}
	}
}

//Tested
vector<unsigned int> sum(vector<vector<unsigned int> > userInputs){
	vector<unsigned int> result;
	if(userInputs.size() == 0){
		return result;
	}
	reverse(userInputs[0].begin(),userInputs[0].end());
	result = userInputs[0];
	unsigned int firstCrawler,secondCrawler,sum = 0,carry =0;
	for(unsigned int counter = 1;counter < userInputs.size();counter++){
		reverse(userInputs[counter].begin(),userInputs[counter].end());
		firstCrawler = secondCrawler = carry = 0;
		while(firstCrawler < result.size() && secondCrawler < userInputs[counter].size()){
			sum = result[firstCrawler] + userInputs[counter][secondCrawler] + carry;
			result[firstCrawler] = sum%10;
			firstCrawler++;
			secondCrawler++;
			carry = sum/10;
		}
		while(firstCrawler < result.size()){
			sum = result[firstCrawler] + carry;
			result[firstCrawler] = sum%10;
			carry = sum/10;
			firstCrawler++;
		}
		while(secondCrawler < userInputs[counter].size()){
			sum = userInputs[counter][secondCrawler] + carry;
			result.push_back(sum%10);
			carry = sum/10;
			secondCrawler++;
		}
		while(carry){
			result.push_back(carry%10);
			carry /= 10;
		}
	}
	reverse(result.begin(),result.end());
	return result;
}

//Tested
vector<unsigned int> sum(vector<unsigned int> first,vector<unsigned int> second){
	vector<vector<unsigned int> > userInput;
	userInput.push_back(first);
	userInput.push_back(second);
	return sum(userInput);
}

//Tested
vector<unsigned int> convertToDigits(string userInput){
	vector<unsigned int> number;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		number.push_back(userInput[counter]-'0');
	}
	return number;
}

//Tested
vector<unsigned int> multiply(vector<unsigned int> userInput,unsigned int digit){
	vector<unsigned int> result;
	reverse(userInput.begin(),userInput.end());
	unsigned int carry = 0,product;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		product = userInput[counter] * digit + carry;
		result.push_back(product%10);
		carry = product/10;
	}
	while(carry){
		result.push_back(carry%10);
		carry /= 10;
	}
	reverse(result.begin(),result.end());
	return result;
}

//Tested
vector<unsigned int> multiply(vector<unsigned int> firstUserInput,vector<unsigned int> secondUserInput){
	reverse(secondUserInput.begin(),secondUserInput.end());
	vector<unsigned int> result,temp;
	vector<vector<unsigned int> > input;
	for(unsigned int outerCounter = 0;outerCounter < secondUserInput.size();outerCounter++){
		temp = multiply(firstUserInput,secondUserInput[outerCounter]);
		if(result.size() == 0){
			result = temp;
		}else{
			for(unsigned int innerCounter = 0;innerCounter < outerCounter;innerCounter++){
				temp.push_back(0);
			}
			input.clear();
			input.push_back(result);
			input.push_back(temp);
			result = sum(input);
		}
	}
	return result;
}

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
bool isNumberPrime(long long int userInput){
	if(userInput == 1){
		return false;
	}
	if(userInput == 2){
		return true;
	}
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
long long int gcd(long long int firstUserInput,long long int secondUserInput){
	if(firstUserInput == 1 || secondUserInput == 1){
		return 1;
	}
	if(secondUserInput%firstUserInput == 0){
		return firstUserInput;
	}
	return gcd(secondUserInput%firstUserInput,firstUserInput);
}

//Tested
long long int gcd(vector<long long int> userInputs){
	if(userInputs.size() < 2){
		return 0;
	}
	long long int result = gcd(userInputs[0],userInputs[1]);
	for(unsigned int counter = 2;counter < userInputs.size();counter++){
		result = gcd(result,userInputs[counter]);
	}
	return result;
}

//Tested
long long int lcm(long long int first,long long int second){
	return (first*second)/gcd(first,second);
}

//Tested
long long int lcm(vector<long long int> userInputs){
	if(userInputs.size() < 2){
		return 0;
	}
	long long int lcm = (userInputs[0]*userInputs[1])/gcd(userInputs[0],userInputs[1]);
	for(unsigned int counter = 2;counter < userInputs.size();counter++){
		lcm = (lcm * userInputs[counter])/(gcd(userInputs[counter],lcm));
	}
	return lcm;
}

//Tested
long long int getSumOfDigits(vector<unsigned int> userInput){
	long long int sum = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		sum += userInput[counter];
	}
	return sum;
}

//Tested
vector<unsigned int> getUINTInVector(unsigned int number){
	vector<unsigned int> userInput;
	while(number){
		userInput.push_back(number%10);
		number /=10;
	}
	reverse(userInput.begin(),userInput.end());
	return userInput;
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
bool isPerfectSquare(unsigned long long int value){
	unsigned long long int squareRoot = sqrtl(value);
	return squareRoot*squareRoot == value;
}

//Tested
void convertToBinary(unsigned int userInput,vector<bool> &binary){
	if(userInput == 1 || userInput == 0){
		binary.push_back(userInput == 1);
		return;
	}
	convertToBinary(userInput/2,binary);
	binary.push_back(userInput%2==1);
}

//Tested
vector<unsigned int> generatePrimeNumber(unsigned int limit){
	vector<bool> flags;
	vector<unsigned int> primes;
	flags.assign(limit+2,true);
	for(unsigned int counter = 2;counter <= limit;counter++){
		if(flags[counter]){
			unsigned int innerCounter = 2;
			while(counter*innerCounter <= limit){
				flags[counter*innerCounter] = false;
				innerCounter+=1;
			}
		}
	}
	for(unsigned int counter = 2;counter <= limit;counter++){
		if(flags[counter]){
			primes.push_back(counter);
		}
	}
	return primes;
}

map<unsigned int,bool> generatePrimeNumberMap(unsigned int limit){
	vector<bool> flags;
	flags.assign(limit+2,true);
	map<unsigned int,bool> primeNumberMap;
	for(unsigned int counter = 2;counter <= limit;counter++){
		if(flags[counter]){
			unsigned int innerCounter = 2;
			while(counter*innerCounter <= limit){
				flags[counter*innerCounter] = false;
				innerCounter+=1;
			}
		}
	}
	for(unsigned int counter = 2;counter <= limit;counter++){
		if(flags[counter]){
			primeNumberMap.insert(pair<unsigned int,bool>(counter,true));
		}
	}
	return primeNumberMap;
}

map<unsigned int,bool> generatePrimeNumberMap(unsigned int start,unsigned int end){
	vector<bool> flags;
	flags.assign(end+2,true);
	map<unsigned int,bool> primeNumberMap;
	for(unsigned int counter = 2;counter <= end;counter++){
		if(flags[counter]){
			unsigned int innerCounter = 2;
			while(counter*innerCounter <= end){
				flags[counter*innerCounter] = false;
				innerCounter+=1;
			}
		}
	}
	for(unsigned int counter = start;counter <= end;counter++){
		if(flags[counter]){
			primeNumberMap.insert(pair<unsigned int,bool>(counter,true));
		}
	}
	return primeNumberMap;
}

double getTotientFuncValue(unsigned long long int userInput){
	map<unsigned long long int,unsigned long long int> primeFactorization = getPrimeFactorization(userInput);
	map<unsigned long long int,unsigned long long int>::iterator itToPrimeFactorization;
	double result = userInput;
	for(itToPrimeFactorization = primeFactorization.begin();itToPrimeFactorization != primeFactorization.end();itToPrimeFactorization++){
		result *= (double)(itToPrimeFactorization->first-1);
		result /= (double)itToPrimeFactorization->first;
	}
	return result;
}

#endif /* MATHUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
