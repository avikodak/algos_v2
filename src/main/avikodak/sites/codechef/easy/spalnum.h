/****************************************************************************************************************************************************
 *  File Name                   : spalnum.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/spalnum.h
 *  Created on                  : 30-Oct-2015 :: 7:10:09 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SPALNUM
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
#include <stdint.h>
#include <iomanip>
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

#ifndef SPALNUM_H_
#define SPALNUM_H_

//Tested
unsigned int reversedNumber(unsigned int userInput){
	unsigned int revResults = 0;
	while(userInput){
		revResults = (revResults << 3) + (revResults << 1) + (userInput%10);
		userInput /= 10;
	}
	return revResults;
}

//Tested
bool isPalindrome(unsigned int userInput){
	return userInput == reversedNumber(userInput);
}

//Tested
vector<unsigned int> generatePalindromeNumbers(unsigned int limit){
	vector<unsigned int> palindromeNumbers;
	for(unsigned int counter = 1;counter <= limit;counter++){
		if(isPalindrome(counter)){
			palindromeNumbers.push_back(counter);
		}
	}
	return palindromeNumbers;
}

//Tested
void printResults(){
	vector<unsigned int> palindromeNumbers = generatePalindromeNumbers(100000);
	vector<unsigned int>::iterator itToLPalindromeNumbers,itToUPalindromeNumbers;
	unsigned int testCases,lowerLimit,upperLimit,sum;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u %u",&lowerLimit,&upperLimit);
		itToLPalindromeNumbers = lower_bound(palindromeNumbers.begin(),palindromeNumbers.end(),lowerLimit);
		itToUPalindromeNumbers = upper_bound(palindromeNumbers.begin(),palindromeNumbers.end(),upperLimit);
		sum = 0;
		while(itToLPalindromeNumbers != palindromeNumbers.end() && itToLPalindromeNumbers != itToUPalindromeNumbers){
			sum += *itToLPalindromeNumbers;
			itToLPalindromeNumbers++;
		}
		printf("%u\n",sum);
	}
}

#endif /* SPALNUM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
