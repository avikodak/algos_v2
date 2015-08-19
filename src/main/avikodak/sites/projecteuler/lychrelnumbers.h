/****************************************************************************************************************************************************
 *  File Name                   : lychrelnumbers.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\lychrelnumbers.h
 *  Created on                  : Aug 20, 2015 :: 12:22:48 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=55
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

#ifndef LYCHRELNUMBERS_H_
#define LYCHRELNUMBERS_H_

//Tested
unsigned long long int reverseNumber(unsigned long long int userInput){
	unsigned long long int reverseValue = 0;
	while(userInput){
		reverseValue *= 10;
		reverseValue += (userInput%10);
		userInput /= 10;
	}
	return reverseValue;
}

//Tested
bool isPalindrome(unsigned long long int userInput){
	return reverseNumber(userInput) == userInput;
}

//Tested
unsigned long long int getIntermediateValue(unsigned long long int userInput){
	return userInput + reverseNumber(userInput);
}

//Tested
bool isLychrelNumber(unsigned long long int userInput){
	for(unsigned int counter = 0;counter < 50;counter++){
		userInput = userInput+reverseNumber(userInput);
		if(isPalindrome(userInput)){
			return false;
		}
	}
	return true;
}

//Tested
//Ans : 249
void getTotalLychrelNumber(){
	unsigned int total = 0;
	for(unsigned long long int counter = 10;counter < 10000;counter++){
		if(isLychrelNumber(counter)){
			total++;
		}
	}
	cout << total << endl;
}

#endif /* LYCHRELNUMBERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
