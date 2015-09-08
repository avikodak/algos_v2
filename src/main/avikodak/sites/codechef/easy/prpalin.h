/****************************************************************************************************************************************************
 *  File Name                   : prpalin.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\prpalin.h
 *  Created on                  : Aug 26, 2015 :: 10:35:41 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/PRPALIN/
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef PRPALIN_H_
#define PRPALIN_H_

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

unsigned int reverseNumber(unsigned int userInput){
	unsigned int value = 0;
	while(userInput){
		value = (value << 3) + (value << 1) + (userInput%10);
		userInput /= 10;
	}
	return value;
}

bool isPalindrome(unsigned int userInput){
	return userInput == reverseNumber(userInput);
}

vector<unsigned int> getPalindromes(vector<unsigned int> userInput){
	vector<unsigned int> primePalindromes;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(isPalindrome(userInput[counter])){
			primePalindromes.push_back(userInput[counter]);
		}
	}
	return primePalindromes;
}

void printResult(){
	vector<unsigned int> primesNumber = generatePrimeNumber(1003001);
	vector<unsigned int> primePalindromes = getPalindromes(primesNumber);
	unsigned int input;
	scanf("%u",&input);
	if(binary_search(primesNumber.begin(),primesNumber.end(),input)){
		printf("%u\n",input);
	}else{
		printf("%u\n",primePalindromes[upper_bound(primePalindromes.begin(),primePalindromes.end(),input) - primePalindromes.begin()]);
	}
}

//2,3,5,7,11, 101, 131, 151, 181, 191, 313, 353, 373, 383, 727, 757, 787, 797, 919, 929, 10301, 10501, 10601, 11311, 11411, 12421, 12721, 12821, 13331, 13831, 13931, 14341, 14741, 15451, 15551, 16061, 16361, 16561, 16661, 17471, 17971, 18181, 18481, 19391, 19891, 19991, 30103, 30203, 30403, 30703, 30803, 31013, 31513, 32323, 32423, 33533, 34543, 34843, 35053, 35153, 35353, 35753, 36263, 36563, 37273, 37573, 38083, 38183, 38783, 39293, 70207, 70507, 70607, 71317, 71917, 72227, 72727, 73037, 73237, 73637, 74047, 74747, 75557, 76367, 76667, 77377, 77477, 77977, 78487, 78787, 78887, 79397, 79697, 79997, 90709, 91019, 93139, 93239, 93739, 94049, 94349, 94649, 94849, 94949, 95959, 96269, 96469, 96769, 97379, 97579, 97879, 98389, 98689,1003001
//Tested
unsigned int reverseNumber(unsigned int userInput){
	unsigned int value = 0;
	while(userInput){
		value = (value << 3) + (value << 1) + (userInput%10);
		userInput /= 10;
	}
	return value;
}

//Tested
bool isPalindrome(unsigned int userInput){
	return userInput == reverseNumber(userInput);
}

//Tested
bool isNumberPrime(unsigned int userInput){
	if(userInput == 1){
		return false;
	}
	if(userInput == 2){
		return true;
	}
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
void printResult(){
	unsigned int input;
	scanf("%u",&input);
	for(unsigned int counter = input;;counter++){
		if(isNumberPrime(counter) && isPalindrome(counter)){
			printf("%u",counter);
			return;
		}
	}
}

#endif /* PRPALIN_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
