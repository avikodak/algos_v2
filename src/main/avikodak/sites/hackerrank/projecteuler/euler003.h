/****************************************************************************************************************************************************
 *  File Name                   : euler003.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\projecteuler\euler003.h
 *  Created on                  : Jul 28, 2015 :: 8:41:05 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/contests/projecteuler/challenges/euler003
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

#ifndef EULER003_H_
#define EULER003_H_

//Tested
long long int max(long int firstInput,long long  int secondInput){
	return firstInput > secondInput?firstInput:secondInput;
}

//Tested
void printLargestPrimeFactor(){
	unsigned int testCases;
	scanf("%u",&testCases);
	long long int userInput;
	long long int squareRoot,largestDivisor;
	bool flag;
	while(testCases--){
		cin  >> userInput;
		squareRoot = sqrtl(userInput);
		largestDivisor = 0;
		flag = true;
		while(flag){
			flag = false;
			while(!(userInput&1)){
				largestDivisor = max(largestDivisor,2);
				flag = true;
				userInput /= 2;
			}
			for(long long int counter = 3;counter <= squareRoot;counter+=2){
				if(userInput%counter == 0){
					largestDivisor = max(counter,largestDivisor);
					flag = true;
					userInput /= counter;
					break;
				}
			}
			if(!flag){
				largestDivisor = max(largestDivisor,userInput);
			}
		}
		cout << largestDivisor << endl;
	}
}

#endif /* EULER003_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
