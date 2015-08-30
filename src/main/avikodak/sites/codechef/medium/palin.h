/****************************************************************************************************************************************************
 *  File Name                   : palin.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\medium\palin.h
 *  Created on                  : Aug 29, 2015 :: 8:47:56 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/PALIN
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

#ifndef PALIN_H_
#define PALIN_H_

bool reverseUInt(unsigned long long int userInput){
	unsigned int reverse = 0;
	while(userInput){
		reverse *= 10;
		reverse += userInput%10;
		userInput /= 10;
	}
	return reverse;
}

bool isPalindrome(unsigned long long int userInput){
	return reverseUInt(userInput) == userInput;
}

vector<unsigned long long int> getPalindromes(unsigned long long int limit = 1000000){
	vector<unsigned long long int> palindromes;
	for(unsigned int counter = 1;counter <= limit;counter++){
		if(isPalindrome(counter)){
			palindromes.push_back(counter);
		}
	}
	return palindromes;
}

void printResults(){
	vector<unsigned long long int> palindromes = getPalindromes(1111111);
	unsigned int testCases;
	scanf("%u",&testCases);
	unsigned long long int userInput;
	while(testCases--){
		cin >> userInput;
		cout << palindromes[upper_bound(palindromes.begin(),palindromes.end(),userInput) - palindromes.begin()] << endl;
	}
}

#endif /* PALIN_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
