/****************************************************************************************************************************************************
 *  File Name                   : dpc206.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/dpc206.h
 *  Created on                  : 13-Sep-2015 :: 12:30:29 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/DPC206
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

#ifndef DPC206_H_
#define DPC206_H_

//Tested
long long int reverse(long long int userInput){
	long long int result = 0;
	while(userInput){
		result = (result << 3) + (result << 1) +(userInput%10);
		userInput/=10;
	}
	return result;
}

//Tested
bool isPalindrome(long long int userInput){
	return reverse(userInput) == userInput;
}

//Tested
void producePalindrome(long long int userInput){
	unsigned int totalIterations = 0;
	while(!isPalindrome(userInput)){
		userInput = userInput + reverse(userInput);
		totalIterations++;
	}
	cout << totalIterations << " " << userInput << endl;
}

//Tested
void printResults(){
	unsigned int testCases;
	long long int userInput;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%lld",&userInput);
		producePalindrome(userInput);
	}
}

#endif /* DPC206_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
