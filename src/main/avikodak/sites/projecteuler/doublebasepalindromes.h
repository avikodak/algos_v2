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
