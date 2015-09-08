/****************************************************************************************************************************************************
 *  File Name                   : doublebasepalindromes.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\doublebasepalindromes.h
 *  Created on                  : Aug 13, 2015 :: 5:38:41 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=36
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

#ifndef DOUBLEBASEPALINDROMES_H_
#define DOUBLEBASEPALINDROMES_H_

//Tested
bool isPalindrome(unsigned int userInput){
	unsigned int revNumber = 0;
	while(userInput){
		revNumber *= 10;
		revNumber += (userInput%10);
		userInput /= 10;
	}
	return revNumber == userInput;
}

//Tested
bool isPalindrome(vector<bool> userInput){
	unsigned int frontCrawler =0,rearCrawler = userInput.size()-1;
	while(frontCrawler < rearCrawler){
		if(userInput[frontCrawler] != userInput[rearCrawler]){
			return false;
		}
		frontCrawler++;
		rearCrawler--;
	}
	return true;
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
vector<bool> convertToBinary(unsigned int userInput){
	vector<bool> binaryRep;
	convertToBinary(userInput,binaryRep);
}

//Tested
bool isPalindromeBinary(unsigned int userInput){
	vector<bool> binaryRep = convertToBinary(userInput);
	return isPalindrome(binaryRep);
}

//Tested
//Ans : 872187
void printSumOfDoubleBasePalindromes(){
	unsigned long long int sum = 0;
	for(unsigned int counter = 0;counter < 1000000;counter++){
		if(isPalindrome(counter) && isPalindromeBinary(counter)){
			sum += counter;
		}
	}
	cout << sum << endl;
}

#endif /* DOUBLEBASEPALINDROMES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
