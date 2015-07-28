/****************************************************************************************************************************************************
 *  File Name                   : summationofprimes.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\summationofprimes.h
 *  Created on                  : Jul 28, 2015 :: 10:25:49 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=10
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

#ifndef SUMMATIONOFPRIMES_H_
#define SUMMATIONOFPRIMES_H_

//Tested
bool isNumberPrime(long long int userInput){
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
//Ans : 142913828922
void getSummationOfPrimes(){
	long long int sum = 2;
	for(long long int counter = 3;counter < 2000000;counter++){
		if(isNumberPrime(counter)){
			sum += counter;
		}
	}
	cout << sum << endl;
}

#endif /* SUMMATIONOFPRIMES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
